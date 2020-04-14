//
// Created by federico on 11/04/2020.
//

#include "SimpleCamera.h"
#include "../Aspect/Color.h"
#include "../Aspect/RGB.h"

SimpleCamera::SimpleCamera(const ReferenceFrame &referenceFrame, const Scene &scene) : Camera(referenceFrame, scene) {}

std::string SimpleCamera::picture(int height, int width, double time) {

    std::string result;

    for (int j = height - 1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {

            double x = sensor_size * (((double) i / (width - 1) ) - 0.5 );
            double y = sensor_size * (((double) j / (height - 1) ) - 0.5 );

            Vector3 focal_point = get_reference_frame().get_location(time).add(get_direction(time).scale(-lens_distance));

            Color c = get_scene().cast_ray(
                    Line::between_points(focal_point, get_reference_frame().from_plane(Vector2(x, y), time)),
                    _reflections + 1,
                    time);

            result += RGB::to_rgb(c).to_string();

        }

        result += "\n";
    }


    return "P3\n"+std::to_string(height)+" "+std::to_string(width)+"\n255\n" + result;

}

