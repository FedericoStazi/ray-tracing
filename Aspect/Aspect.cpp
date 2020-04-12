//
// Created by federico on 11/04/2020.
//

#include "Aspect.h"

Aspect::Aspect() = default;

Aspect::Aspect(const Color &color) : color(color) {}

const Color &Aspect::get_color() const {
    return color;
}
