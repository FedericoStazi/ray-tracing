//
// Created by federico on 12/04/2020.
//

#ifndef CPP_GRAPHICS_SQUARE_H
#define CPP_GRAPHICS_SQUARE_H


#include "Surface.h"

class Square : public Surface {

public:

    Square(const ReferenceFrame &referenceFrame, const Aspect &aspect, float side)
        : Surface(referenceFrame,aspect),
          side(side) {
            add(Vector2(side/2, side/2));
            add(Vector2(-side/2, side/2));
            add(Vector2(-side/2, -side/2));
            add(Vector2(side/2, -side/2));
    }

private:

    float side;
};


#endif //CPP_GRAPHICS_SQUARE_H
