//
// Created by federico on 11/04/2020.
//

#include "Object2D.h"

Object2D::Object2D(const ReferenceFrame &referenceFrame, Surface * surface) : Object(referenceFrame) {
    add(surface);
}
