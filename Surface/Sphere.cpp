//
// Created by federico on 11/04/2020.
//

#include <cmath>
#include "Sphere.h"
#include "../Utils/BaseGeometry/Constants.h"

Sphere::Sphere(const ReferenceFrame &referenceFrame, const Aspect &aspect,
               float radius) : Surface(referenceFrame, aspect), radius(radius) {}

UnitVector3 Sphere::get_normal(const Vector3 & v, float time) {
    return static_cast<UnitVector3>((v - (get_reference_frame().get_location(time))).normalized());
}

std::vector<std::pair<float, Surface *>> Sphere::intersections(const Line& ray, float time) {

    std::vector<std::pair<float, Surface *>> result;

    // sphere's centre is translated so that ray starts from the origin
    Vector3 line = ray.get_direction(time);
    Vector3 centre = get_reference_frame().get_location(time) - (ray.get_location(time));

    float delta = line.dot(centre) * line.dot(centre) - centre.norm() * centre.norm() + radius * radius;

    if (delta >= 0) {
        result.emplace_back(line.dot(centre) - std::sqrt(delta), this);
        result.emplace_back(line.dot(centre) + std::sqrt(delta), this);
    }

    return result;
}

float Sphere::furthest_distance(float time) {

    if (get_reference_frame().get_location(time).norm() > Constants::eps) {

        Line line = Line::between_points(Vector3(0, 0, 0), get_reference_frame().get_location(time));
        std::vector<std::pair<float, Surface *>> line_intersections = intersections(line, time);
        return std::max(line_intersections[0].first, line_intersections[1].first);
    } else {

        return radius;
    }
}
