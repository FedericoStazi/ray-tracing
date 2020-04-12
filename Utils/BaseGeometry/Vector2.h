//
// Created by federico on 10/04/2020.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"
#ifndef CPP_GRAPHICS_VECTOR2_H
#define CPP_GRAPHICS_VECTOR2_H


#include "Vector3.h"

class Vector2 : public Vector3{

public:

    struct Non2DException: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The vector does not have z = 0";
        }
    };

    explicit Vector2(Vector3 v);
    Vector2(double x, double y);
    Vector2();

};


#endif //CPP_GRAPHICS_VECTOR2_H

#pragma clang diagnostic pop