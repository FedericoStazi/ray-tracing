//
// Created by federico on 10/04/2020.
//

#ifndef CPP_GRAPHICS_CONSTANTS_H
#define CPP_GRAPHICS_CONSTANTS_H


#include <limits>

struct Constants {
public:
    constexpr static double eps = 1e-6;
    constexpr static double inf = std::numeric_limits<double>::infinity();
};


#endif //CPP_GRAPHICS_CONSTANTS_H
