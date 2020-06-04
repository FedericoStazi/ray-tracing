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

     ///Get a Vector3 with the values of this TimeVector3 at a certain time
     Vector3 time(float time) const {
        if (!_is_function)
            return *this;
        else
            return Vector3(fx.get(time), fy.get(time), fz.get(time));
    }

    TimeVector3(TimeFunction x, TimeFunction y, TimeFunction z)
        : fx(std::move(x)),
          fy(std::move(y)),
          fz(std::move(z)),
          _is_function(true) {}

};


#endif //CPP_GRAPHICS_TIMEVECTOR3_H
