//
// Created by federico on 03/06/2020.
//

#include "Cylinder.h"
#include "../Surface/OpenCylinder.h"
#include "../Surface/Circle.h"

Cylinder::Cylinder(const ReferenceFrame &referenceFrame, Aspect aspect, float radius, float height) : Object(referenceFrame) {
    add(new OpenCylinder(ReferenceFrame(), aspect, radius, height));
    add(new Circle(ReferenceFrame(TimeVector3(0,0,-height/2), Basis()), aspect, radius));
    add(new Circle(ReferenceFrame(TimeVector3(0,0,height/2), Basis()), aspect, radius));
}