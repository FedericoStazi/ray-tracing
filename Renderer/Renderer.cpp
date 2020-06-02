//
// Created by federico on 02/06/2020.
//

#include <queue>
#include <iostream>
#include "Renderer.h"
#include "../Utils/BaseGeometry/Vector2.h"

Picture Renderer::picture(int height, int width, double time) const {

    class RayRequest {
    public:
        Vector2 position; // bottom left corner, in [0,1) in the pixel
        int size = 0; // side has length 2^-size
        double variance = Constants::inf;
        Color color;
        RayRequest() = default;
        RayRequest(Vector2 position, int size, double variance, Color color) :
            position(std::move(position)), size(size), variance(variance), color(color) {}
        [[nodiscard]] double get_priority() const {
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

        [[nodiscard]] double get_priority() const {
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
                    points.push_back( (Vector2)
                      active_request.position.add(
                          Vector2(i,j).scale(
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
                    double variance =
                        (c.get_r() - mean.get_r()) * (c.get_r() - mean.get_r()) +
                        (c.get_g() - mean.get_g()) * (c.get_g() - mean.get_g()) +
                        (c.get_b() - mean.get_b()) * (c.get_b() - mean.get_b());
                    RayRequest new_request(
                        (Vector2)active_request.position.add(
                            Vector2(i,j).scale(pow(0.5,sub_squares+active_request.size))),
                        active_request.size + sub_squares, variance, c);
                    requests.push(new_request);
                }
        }

        //called at the end, can do anything with requests queue
        Color get_color() {
            Color result;
            while (!requests.empty()) {
                RayRequest req = requests.top();
                requests.pop();
                result = result.add(req.color.scale(pow(0.5, 2*req.size)));
            }
            return result;
        }

    };

    int max_requests = 25 * height * width;

    std::priority_queue<PixelRenderer> queue;
    for (int i=0; i<height; i++)
        for (int j=0; j<height; j++)
            queue.push(PixelRenderer(i, j));

    while (max_requests--) {

        if (max_requests%10000 == 0)
            std::cerr << max_requests << "\r";

        PixelRenderer pixel = queue.top();
        queue.pop();
        std::vector<Vector2> requests = pixel.get_request();
        std::vector<Color> colors;

        colors.reserve(requests.size());
        for (const Vector2& point:requests) {
            Vector2 screen_point = (Vector2)
                Vector2((double)pixel.x/width, (double)pixel.y/height)
                    .add(Vector2(point.x() /width, point.y()/height));
            colors.push_back(camera.cast_ray(screen_point, 0));
        }

        pixel.complete_request(colors);
        queue.push(pixel);
    }

    Picture result(height, width);

    while(!queue.empty()) {
        PixelRenderer pixel = queue.top();
        queue.pop();
        result.set_pixel(height - pixel.y - 1, pixel.x, RGB::to_rgb(pixel.get_color()));
    }

    return result;

}