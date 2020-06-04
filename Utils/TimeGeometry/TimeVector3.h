//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_TIMEVECTOR3_H
#define CPP_GRAPHICS_TIMEVECTOR3_H

#include "TimeFunction.h"
#include "../BaseGeometry/Vector3.h"

class Vector3;
class TimeVector3 : public Vector3{

    using Vector3::Vector3;

protected:

    TimeFunction fx, fy, fz;
    bool _is_function = false;

public:

    TimeVector3() : Vector3() {}

    TimeVector3(TimeFunction x, TimeFunction y, TimeFunction z);

    [[nodiscard]] Vector3 time(float time) const;

};


#endif //CPP_GRAPHICS_TIMEVECTOR3_H
