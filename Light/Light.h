//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_LIGHT_H
#define CPP_GRAPHICS_LIGHT_H


#include "../Entity.h"

class Light : public Entity {


public:

    explicit Light(const ReferenceFrame &referenceFrame);
    virtual double get_intensity() const = 0;

};


#endif //CPP_GRAPHICS_LIGHT_H
