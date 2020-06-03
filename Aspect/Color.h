//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_COLOR_H
#define CPP_GRAPHICS_COLOR_H

#include <cmath>
#include "../Utils/BaseGeometry/Vector3.h"

class Color {

private:

    float _r, _g, _b;

public:

    static int tone_mapping(float k);

    Color();
    Color(float r, float g, float b);

    [[nodiscard]] float get_r() const;
    Color set_r(float r);
    [[nodiscard]] float get_g() const;
    Color set_g(float g);
    [[nodiscard]] float get_b() const;
    Color set_b(float b);

    [[nodiscard]] Color add(Color c) const;

    [[nodiscard]] Color scale(float k) const;
    [[nodiscard]] Color scale(const Color & c) const;

    [[nodiscard]] bool is_zero() const;

    std::string to_string();

};


#endif //CPP_GRAPHICS_COLOR_H
