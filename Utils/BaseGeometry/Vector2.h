//
// Created by federico on 10/04/2020.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"
#ifndef CPP_GRAPHICS_VECTOR2_H
#define CPP_GRAPHICS_VECTOR2_H


#include "Vector3.h"
#include "Values.h"

class Vector2 : public Vector3{

public:

    struct Non2DException: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The vector does has z = 0";
        }
    };

    explicit Vector2(Vector3 v) : Vector3(std::move(v)) {
        if (std::abs(z()) > Values::eps)
            throw Non2DException();
    }

    Vector2(float x, float y) : Vector3(x, y, 0) {}

    Vector2() : Vector3() {};

};


#endif //CPP_GRAPHICS_VECTOR2_H

#pragma clang diagnostic pop