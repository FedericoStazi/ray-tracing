//
// Created by federico on 12/04/2020.
//

#include "Square.h"

Square::Square(const ReferenceFrame &referenceFrame, const Aspect &aspect, float side) : Surface(referenceFrame,
                                                                                                  aspect), side(side) {
    add(Vector2(side/2, side/2));
    add(Vector2(-side/2, side/2));
    add(Vector2(-side/2, -side/2));
    add(Vector2(side/2, -side/2));

}
