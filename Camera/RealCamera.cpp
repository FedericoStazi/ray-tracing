//
// Created by federico on 13/04/2020.
//

#include <iostream>
#include <random>
#include "RealCamera.h"
#include "../Aspect/RGB.h"

RealCamera::RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene) : Camera(referenceFrame, scene) {}

std::string RealCamera::picture(int height, int width, double time) {

    std::random_device rd;
    std::minstd_rand gen(rd());
    std::uniform_real_distribution<> dis(-0.5, 0.5);

    std::string result;

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            Color c;

            for (int s=0; s < _samples; s++) {

                double x = 0.5 - (width - i - 1 + dis(gen)) / (width-1);
                double y = 0.5 - (j + dis(gen)) / (height-1);

                Vector3 focal_point = get_reference_frame().from_plane(
                        Vector2(aperture * dis(gen), aperture * dis(gen)), time);

                c = c.add(get_scene().cast_ray(
                        Line::between_points(
                                focal_point,
                                get_reference_frame().from_plane(Vector2(focal_plane_size * x, focal_plane_size * y), time)
                                .add(get_direction(time).scale(focal_plane_distance))),
                        _reflections + 1,
                        time));

            }

            c = c.scale(1.0/_samples);
            result += RGB::to_rgb(c).to_string();

            std::cout<<j<<"/"<<height<<"\r";

        }

        result += "\n";
    }


    return "P3\n"+std::to_string(height)+" "+std::to_string(width)+"\n255\n" + result;

}