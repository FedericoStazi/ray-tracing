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
    float sensor_size = 0.2;
    float lens_distance = 0.5;

public:

    SimpleCamera(const ReferenceFrame &referenceFrame, const Scene &scene);
    Picture picture(int height, int width, float time) override;

};


#endif //CPP_GRAPHICS_SIMPLECAMERA_H
