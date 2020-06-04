//
// Created by federico on 13/04/2020.
//

#ifndef CPP_GRAPHICS_RGB_H
#define CPP_GRAPHICS_RGB_H


#include <string>
#include "Color.h"

///Class representing a color in the range [0,255] in the 3 color channels
class RGB {

public:

    static RGB to_rgb(Color c) {
        return RGB(
            _to_rgb(c.get_r()),
            _to_rgb(c.get_g()),
            _to_rgb(c.get_b())
        );
    }

    Color from_rgb() {
        return Color(
            _from_rgb(_r),
            _from_rgb(_g),
            _from_rgb(_b)
        );
    }

    RGB(int r, int g, int b) : _r(r), _g(g), _b(b) {}

    std::string to_string() {
        return std::to_string(_r)+" "+std::to_string(_g)+" "+std::to_string(_b)+" ";
    }

private:

    struct NegativeIntensityException: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The intensity must be positive";
        }
    };

    int _r, _g, _b;

    static constexpr float ka = 2;
    static constexpr float kb = 1.3;

    static constexpr float gamma = 2.2;

    static int _to_rgb(float i);
    static float _from_rgb(int c);

};


#endif //CPP_GRAPHICS_RGB_H
