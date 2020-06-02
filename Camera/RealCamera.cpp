//
// Created by federico on 13/04/2020.
//

#include <iostream>
#include <random>
#include <utility>
#include <queue>
#include <assert.h>
#include "RealCamera.h"
#include "../Aspect/RGB.h"
#include "../Picture.h"

RealCamera::RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene) : Camera(referenceFrame, scene),
                                                                                renderer(Renderer(*this)) {}

RealCamera::RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene, double sensor_size, double focal_length,
                       double lens_distance, double aperture_size, double aperture_distance) : Camera(referenceFrame, scene),
                                                                                            sensor_size(sensor_size),
                                                                                            focal_length(focal_length),
                                                                                            lens_distance(lens_distance),
                                                                                            aperture_size(aperture_size),
                                                                                            aperture_distance(aperture_distance),
                                                                                            renderer(Renderer(*this)) {}

RealCamera::RealCamera(const Vector3 &position, const Vector3 &point, Scene scene) : Camera(position, point, std::move(scene)),
                                                                                    renderer(Renderer(*this)) {}

void RealCamera::set_sensor_size(double _sensor_size) {
    sensor_size = _sensor_size;
}

void RealCamera::set_focal_length(double _focal_length) {
    focal_length = _focal_length;
}

void RealCamera::set_lens_distance(double _lens_distance) {
    lens_distance = _lens_distance;
}

void RealCamera::set_aperture_size(double _aperture_size) {
    aperture_distance = _aperture_size;
}

void RealCamera::set_aperture_distance(double _aperture_distance) {
    aperture_distance = _aperture_distance;
}

void RealCamera::set_shutter_speed(double _shutter_speed) {
    shutter_speed = _shutter_speed;
}

double RealCamera::get_focal_plane_distance() const {
    return (lens_distance * focal_length / (lens_distance - focal_length) ) - aperture_distance;
}

double RealCamera::get_focal_plane_size() const {
    return get_focal_plane_distance() * sensor_size / lens_distance;
}

Picture RealCamera::picture(int height, int width, double time) {
    return renderer.picture(height, width, time);
}


Picture RealCamera::picture_old(int height, int width, double time) {

    bool heatmap = false;
    Picture result(height, width);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            auto [color1, var] = cast_n_rays(height, width, j, i, time, _first_samples);

            Color color;

            if (heatmap) {
                double v = (double) additional_samples(var) / 500;
                color = Color(v, v, v);
            } else {
                auto [color2, _] = cast_n_rays(height, width, j, i, time, additional_samples(var));
                color = color1.add(color2);
                color = color.scale(1.0/(_first_samples + additional_samples(var)));
            }

            result.set_pixel(j, i, RGB::to_rgb(color));

            /// print status
            std::cout<<j<<"/"<<height<<"\r";

        }
    }

    return result;

}

//TODO make a separate one for each algorithm
std::pair<Color, double> RealCamera::cast_n_rays(int height, int width, int j, int i, double time, int n) {

    std::vector<Color> samples;
    Color result;

    std::random_device rd;
    std::minstd_rand gen(rd());

    std::uniform_real_distribution<> dis(-0.5, 0.5);
    std::uniform_real_distribution<> time_dis(0, shutter_speed);

    for (int s=0; s < n; s++) {

        double ray_time = time + time_dis(gen);

        double x = 0.5 - (width - i - 1 + dis(gen)) / (width - 1);
        double y = 0.5 - (j + dis(gen)) / (height - 1);

        Vector3 focal_point = get_reference_frame().from_plane(
                Vector2(aperture_size * dis(gen), aperture_size * dis(gen)), ray_time)
            .add(get_direction(ray_time).scale(aperture_distance));

        Color ray_color = get_scene().cast_ray(
            Line::between_points(
                focal_point,
                get_reference_frame().from_plane(Vector2(get_focal_plane_size() * x, get_focal_plane_size() * y), ray_time)
                    .add(get_direction(ray_time).scale(get_focal_plane_distance()))),
            _reflections + 1,
            ray_time);

        result = result.add(ray_color);
        samples.push_back(ray_color);

    }

    Color mean = result.scale(1.0/n);
    double var = 0;

    for (auto s:samples) {
        Color diff = s.add(mean.scale(-1));
        var += pow(diff.get_r(), 2) + pow(diff.get_g(), 2) + pow(diff.get_b(), 2);
    }

    return {result, var};

}

//TODO make separate class
//check if randomness on pixel position is needed
Color RealCamera::cast_ray(Vector2 position, double time) {

    std::random_device rd;
    std::minstd_rand gen(rd());

    std::uniform_real_distribution<> dis(-0.5, 0.5);
    std::uniform_real_distribution<> time_dis(0, shutter_speed);

    double x = position.x()-0.5;
    double y = position.y()-0.5;

    double ray_time = time + time_dis(gen);

    Vector3 focal_point = get_reference_frame().from_plane(
            Vector2(aperture_size * dis(gen), aperture_size * dis(gen)), ray_time)
        .add(get_direction(ray_time).scale(aperture_distance));

    Color ray_color = get_scene().cast_ray(
        Line::between_points(
            focal_point,
            get_reference_frame().from_plane(Vector2(get_focal_plane_size() * x, get_focal_plane_size() * y), ray_time)
                .add(get_direction(ray_time).scale(get_focal_plane_distance()))),
        _reflections + 1, time);

    return ray_color;

}
