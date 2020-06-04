//
// Created by federico on 03/06/2020.
//

#ifndef CPP_GRAPHICS_CYLINDER_H
#define CPP_GRAPHICS_CYLINDER_H


#include "Object.h"

class Cylinder : public Object {

public:
    Cylinder(const ReferenceFrame &referenceFrame, Aspect aspect, float radius, float height);

};


#endif //CPP_GRAPHICS_CYLINDER_H
