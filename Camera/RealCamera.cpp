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

RealCamera::RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene, float sensor_size, float focal_length,
                       float lens_distance, float aperture_size, float aperture_distance) : Camera(referenceFrame, scene),
                                                                                            sensor_size(sensor_size),
                                                                                            focal_length(focal_length),
                                                                                            lens_distance(lens_distance),
                                                                                            aperture_size(aperture_size),
                                                                                            aperture_distance(aperture_distance),
                                                                                            renderer(Renderer(*this)) {}

RealCamera::RealCamera(const Vector3 &position, const Vector3 &point, Scene scene) : Camera(position, point, std::move(scene)),
                                                                                    renderer(Renderer(*this)) {}

void RealCamera::set_sensor_size(float _sensor_size) {
    sensor_size = _sensor_size;
}

void RealCamera::set_focal_length(float _focal_length) {
    focal_length = _focal_length;
}

void RealCamera::set_lens_distance(float _lens_distance) {
    lens_distance = _lens_distance;
}

void RealCamera::set_aperture_size(float _aperture_size) {
    aperture_distance = _aperture_size;
}

void RealCamera::set_aperture_distance(float _aperture_distance) {
    aperture_distance = _aperture_distance;
}

void RealCamera::set_shutter_speed(float _shutter_speed) {
    shutter_speed = _shutter_speed;
}

float RealCamera::get_focal_plane_distance() const {
    return (lens_distance * focal_length / (lens_distance - focal_length) ) - aperture_distance;
}

float RealCamera::get_focal_plane_size() const {
    return get_focal_plane_distance() * sensor_size / lens_distance;
}

Picture RealCamera::picture(int height, int width, float time) {
    return renderer.picture(height, width, time);
}

//TODO make separate class
//check if randomness on pixel position is needed
Color RealCamera::cast_ray(Vector2 position, float time) const {

    std::random_device rd;
    std::minstd_rand gen(rd());

    std::uniform_real_distribution<> dis(-0.5, 0.5);
    std::uniform_real_distribution<> time_dis(0, shutter_speed);

    float x = position.x()-0.5;
    float y = position.y()-0.5;

    float ray_time = time + time_dis(gen);

    Vector3 focal_point = get_reference_frame().from_plane(
            Vector2(aperture_size * dis(gen), aperture_size * dis(gen)), ray_time)
            + ((get_direction(ray_time) * (aperture_distance)));

    Color ray_color = get_scene().cast_ray(
        Line::between_points(
            focal_point,
            get_reference_frame().from_plane(Vector2(get_focal_plane_size() * x, get_focal_plane_size() * y), ray_time)
                + ((get_direction(ray_time) * (get_focal_plane_distance())))),
        _reflections + 1, time);

    return ray_color;

}
