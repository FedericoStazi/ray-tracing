//
// Created by federico on 02/06/2020.
//

#include <queue>
#include <iostream>
#include <mutex>
#include <thread>
#include "Renderer.h"
#include "../Utils/BaseGeometry/Vector2.h"

Picture Renderer::picture(int height, int width, float time) const {

    class RayRequest {
    public:
        Vector2 position; // bottom left corner, in [0,1) in the pixel
        int size = 0; // side has length 2^-size
        float variance = Constants::inf;
        Color color;
        RayRequest() = default;
        RayRequest(Vector2 position, int size, float variance, Color color) :
            position(std::move(position)), size(size), variance(variance), color(color) {}
        [[nodiscard]] float get_priority() const {
            return log2(variance+1) - 2*size;
        }
        bool operator<(const RayRequest& other) const {
            return other.get_priority() > get_priority();
        }
    };

    class PixelRenderer {
    public:

        int sub_squares=2; //2^i per side
        int x, y;
        std::priority_queue<RayRequest> requests;

        RayRequest active_request;

        explicit PixelRenderer(int x, int y) : x(x), y(y) {
            requests.push(RayRequest(Vector2(0,0), 0, Constants::inf, Color()));
        };

        [[nodiscard]] float get_priority() const {
            return requests.top().get_priority();
        }

        bool operator<(const PixelRenderer& other) const {
            return other.get_priority() > get_priority();
        }

        // When the request is chosen, get_request is called
        std::vector<Vector2> get_request () {

            active_request = requests.top();
            requests.pop();
            std::vector<Vector2> points;

            for (int i=0; i<(1<<sub_squares); i++)
                for (int j=0; j<(1<<sub_squares); j++)
                    points.push_back( static_cast<Vector2> (
                      active_request.position + (
                          Vector2(i,j) *
                              pow(0.5,sub_squares+active_request.size))));

            return points;
        }

        // When the request is completed, complete_request is called
        // The elements in colors have the same order
        void complete_request (std::vector<Color> colors) {

            Color mean;
            for (Color c:colors)
                mean = mean.add(c);
            mean = mean.scale(1.0/(colors.size()));

            for (int i=0; i<(1<<sub_squares); i++)
                for (int j=0; j<(1<<sub_squares); j++) {
                    Color c = colors[i * (1<<sub_squares) + j];
                    float variance =
                        (c.get_r() - mean.get_r()) * (c.get_r() - mean.get_r()) +
                        (c.get_g() - mean.get_g()) * (c.get_g() - mean.get_g()) +
                        (c.get_b() - mean.get_b()) * (c.get_b() - mean.get_b());
                    RayRequest new_request(
                        static_cast<Vector2> (active_request.position + (
                            Vector2(i,j) * (pow(0.5,sub_squares+active_request.size)))),
                        active_request.size + sub_squares, variance, c);
                    requests.push(new_request);
                }
        }

        //called at the end, can do anything with requests queue
        Color get_color() {
            //return Color((float)requests.size()/10, (float)requests.size()/100, (float)requests.size()/1000);
            Color result;
            while (!requests.empty()) {
                RayRequest req = requests.top();
                requests.pop();
                result = result.add(req.color.scale(pow(0.5, 2*req.size)));
            }
            return result;
        }

    };

    int max_requests = 10 * height * width;
    std::priority_queue<PixelRenderer> queue;
    int threads_number = 4;

    for (int i=0; i<height; i++)
        for (int j=0; j<height; j++)
            queue.push(PixelRenderer(i, j));

    std::mutex max_requests_mutex;
    std::mutex queue_mutex;

    [[maybe_unused]] auto complete_requests =[&](){

        int local_max_requests = 1;

        while (local_max_requests > 0) {

            queue_mutex.lock();
            PixelRenderer pixel = queue.top();
            queue.pop();
            queue_mutex.unlock();

            std::vector<Vector2> requests = pixel.get_request();
            std::vector<Color> colors;

            colors.reserve(requests.size());
            for (const Vector2& point:requests) {
                Vector2 screen_point = static_cast<Vector2> (
                    Vector2((float)pixel.x/width, (float)pixel.y/height)
                    + (Vector2(point.x() /width, point.y()/height)));
                colors.push_back(camera.cast_ray(screen_point, 0));
            }

            pixel.complete_request(colors);

            queue_mutex.lock();
            queue.push(pixel);
            queue_mutex.unlock();

            max_requests_mutex.lock();
            local_max_requests = --max_requests;
            max_requests_mutex.unlock();

            if (local_max_requests%1000 == 0)
                std::cerr << max_requests/1000 << "    \r";

        }
    };

    std::vector<std::thread> threads;
    for (int t=0; t<threads_number; t++)
        threads.emplace_back(complete_requests);
    std::for_each(threads.begin(), threads.end(), [](std::thread& t){t.join();});

    /*while (max_requests--) {

        if (max_requests%1000 == 0)
            std::cerr << max_requests << "\r";

        PixelRenderer pixel = queue.top();
        queue.pop();
        std::vector<Vector2> requests = pixel.get_request();
        std::vector<Color> colors;

        colors.reserve(requests.size());
        for (const Vector2& point:requests) {
            Vector2 screen_point = static_cast<Vector2> (
                Vector2((float)pixel.x/width, (float)pixel.y/height)
                    + (Vector2(point.x() /width, point.y()/height)));
            colors.push_back(camera.cast_ray(screen_point, 0));
        }

        pixel.complete_request(colors);
        queue.push(pixel);
    }*/

    Picture result(height, width);

    while(!queue.empty()) {
        PixelRenderer pixel = queue.top();
        queue.pop();
        result.set_pixel(height - pixel.y - 1, pixel.x, RGB::to_rgb(pixel.get_color()));
    }

    return result;

}