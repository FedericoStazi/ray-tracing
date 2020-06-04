//
// Created by federico on 13/04/2020.
//

#include "RGB.h"

int RGB::_to_rgb(float i) {

    if (i < 0)
        throw NegativeIntensityException();

    //tone mapping
    float p = pow(i, kb);
    float k = std::min(1.0, p / (p + 1/pow(2*ka, kb)));

    //display encoding
    return (int) (pow(k, gamma) * 255.0);

}

float RGB::_from_rgb(int c) {

    float k = pow((float) c / 255, 1/gamma);

    float p = k / (pow(2*ka, kb) * (1 - k));

    return pow(p, 1/kb);

}