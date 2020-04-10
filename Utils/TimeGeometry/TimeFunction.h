//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_TIMEFUNCTION_H
#define CPP_GRAPHICS_TIMEFUNCTION_H

#include <functional>

class TimeFunction {

private:

    typedef std::function<double(double)> data_type;

    data_type value;

public:

    explicit TimeFunction(data_type value);
    explicit TimeFunction(double value);

    [[nodiscard]] double get(double time) const;

};


#endif //CPP_GRAPHICS_TIMEFUNCTION_H
