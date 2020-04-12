//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_ASPECT_H
#define CPP_GRAPHICS_ASPECT_H


#include "Color.h"

class Aspect {

private:

    Color color;

    double k_diffuse = 1; // TODO should it be k_diffuse + k_specular = 1 ?
    double k_specular = 0;
    double roughness = 10;

public:

    Aspect();
    explicit Aspect(const Color &color);

    [[nodiscard]] const Color &get_color() const;
    [[nodiscard]] double get_k_diffuse() const;

};


#endif //CPP_GRAPHICS_ASPECT_H
