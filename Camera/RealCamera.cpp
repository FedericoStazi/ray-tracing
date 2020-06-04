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

//TODO make separate class
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
