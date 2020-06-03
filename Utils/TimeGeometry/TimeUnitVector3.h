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

    explicit TimeUnitVector3(const Vector3& v);
    explicit TimeUnitVector3(TimeVector3 v);
    TimeUnitVector3(TimeFunction x, TimeFunction y, TimeFunction z);
    TimeUnitVector3(float x, float y, float z);
    explicit TimeUnitVector3(const UnitVector3& v);
    TimeUnitVector3();

    [[nodiscard]] UnitVector3 time(float time) const;

};


#endif //CPP_GRAPHICS_TIMEUNITVECTOR3_H

#pragma clang diagnostic pop