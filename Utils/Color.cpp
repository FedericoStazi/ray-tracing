//
// Created by federico on 09/04/2020.
//

#include "Color.h"


Color::Color(int r, int g, int b) : _r(r), _g(g), _b(b) {}

Color::Color() : Color(0, 0, 0) {}

int Color::get_r() const {
    return _r;
}

Color Color::set_r(int r) {
    return Color(r, get_g(), get_b());
}

int Color::get_g() const {
    return _g;
}

Color Color::set_g(int g) {
    return Color(get_r(), _g, get_b());
}

int Color::get_b() const {
    return _b;
}

Color Color::set_b(int b) {
    return Color(get_r(), get_g(), _b);
}
