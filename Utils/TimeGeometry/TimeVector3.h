//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_TIMEVECTOR3_H
#define CPP_GRAPHICS_TIMEVECTOR3_H

#include "TimeFunction.h"
#include "../BaseGeometry/Vector3.h"

class TimeVector3 {

protected:

    TimeFunction fx, fy, fz;

public:

    TimeVector3(TimeFunction x, TimeFunction y, TimeFunction z);
    TimeVector3(double x, double y, double z);
    explicit TimeVector3(const Vector3& v);
    TimeVector3();

    [[nodiscard]] Vector3 time(double time) const;

};


#endif //CPP_GRAPHICS_TIMEVECTOR3_H