//
// Created by federico on 09/04/2020.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"
#ifndef CPP_GRAPHICS_TIMEUNITVECTOR3_H
#define CPP_GRAPHICS_TIMEUNITVECTOR3_H


#include "TimeFunction.h"
#include "TimeVector3.h"
#include "../BaseGeometry/Vector3.h"
#include "../BaseGeometry/UnitVector3.h"

class TimeUnitVector3 : public TimeVector3 {

public:

    [[nodiscard]] UnitVector3 time(float time) const {
        return static_cast<UnitVector3>(TimeVector3::time(time));
    }

    // non time depending constructors

    explicit TimeUnitVector3(const Vector3& v) : TimeUnitVector3(UnitVector3(v)) {}

    TimeUnitVector3(float x, float y, float z) : TimeVector3(x, y, z) {}

    TimeUnitVector3() : TimeUnitVector3(0, 0, 1) {}

    // time depending constructors

    explicit TimeUnitVector3(TimeVector3 v) : TimeVector3(std::move(v)) {}

    TimeUnitVector3(TimeFunction x, TimeFunction y, TimeFunction z) : TimeVector3(x, y, z) {}

    explicit TimeUnitVector3(const UnitVector3& v) : TimeUnitVector3(v.x(), v.y(), v.z()) {}

};


#endif //CPP_GRAPHICS_TIMEUNITVECTOR3_H
#pragma clang diagnostic pop