//
// Created by federico on 03/06/2020.
//

#ifndef CPP_GRAPHICS_CYLINDER_H
#define CPP_GRAPHICS_CYLINDER_H


#include "Object.h"
#include "../Surface/Circle.h"
#include "../Surface/OpenCylinder.h"

class Cylinder : public Object {

public:
    Cylinder(const ReferenceFrame &referenceFrame, Aspect aspect, float radius, float height) : Object(referenceFrame) {
        add(new OpenCylinder(ReferenceFrame(), aspect, radius, height));
        add(new Circle(ReferenceFrame(TimeVector3(0,0,-height/2), Basis()), aspect, radius));
        add(new Circle(ReferenceFrame(TimeVector3(0,0,height/2), Basis()), aspect, radius));
    }

};


#endif //CPP_GRAPHICS_CYLINDER_H
