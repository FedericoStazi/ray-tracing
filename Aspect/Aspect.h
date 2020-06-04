//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_ASPECT_H
#define CPP_GRAPHICS_ASPECT_H


#include "Color.h"

///Contains information about a surface aspect
class Aspect {

public:

    [[nodiscard]] const Color inline & get_k_diffuse() const {
        return k_diffuse;
    }

    [[nodiscard]] const Color inline & get_k_specular() const {
        return k_specular;
    }

    [[nodiscard]] const Color inline & get_k_mirror() const {
        return k_mirror;
    }

    [[nodiscard]] float inline get_roughness() const {
        return roughness;
    }

    Aspect() = default;

    explicit Aspect(const Color &color) : k_diffuse(color) {}

    Aspect(const Color &k_diffuse, const Color &k_specular, const Color &k_mirror, float roughness)
        : k_diffuse(k_diffuse),
          k_specular(k_specular),
          k_mirror(k_mirror),
          roughness(roughness) {}

private:

    // Phong's Illumination model parameters
    Color k_diffuse;
    Color k_specular = Color(0.5, 0.5, 0.5);
    Color k_mirror = Color(0.1, 0.1, 0.1);
    float roughness = 5;

};


#endif //CPP_GRAPHICS_ASPECT_H
