//
// Created by federico on 13/04/2020.
//

#include "RGB.h"

RGB::RGB(int r, int g, int b) : _r(r), _g(g), _b(b) {}

std::string RGB::to_string() {
    return std::to_string(_r)+" "+std::to_string(_g)+" "+std::to_string(_b)+" ";
}

int RGB::_to_rgb(float i) {

    if (i < 0)
        throw NegativeIntensityException();

    //tone mapping
    float p = pow(i, b);
    float k = std::min(1.0, p / (p + 1/pow(2*a, b)));

    //display encoding
    return (int) (pow(k, gamma) * 255.0);

}

float RGB::_from_rgb(int c) {

    float k = pow((float) c / 255, 1/gamma);

    float p = k / (pow(2*a, b) * (1 - k));

    return pow(p, 1/b);

}

RGB RGB::to_rgb(Color c) {
    return RGB(
            _to_rgb(c.get_r()),
            _to_rgb(c.get_g()),
            _to_rgb(c.get_b())
            );
}

Color RGB::from_rgb() {
    return Color(
            _from_rgb(_r),
            _from_rgb(_g),
            _from_rgb(_b)
            );
}
