//
// Created by federico on 11/04/2020.
//

#include "Circle.h"
#include "../Utils/BaseGeometry/Values.h"

Circle::Circle(const ReferenceFrame &referenceFrame, const Aspect &aspect,
               float radius) : Surface(referenceFrame, aspect), radius(radius) {}

std::vector<std::pair<float, Surface *>> Circle::intersections(const Line& ray, float time) {

    std::vector<std::pair<float, Surface *>> result;

    if (get_reference_frame().point_intersection(ray, time).norm() < radius)
        result.emplace_back(get_reference_frame().k_intersection(ray, time), this);

    return result;

}

float Circle::furthest_distance(float time) {
    return get_reference_frame().get_location(time).norm()  + radius;
}