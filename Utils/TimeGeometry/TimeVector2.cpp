//
// Created by federico on 09/04/2020.
//

#include "TimeVector2.h"

#include <utility>

TimeVector2::TimeVector2(TimeVector3 v) : TimeVector3(std::move(v)) {}

TimeVector2::TimeVector2(TimeFunction x, TimeFunction y) : TimeVector3(std::move(x), std::move(y), TimeFunction(0)) {}

TimeVector2::TimeVector2(double x, double y) : TimeVector3(x, y, 0) {}

TimeVector2::TimeVector2(const Vector2& v) : TimeVector2(v.x(), v.y()) {}

TimeVector2::TimeVector2() : TimeVector2(0, 0) {}

Vector2 TimeVector2::time(double time) const {
    return Vector2(fx.get(time), fy.get(time));
}
