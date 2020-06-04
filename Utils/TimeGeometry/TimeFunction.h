//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_TIMEFUNCTION_H
#define CPP_GRAPHICS_TIMEFUNCTION_H

#include <functional>

class TimeFunction {

    typedef std::function<float(float)> _function_type;

public:

    ///Evaluate the function at a certain time
    [[nodiscard]] inline float get(float time) const {
        if (!_is_function)
            return _value;
        else
            return (*_function)(time);
    }

    explicit TimeFunction(TimeFunction::_function_type* function_ptr) : _function(function_ptr), _is_function(true) {}

    explicit TimeFunction(float value) : _value(value), _is_function(false) {}

    TimeFunction() = default;

private:

    bool _is_function = false;
    float _value = 0;
    _function_type* _function = nullptr;

};


#endif //CPP_GRAPHICS_TIMEFUNCTION_H
