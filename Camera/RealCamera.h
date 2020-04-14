//
// Created by federico on 13/04/2020.
//

#ifndef CPP_GRAPHICS_REALCAMERA_H
#define CPP_GRAPHICS_REALCAMERA_H


#include <string>
#include "Camera.h"

class RealCamera : Camera {

private:

    int _reflections = 1;
    int _samples = 256;

    double focal_plane_size = 50;
    double aperture = 10;
    double focal_plane_distance = 200;

public:

    RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene);
    std::string picture(int height, int width, double time) override;


};


#endif //CPP_GRAPHICS_REALCAMERA_H
