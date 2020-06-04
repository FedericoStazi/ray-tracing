//
// Created by federico on 11/04/2020.
//

#include "Object.h"

std::vector<std::pair<float, Surface *>> Object::intersections(const Line& ray, float time) const {

    std::vector<std::pair<float, Surface *>> result;

    if (ray.distance(get_reference_frame().get_location(time), time) < furthest_distance)
        for (Surface * surface : surfaces) {
            std::vector<std::pair<float, Surface *>> v = surface->intersections(get_reference_frame().to_ref_frame(ray, time), time);
            result.insert(result.end(), v.begin(), v.end());
        }

    return result;
}
