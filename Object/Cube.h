//
// Created by federico on 12/04/2020.
//

#ifndef CPP_GRAPHICS_CUBE_H
#define CPP_GRAPHICS_CUBE_H


#include "Object.h"
#include "../Surface/Square.h"

class Cube : public Object{

public:

    Cube(const ReferenceFrame &referenceFrame, Aspect aspect, float side) : Object(referenceFrame), side(side) {
        add(new Square(ReferenceFrame(TimeVector3(0, 0, side/2), Basis()), aspect, side));
        add(new Square(ReferenceFrame(TimeVector3(side/2, 0, 0), Basis().rotate(0, M_PI/2, 0, 0)), aspect, side));
        add(new Square(ReferenceFrame(TimeVector3(0, 0, -side/2), Basis().rotate(0, M_PI, 0, 0)), aspect, side));
        add(new Square(ReferenceFrame(TimeVector3(-side/2, 0, 0), Basis().rotate(0, -M_PI/2, 0, 0)), aspect, side));
        add(new Square(ReferenceFrame(TimeVector3(0, side/2, 0), Basis().rotate(-M_PI/2, 0, 0, 0)), aspect, side));
        add(new Square(ReferenceFrame(TimeVector3(0, -side/2, 0), Basis().rotate(M_PI/2, 0, 0, 0)), aspect, side));
    }

private:

    float side;

};


#endif //CPP_GRAPHICS_CUBE_H
