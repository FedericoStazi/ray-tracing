//
// Created by federico on 11/04/2020.
//

#include "Circle.h"
#include "../Utils/BaseGeometry/Values.h"

std::vector<std::pair<float, Surface *>> Circle::intersections(const Line& ray, float time) {
    std::vector<std::pair<float, Surface *>> result;
    if (get_reference_frame().point_intersection(ray, time).norm() < radius)
        result.emplace_back(get_reference_frame().k_intersection(ray, time), this);
    return result;
}