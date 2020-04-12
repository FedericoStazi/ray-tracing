//
// Created by federico on 11/04/2020.
//

#include "Circle.h"

Circle::Circle(const ReferenceFrame &referenceFrame, const Aspect &aspect,
               double radius) : Surface(referenceFrame, aspect), radius(radius) {}

std::vector<std::pair<double, Color>> Circle::intersections(const Line& ray, double time) {

    std::vector<std::pair<double, Color>> result;

    if (get_reference_frame().point_intersection(ray, time).magnitude() < radius)
        result.emplace_back(get_reference_frame().k_intersection(ray, time), get_aspect().get_color());

    return result;

}
