//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_ENTITY_H
#define CPP_GRAPHICS_ENTITY_H


#include "Utils/Geometry/ReferenceFrame.h"

///Parent of any class that has a position in the world
class Entity {

public:

    [[nodiscard]] const ReferenceFrame &get_reference_frame() const {
        return reference_frame;
    }

protected:

    explicit Entity(ReferenceFrame referenceFrame) : reference_frame(std::move(referenceFrame)) {}
    Entity() = default;

private:

    ReferenceFrame reference_frame;

};


#endif //CPP_GRAPHICS_ENTITY_H
