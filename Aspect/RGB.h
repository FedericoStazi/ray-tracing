//
// Created by federico on 13/04/2020.
//

#ifndef CPP_GRAPHICS_RGB_H
#define CPP_GRAPHICS_RGB_H


#include <string>
#include "Color.h"

class RGB {

private:

    struct NegativeIntensityException: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The intensity must be positive";
        }
    };

    int _r, _g, _b;

    static constexpr double a = 2;
    static constexpr double b = 1.3;

    static constexpr double gamma = 2.2;

    static int _to_rgb(double i);
    static double _from_rgb(int c);

public:

    RGB(int r, int g, int b);

    std::string to_string();
    std::string to_hex();

    static RGB to_rgb(Color c);
    Color from_rgb();

};


#endif //CPP_GRAPHICS_RGB_H
