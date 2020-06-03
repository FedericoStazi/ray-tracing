//
// Created by federico on 09/04/2020.
//

#include "TimeFunction.h"

#include <cmath>
#include <assert.h>

TimeFunction::TimeFunction(TimeFunction::_function_type* function_ptr) : _function(function_ptr), _is_function(true) {}

TimeFunction::TimeFunction(float value) : _value(value), _is_function(false) {}

float TimeFunction::get(float time) const {

    if (!_is_function)
        return _value;
    else
        return (*_function)(time);
}
