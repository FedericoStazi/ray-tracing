//
// Created by federico on 09/04/2020.
//

#include "TimeFunction.h"

#include <utility>

TimeFunction::TimeFunction(TimeFunction::_function_type   function) : _function(std::move(function)), _is_function(true) {}

TimeFunction::TimeFunction(double value) : _value(value), _is_function(false) {}

double TimeFunction::get(double time) const { return _is_function ? _function(time) : _value; }

/*
double TimeFunction::get(double time) const {

    if (!_is_function) {
        return _value;
    } else {

        if (std::abs(time - *_last) > EPS) {
            *_last = time;
            *_cached = _function(time);
        }

        return *_cached;
    }
}
*/