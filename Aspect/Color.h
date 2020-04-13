//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_COLOR_H
#define CPP_GRAPHICS_COLOR_H


#include <cmath>
#include "../Utils/BaseGeometry/Vector3.h"

class Color {

private:

    double _r, _g, _b;

public:

    static int tone_mapping(double k);

    Color();
    Color(double r, double g, double b);

    [[nodiscard]] double get_r() const;
    Color set_r(double r);
    [[nodiscard]] double get_g() const;
    Color set_g(double g);
    [[nodiscard]] double get_b() const;
    Color set_b(double b);

    [[nodiscard]] Color add(Color c) const;

    [[nodiscard]] Color scale(double k) const;
    [[nodiscard]] Color scale(const Color & c) const;

    std::string to_string();

};


#endif //CPP_GRAPHICS_COLOR_H
