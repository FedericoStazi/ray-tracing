//
// Created by federico on 12/04/2020.
//

#ifndef CPP_GRAPHICS_SIMPLELIGHT_H
#define CPP_GRAPHICS_SIMPLELIGHT_H


#include "Light.h"

class SimpleLight : public Light{

private:

    Color intensity;

public:

    SimpleLight(const ReferenceFrame &referenceFrame, Color intensity);
    Color get_intensity() const override;

};


#endif //CPP_GRAPHICS_SIMPLELIGHT_H
