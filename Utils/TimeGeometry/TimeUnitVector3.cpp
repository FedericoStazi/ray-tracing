//
// Created by federico on 09/04/2020.
//

#include "TimeUnitVector3.h"
#include "../Geometry/Vector3.h"

TimeUnitVector3::TimeUnitVector3(TimeVector3 v) : TimeVector3(std::move(v)) {}

TimeUnitVector3::TimeUnitVector3(TimeFunction x, TimeFunction y, TimeFunction z) : TimeVector3(std::move(x), std::move(y), std::move(z)) {}

TimeUnitVector3::TimeUnitVector3(double x, double y, double z) : TimeVector3(x, y, z) {}

TimeUnitVector3::TimeUnitVector3(const UnitVector3& v) : TimeUnitVector3(v.x(), v.y(), v.z()) {}

TimeUnitVector3::TimeUnitVector3() : TimeUnitVector3(0, 0, 1) {}

UnitVector3 TimeUnitVector3::time(double time) const {
    return UnitVector3(fx.get(time), fy.get(time), fz.get(time));
}