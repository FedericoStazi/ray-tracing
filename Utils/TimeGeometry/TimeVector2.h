//
// Created by federico on 09/04/2020.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"
#ifndef CPP_GRAPHICS_TIMEVECTOR2_H
#define CPP_GRAPHICS_TIMEVECTOR2_H


#include "TimeVector3.h"
#include "../BaseGeometry/Vector2.h"

class TimeVector2 : public TimeVector3 {

public:

    Vector2 time(float time) const {
        return static_cast<Vector2>(TimeVector3::time(time));
    }

    // non time depending constructors

    explicit TimeVector2(const Vector3& v) : TimeVector2(Vector2(v)) {}

    TimeVector2(float x, float y) : TimeVector3(x, y, 0) {}

    TimeVector2() : TimeVector2(0, 0) {}

    // time depending constructors

    explicit TimeVector2(TimeVector3 v) : TimeVector3(std::move(v)) {}

    TimeVector2(TimeFunction x, TimeFunction y) : TimeVector3(x, y, TimeFunction(0.0f)) {}

    explicit TimeVector2(const Vector2& v) : TimeVector2(v.x(), v.y()) {}

};


#endif //CPP_GRAPHICS_TIMEVECTOR2_H

#pragma clang diagnostic pop