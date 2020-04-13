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

    explicit TimeVector2(const Vector3& v);
    explicit TimeVector2(TimeVector3 v);
    TimeVector2(TimeFunction x, TimeFunction y);
    TimeVector2(double x, double y);
    explicit TimeVector2(const Vector2& v);
    TimeVector2();

    [[nodiscard]] Vector2 time(double time) const;

};


#endif //CPP_GRAPHICS_TIMEVECTOR2_H

#pragma clang diagnostic pop