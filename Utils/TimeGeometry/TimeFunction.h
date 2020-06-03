//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_TIMEFUNCTION_H
#define CPP_GRAPHICS_TIMEFUNCTION_H

#include <functional>

class TimeFunction {

private:

    typedef std::function<float(float)> _function_type;

    bool _is_function{};

    float _value = 0;
    _function_type _function;

    // caching
    float EPS = 1e-6;
    mutable float _last = 0;
    mutable float _cached = 0;

public:

    explicit TimeFunction(const _function_type& value);
    explicit TimeFunction(float value);
    TimeFunction() = default;

    [[nodiscard]] float get(float time) const;

};


#endif //CPP_GRAPHICS_TIMEFUNCTION_H
