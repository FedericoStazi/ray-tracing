//
// Created by federico on 13/04/2020.
//

#include <iostream>
#include <random>
#include <utility>
#include "RealCamera.h"
#include "../Aspect/RGB.h"

RealCamera::RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene) : Camera(referenceFrame, scene) {}

RealCamera::RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene, double sensor_size, double focal_length,
                       double lens_distance, double aperture_size, double aperture_distance) : Camera(referenceFrame, scene),
                                                                                            sensor_size(sensor_size),
                                                                                            focal_length(focal_length),
                                                                                            lens_distance(lens_distance),
                                                                                            aperture_size(aperture_size),
                                                                                            aperture_distance(aperture_distance) {}

RealCamera::RealCamera(const Vector3 &position, const Vector3 &point, Scene scene) : Camera(position, point, std::move(scene)) {}

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
    return get_focal_plane_distance() * sensor_size / lens_distance;;
}

std::string RealCamera::picture(int height, int width, double time) {

    double focal_plane_size = get_focal_plane_size();
    double focal_plane_distance = get_focal_plane_distance();

    std::random_device rd;
    std::minstd_rand gen(rd());

    std::uniform_real_distribution<> dis(-0.5, 0.5);
    std::uniform_real_distribution<> time_dis(0, shutter_speed);

    std::string result;

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            double ray_time = time + time_dis(gen);

            Color c;

            for (int s=0; s < _samples; s++) {

                double x = 0.5 - (width - i - 1 + dis(gen)) / (width-1);
                double y = 0.5 - (j + dis(gen)) / (height-1);

                Vector3 focal_point = get_reference_frame().from_plane(
                        Vector2(aperture_size * dis(gen), aperture_size * dis(gen)), ray_time)
                                .add(get_direction(ray_time).scale(aperture_distance));

                c = c.add(get_scene().cast_ray(
                        Line::between_points(
                                focal_point,
                                get_reference_frame().from_plane(Vector2(focal_plane_size * x, focal_plane_size * y), ray_time)
                                        .add(get_direction(ray_time).scale(focal_plane_distance))),
                        _reflections + 1,
                        ray_time));

            }

            c = c.scale(1.0/_samples);
            result += RGB::to_rgb(c).to_string();

            std::cout<<j<<"/"<<height<<"\r";

        }

        result += "\n";
    }


    return "P3\n"+std::to_string(height)+" "+std::to_string(width)+"\n255\n" + result;

}
