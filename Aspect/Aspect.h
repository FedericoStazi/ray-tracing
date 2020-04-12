//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_ASPECT_H
#define CPP_GRAPHICS_ASPECT_H


#include "Color.h"

class Aspect {

private:

    Color color;

public:

    Aspect();
    explicit Aspect(const Color &color);

    [[nodiscard]] const Color &get_color() const;

};


#endif //CPP_GRAPHICS_ASPECT_H
