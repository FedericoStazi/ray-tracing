//
// Created by federico on 09/04/2020.
//

#include "Color.h"
#include "../Utils/BaseGeometry/Constants.h"


Color::Color(double r, double g, double b) : _r(r), _g(g), _b(b) {}

Color::Color() : Color(0, 0, 0) {}

int Color::tone_mapping(double k) {
    return (int) (255.0 *std::erf(k));
}

double Color::get_r() const {
    return _r;
}

Color Color::set_r(double r) {
    return Color(r, get_g(), get_b());
}

double Color::get_g() const {
    return _g;
}

Color Color::set_g(double g) {
    return Color(get_r(), g, get_b());
}

double Color::get_b() const {
    return _b;
}


Color Color::set_b(double b) {
    return Color(get_r(), get_g(), b);
}


Color Color::add(Color c) const {
    return Color(
            get_r() + c.get_r(),
            get_g() + c.get_g(),
            get_b() + c.get_b()
            );
}

Color Color::scale(double k) const {
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
        get_r() < Constants::eps &&
        get_g() < Constants::eps &&
        get_b() < Constants::eps;
}
