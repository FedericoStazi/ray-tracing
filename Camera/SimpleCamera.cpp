//
// Created by federico on 11/04/2020.
//

#include "SimpleCamera.h"
#include "../Aspect/Color.h"
#include "../Aspect/RGB.h"

SimpleCamera::SimpleCamera(const ReferenceFrame &referenceFrame, const Scene &scene) : Camera(referenceFrame, scene) {}

Picture SimpleCamera::picture(int height, int width, float time) {

    Picture result(height, width);

    for (int j = height - 1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {

            float x = sensor_size * (((float) i / (width - 1) ) - 0.5 );
            float y = sensor_size * (((float) j / (height - 1) ) - 0.5 );

            Vector3 focal_point = (get_reference_frame().get_location(time) + (get_direction(time)) * (-lens_distance));

            Color c = get_scene().cast_ray(
                    Line::between_points(focal_point, get_reference_frame().from_plane(Vector2(x, y), time)),
                    _reflections + 1,
                    time);

            result.set_pixel(j, i, RGB::to_rgb(c));

        }

    }

    return result;

}

