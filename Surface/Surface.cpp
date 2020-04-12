//
// Created by federico on 11/04/2020.
//

#include "Surface.h"

#include <utility>

Surface::Surface(const ReferenceFrame &referenceFrame, const Aspect &aspect) : Entity(referenceFrame), aspect(aspect) {}

const Aspect &Surface::get_aspect() const {
    return aspect;
}
