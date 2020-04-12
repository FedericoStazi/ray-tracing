//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_TIMEFUNCTION_H
#define CPP_GRAPHICS_TIMEFUNCTION_H

#include <functional>

class TimeFunction {

private:

    typedef std::function<double(double)> _function_type;

    bool _is_function;

    double _value = 0;
    _function_type _function;

    // caching
    double EPS = 1e-6;
    mutable double * _last = new double(0);
    mutable double * _cached = new double;

public:

    explicit TimeFunction(_function_type   value);
    explicit TimeFunction(double value);

    [[nodiscard]] double get(double time) const;

};


#endif //CPP_GRAPHICS_TIMEFUNCTION_H
