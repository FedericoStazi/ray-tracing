//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_COLOR_H
#define CPP_GRAPHICS_COLOR_H


#include <cmath>

class Color {

private:

    int _r, _g, _b;

    [[nodiscard]] double _sigmoid(double k) const;

public:

    Color();
    Color(int r, int g, int b);

    [[nodiscard]] int get_r() const;
    Color set_r(int r);
    [[nodiscard]] int get_g() const;
    Color set_g(int g);
    [[nodiscard]] int get_b() const;
    Color set_b(int b);

    [[nodiscard]] Color intensity(double k) const;

};


#endif //CPP_GRAPHICS_COLOR_H
