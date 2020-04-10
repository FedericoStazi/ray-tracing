//
// Created by federico on 09/04/2020.
//

#include "TimeVector3.h"

#include <utility>

TimeVector3::TimeVector3(TimeFunction x, TimeFunction y, TimeFunction z) : fx(std::move(x)), fy(std::move(y)), fz(std::move(z)) {}

TimeVector3::TimeVector3(double x, double y, double z) : fx(x), fy(y), fz(z) {}

TimeVector3::TimeVector3(const Vector3& v) : TimeVector3(v.x(), v.y(), v.z()) {}

TimeVector3::TimeVector3() : TimeVector3(0, 0, 0) {}

Vector3 TimeVector3::time(double time) const {
    return Vector3(fx.get(time), fy.get(time), fz.get(time));
}
