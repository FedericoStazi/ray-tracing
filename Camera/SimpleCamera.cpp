//
// Created by federico on 11/04/2020.
//

#include "SimpleCamera.h"
#include "../Aspect/Color.h"

SimpleCamera::SimpleCamera(const ReferenceFrame &referenceFrame, const Scene &scene) : Camera(referenceFrame, scene) {}

std::string SimpleCamera::picture(int height, int width, double time) {

    std::vector<std::vector<int>> img;

    for (int j = height - 1; j >= 0; j--) {
        std::vector<int> row;
        for (int i = 0; i < width; i++) {

            double x = aperture * ( ( (double) i / (width-1) ) - 0.5 );
            double y = aperture * ( ( (double) j / (height-1) ) - 0.5 );

            Vector3 focal_point = get_reference_frame().get_location(time).add(get_direction(time).scale(-lens_distance));

            Color c = get_scene().cast_ray(Line(
                    TimeVector3(focal_point),
                    TimeUnitVector3(UnitVector3(get_reference_frame().from_plane(Vector2(x, y), time).subtract(focal_point).normalized()))
            ), time);

            row.push_back(c.get_r());
            row.push_back(c.get_g());
            row.push_back(c.get_b());
        }
        img.push_back(row);
    }

    std::string result;

    result = "P3\n"+std::to_string(img.size())+" "+std::to_string(img[0].size()/3)+"\n255\n";

    for (const std::vector<int>& v:img) {
        for (int x:v)
            result += std::to_string(x) + " ";
        result += "\n";
    }

    return result;

}

