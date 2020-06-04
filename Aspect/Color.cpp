//
// Created by federico on 09/04/2020.
//

#include "Color.h"
#include "../Utils/BaseGeometry/Values.h"


Color::Color(float r, float g, float b) : _r(r), _g(g), _b(b) {}

Color::Color() : Color(0, 0, 0) {}

int Color::tone_mapping(float k) {
    return (int) (255.0 *std::erf(k));
}

float Color::get_r() const {
    return _r;
}

Color Color::set_r(float r) {
    return Color(r, get_g(), get_b());
}

float Color::get_g() const {
    return _g;
}

Color Color::set_g(float g) {
    return Color(get_r(), g, get_b());
}

float Color::get_b() const {
    return _b;
}


Color Color::set_b(float b) {
    return Color(get_r(), get_g(), b);
}


Color Color::add(Color c) const {
    return Color(
            get_r() + c.get_r(),
            get_g() + c.get_g(),
            get_b() + c.get_b()
            );
}

Color Color::scale(float k) const {
    return Color(
            get_r() * k,
            get_g() * k,
            get_b() * k
    );
}

Color Color::scale(const Color & c) const {
    return Color(
            get_r() * c.get_r(),
            get_g() * c.get_g(),
            get_b() * c.get_b()
    );
}

std::string Color::to_string() {
    return "(" + std::to_string(get_r()) + " " + std::to_string(get_g()) + " " + std::to_string(get_b()) + ")";
}

bool Color::is_zero() const {
    return
        get_r() < Values::eps &&
        get_g() < Values::eps &&
        get_b() < Values::eps;
}
