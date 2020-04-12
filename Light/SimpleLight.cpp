//
// Created by federico on 12/04/2020.
//

#include "SimpleLight.h"

SimpleLight::SimpleLight(const ReferenceFrame &referenceFrame, double intensity) : Light(referenceFrame), intensity(intensity) {}

double SimpleLight::get_intensity() const {
    return intensity;
}
