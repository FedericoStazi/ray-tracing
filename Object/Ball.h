//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_BALL_H
#define CPP_GRAPHICS_BALL_H


#include "Object.h"
#include "../Surface/Sphere.h"

class Ball : public Object{

public:

    Ball(const ReferenceFrame &referenceFrame, Aspect aspect, float radius) : Object(referenceFrame), radius(radius) {
        add(new Sphere(ReferenceFrame(), aspect, radius));
    }

private:

    float radius;

};


#endif //CPP_GRAPHICS_BALL_H
