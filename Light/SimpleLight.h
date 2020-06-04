//
// Created by federico on 12/04/2020.
//

#ifndef CPP_GRAPHICS_SIMPLELIGHT_H
#define CPP_GRAPHICS_SIMPLELIGHT_H


#include "Light.h"

///Simple light class
class SimpleLight : public Light{

public:

    [[nodiscard]] Color inline get_intensity() const {
        return intensity;
    }

    SimpleLight(const ReferenceFrame &referenceFrame, Color intensity) : Light(referenceFrame), intensity(intensity) {}

private:

    Color intensity;

};


#endif //CPP_GRAPHICS_SIMPLELIGHT_H
