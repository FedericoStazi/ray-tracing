//
// Created by federico on 12/04/2020.
//

#ifndef CPP_GRAPHICS_CUBE_H
#define CPP_GRAPHICS_CUBE_H


#include "Object.h"

class Cube : public Object{

private:

    double side;

public:

    Cube(const ReferenceFrame &referenceFrame, Aspect aspect, double side);

};


#endif //CPP_GRAPHICS_CUBE_H
