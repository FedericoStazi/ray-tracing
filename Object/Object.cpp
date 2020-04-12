//
// Created by federico on 11/04/2020.
//

#include "Object.h"

Object::Object(const ReferenceFrame &referenceFrame) : Entity(referenceFrame) {}

void Object::add(Surface *surface) {
    surfaces.insert(surface);
}

std::vector<std::pair<double, Color>> Object::intersections(const Line& ray, double time) {

    std::vector<std::pair<double, Color>> result;

    for (Surface * surface : surfaces) {
        auto v = surface->intersections(get_reference_frame().to_ref_frame(ray, time), time);
        result.insert(result.end(), v.begin(), v.end());
    }

    return result;
}
