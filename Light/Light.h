//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_LIGHT_H
#define CPP_GRAPHICS_LIGHT_H


#include "../Entity.h"

///Parent class of all lights
class Light : public Entity {

public:

    Light(const ReferenceFrame &referenceFrame) : Entity(referenceFrame) {}
    virtual Color get_intensity() const = 0;

};


#endif //CPP_GRAPHICS_LIGHT_H
