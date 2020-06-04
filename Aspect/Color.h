//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_COLOR_H
#define CPP_GRAPHICS_COLOR_H

#include <cmath>
#include "../Utils/BaseGeometry/Vector3.h"
#include "../Utils/BaseGeometry/Values.h"

///Class representing a color as an amount of light in the range [0,inf) in the 3 color channels
class Color {

public:

    [[nodiscard]] float inline get_r() const {
        return _r;
    }

    [[nodiscard]] float inline get_g() const {
        return _g;
    }

    [[nodiscard]] float inline get_b() const {
        return _b;
    }


    [[nodiscard]] Color inline set_r(float r) {
        return Color(r, get_g(), get_b());
    }

    [[nodiscard]] Color inline set_g(float g) {
        return Color(get_r(), g, get_b());
    }

    [[nodiscard]] Color inline set_b(float b) {
        return Color(get_r(), get_g(), b);
    }


    [[nodiscard]] Color inline add(Color c) const {
        return Color(
            get_r() + c.get_r(),
            get_g() + c.get_g(),
            get_b() + c.get_b()
        );
    }

    [[nodiscard]] Color inline scale(float k) const {
        return Color(
            get_r() * k,
            get_g() * k,
            get_b() * k
        );
    }

    [[nodiscard]] Color inline scale(const Color & c) const {
        return Color(
            get_r() * c.get_r(),
            get_g() * c.get_g(),
            get_b() * c.get_b()
        );
    }

    [[nodiscard]] bool inline is_zero() const {
        return
            get_r() < Values::eps &&
            get_g() < Values::eps &&
            get_b() < Values::eps;
    }


    Color() : Color(0, 0, 0) {}

    Color(float r, float g, float b) : _r(r), _g(g), _b(b) {}

private:

    float _r, _g, _b;

};


#endif //CPP_GRAPHICS_COLOR_H
