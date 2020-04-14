//
// Created by federico on 11/04/2020.
//

#include "Circle.h"
#include "../Utils/BaseGeometry/Constants.h"

Circle::Circle(const ReferenceFrame &referenceFrame, const Aspect &aspect,
               double radius) : Surface(referenceFrame, aspect), radius(radius) {}

std::vector<std::pair<double, Surface *>> Circle::intersections(const Line& ray, double time) {

    std::vector<std::pair<double, Surface *>> result;

    if (get_reference_frame().point_intersection(ray, time).magnitude() < radius)
        result.emplace_back(get_reference_frame().k_intersection(ray, time), this);

    return result;

}

double Circle::furthest_distance(double time) {
    return get_reference_frame().get_location(time).magnitude()  + radius;
}