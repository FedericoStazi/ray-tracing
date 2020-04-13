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

            double x = aperture * ( ( (double) i / (width-1) ) - 0.5 );
            double y = aperture * ( ( (double) j / (height-1) ) - 0.5 );

            Vector3 focal_point = get_reference_frame().get_location(time).add(get_direction(time).scale(-lens_distance));

            Color c = get_scene().cast_ray(Line(
                    TimeVector3(focal_point),
                    TimeUnitVector3(UnitVector3(get_reference_frame().from_plane(Vector2(x, y), time).subtract(focal_point).normalized()))
            ), _reflections, time);

            result += RGB::to_rgb(c).to_string();

        }

        result += "\n";
    }


    return "P3\n"+std::to_string(height)+" "+std::to_string(width)+"\n255\n" + result;

}

