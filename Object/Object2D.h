//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_OBJECT2D_H
#define CPP_GRAPHICS_OBJECT2D_H


#include "Object.h"

///Generic object containing a single surface
class Object2D : public Object {

public:

    Object2D(const ReferenceFrame &referenceFrame, Surface * surface) : Object(referenceFrame) {
        add(surface);
    }

};


#endif //CPP_GRAPHICS_OBJECT2D_H
