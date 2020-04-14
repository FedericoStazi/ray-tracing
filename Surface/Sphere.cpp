//
// Created by federico on 11/04/2020.
//

#include <cmath>
#include "Sphere.h"
#include "../Utils/BaseGeometry/Constants.h"

Sphere::Sphere(const ReferenceFrame &referenceFrame, const Aspect &aspect,
               double radius) : Surface(referenceFrame, aspect), radius(radius) {}

UnitVector3 Sphere::get_normal(const Vector3 & v, double time) {
    return UnitVector3(v.subtract(get_reference_frame().get_location(time)).normalized());
}

std::vector<std::pair<double, Surface *>> Sphere::intersections(const Line& ray, double time) {

    std::vector<std::pair<double, Surface *>> result;

    // sphere's centre is translated so that ray starts from the origin
    Vector3 line = ray.get_direction(time);
    Vector3 centre = get_reference_frame().get_location(time).subtract(ray.get_location(time));

    double delta = line.dot_product(centre) * line.dot_product(centre) - centre.magnitude() * centre.magnitude() + radius * radius;

    if (delta >= 0) {
        result.emplace_back(line.dot_product(centre) - std::sqrt(delta), this);
        result.emplace_back(line.dot_product(centre) + std::sqrt(delta), this);
    }

    return result;
}

double Sphere::furthest_distance(double time) {

    if (get_reference_frame().get_location(time).magnitude() > Constants::eps) {

        Line line = Line::between_points(Vector3(0, 0, 0), get_reference_frame().get_location(time));
        std::vector<std::pair<double, Surface *>> line_intersections = intersections(line, time);
        return std::max(line_intersections[0].first, line_intersections[1].first);
    } else {

        return radius;
    }
}
