//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_ASPECT_H
#define CPP_GRAPHICS_ASPECT_H


#include "Color.h"

class Aspect {

private:

    Color k_diffuse;
    Color k_specular = Color(0.5, 0.5, 0.5);
    Color k_mirror = Color(0.1, 0.1, 0.1);
    float roughness = 5;

public:

    Aspect();
    explicit Aspect(const Color &color);
    Aspect(const Color &k_diffuse, const Color &k_specular, const Color &k_mirror, float roughness);

    [[nodiscard]] const Color &get_k_diffuse() const;
    [[nodiscard]] const Color &get_k_specular() const;
    [[nodiscard]] const Color &get_k_mirror() const;
    [[nodiscard]] float get_roughness() const;

};


#endif //CPP_GRAPHICS_ASPECT_H
