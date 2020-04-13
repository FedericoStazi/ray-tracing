//
// Created by federico on 12/04/2020.
//

#include "SimpleLight.h"

#include <utility>

SimpleLight::SimpleLight(const ReferenceFrame &referenceFrame, Color intensity) : Light(referenceFrame), intensity(intensity) {}

Color SimpleLight::get_intensity() const {
    return intensity;
}
