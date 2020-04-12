//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_COLOR_H
#define CPP_GRAPHICS_COLOR_H


class Color {

private:

    int _r, _g, _b;

public:

    Color();
    Color(int r, int g, int b);

    [[nodiscard]] int get_r() const;
    Color set_r(int r);
    [[nodiscard]] int get_g() const;
    Color set_g(int g);
    [[nodiscard]] int get_b() const;
    Color set_b(int b);

};


#endif //CPP_GRAPHICS_COLOR_H
