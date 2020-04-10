//
// Created by federico on 10/04/2020.
//

#include "Vector2.h"
#include "../TimeGeometry/TimeVector3.h"

Vector2::Vector2(Vector3 v) : Vector3(std::move(v)) {
    if (std::abs(z()) > TimeVector3::eps)
        throw Non2DException();
}

Vector2::Vector2(double x, double y) : Vector3(x, y, 0) {}

Vector2::Vector2() : Vector3() {}