//
// Created by federico on 09/04/2020.
//

#include "TimeFunction.h"

#include <cmath>

TimeFunction::TimeFunction(const TimeFunction::_function_type& function) : _cached(function(0)), _function(function), _is_function(true) {}

TimeFunction::TimeFunction(float value) : _value(value), _is_function(false) {}

float TimeFunction::get(float time) const {

    if (!_is_function) {
        return _value;
    } else {
        return _function(time);

        /*
        if (std::abs(time - _last) > EPS) {
            _last = time;
            _cached = _function(time);
        }

        return _cached;
         */
    }
}
