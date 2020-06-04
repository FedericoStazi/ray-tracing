//
// Created by federico on 10/04/2020.
//

#ifndef CPP_GRAPHICS_VALUES_H
#define CPP_GRAPHICS_VALUES_H

#include <limits>

/// class containing project-wide constant values
struct Values {
public:
    constexpr static float eps = 1e-4;
    constexpr static float inf = std::numeric_limits<float>::infinity();
};


#endif //CPP_GRAPHICS_VALUES_H
