//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_ENTITY_H
#define CPP_GRAPHICS_ENTITY_H


#include "Utils/Geometry/ReferenceFrame.h"

class Entity {

private:

    ReferenceFrame reference_frame;

protected:

    explicit Entity(ReferenceFrame referenceFrame);
    Entity();

public:

    [[nodiscard]] const ReferenceFrame &get_reference_frame() const;

};


#endif //CPP_GRAPHICS_ENTITY_H
