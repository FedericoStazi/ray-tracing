//
// Created by federico on 11/04/2020.
//

#include "Entity.h"

#include <utility>

Entity::Entity(ReferenceFrame referenceFrame) : reference_frame(std::move(referenceFrame)) {}

Entity::Entity() = default;

const ReferenceFrame &Entity::get_reference_frame() const {
    return reference_frame;
}
