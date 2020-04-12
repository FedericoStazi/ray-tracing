//
// Created by federico on 11/04/2020.
//

#include "Ball.h"
#include "../Surface/Sphere.h"

Ball::Ball(const ReferenceFrame &referenceFrame, Aspect aspect, double radius) : Object(referenceFrame), radius(radius) {
    add(new Sphere(ReferenceFrame(), aspect, radius));
}
