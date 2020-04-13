//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_SIMPLECAMERA_H
#define CPP_GRAPHICS_SIMPLECAMERA_H

#include "Camera.h"

// simple camera class used for testing
class SimpleCamera : public Camera {

private:

    int _reflections = 1;
    double aperture = 0.2;
    double lens_distance = 0.5;

public:

    SimpleCamera(const ReferenceFrame &referenceFrame, const Scene &scene);
    std::string picture(int height, int width, double time) override;

};


#endif //CPP_GRAPHICS_SIMPLECAMERA_H
