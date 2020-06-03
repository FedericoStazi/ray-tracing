//
// Created by federico on 11/04/2020.
//

#include "Object.h"

Object::Object(const ReferenceFrame &referenceFrame) : Entity(referenceFrame) {}

void Object::add(Surface *surface) {
    surfaces.insert(surface);
    furthest_distance = std::max(furthest_distance, surface->furthest_distance(0));
}

std::vector<std::pair<float, Surface *>> Object::intersections(const Line& ray, float time) {

    std::vector<std::pair<float, Surface *>> result;

    if (ray.distance(get_reference_frame().get_location(time), time) < furthest_distance)
        for (Surface * surface : surfaces) {
            std::vector<std::pair<float, Surface *>> v = surface->intersections(get_reference_frame().to_ref_frame(ray, time), time);
            result.insert(result.end(), v.begin(), v.end());
        }

    return result;
}
