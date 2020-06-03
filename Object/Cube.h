//
// Created by federico on 12/04/2020.
//

#ifndef CPP_GRAPHICS_CUBE_H
#define CPP_GRAPHICS_CUBE_H


#include "Object.h"

class Cube : public Object{

private:

    float side;

public:

    Cube(const ReferenceFrame &referenceFrame, Aspect aspect, float side);

};


#endif //CPP_GRAPHICS_CUBE_H
