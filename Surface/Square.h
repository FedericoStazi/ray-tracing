//
// Created by federico on 12/04/2020.
//

#ifndef CPP_GRAPHICS_SQUARE_H
#define CPP_GRAPHICS_SQUARE_H


#include "Surface.h"

class Square : public Surface {

private:

    float side;

public:

    Square(const ReferenceFrame &referenceFrame, const Aspect &aspect, float side);

};


#endif //CPP_GRAPHICS_SQUARE_H
