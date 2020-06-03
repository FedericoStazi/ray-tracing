//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_BALL_H
#define CPP_GRAPHICS_BALL_H


#include "Object.h"

class Ball : public Object{

private:

    float radius;

public:

    Ball(const ReferenceFrame &referenceFrame, Aspect aspect, float radius);

};


#endif //CPP_GRAPHICS_BALL_H
