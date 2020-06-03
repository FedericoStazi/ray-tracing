//
// Created by federico on 09/04/2020.
//

#include "TimeVector3.h"

#include <utility>

TimeVector3::TimeVector3(TimeFunction x, TimeFunction y, TimeFunction z) : fx(std::move(x)), fy(std::move(y)), fz(std::move(z)), _is_function(true) {}

Vector3 TimeVector3::time(float time) const {
    if (!_is_function)
        return *this;
    else
        return Vector3(fx.get(time), fy.get(time), fz.get(time));
}
