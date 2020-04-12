//
// Created by federico on 11/04/2020.
//

#include <cmath>
#include "Sphere.h"

Sphere::Sphere(const ReferenceFrame &referenceFrame, const Aspect &aspect,
               double radius) : Surface(referenceFrame, aspect), radius(radius) {}

std::vector<std::pair<double, Color> > Sphere::intersections(const Line& ray, double time) {

    std::vector<std::pair<double, Color>> result;

    // sphere's centre is translated so that ray starts from the origin
    Vector3 line = ray.get_direction(time);
    Vector3 centre = get_reference_frame().get_location(time).add(ray.get_location(time).scale(-1));

    double delta = line.dot_product(centre) * line.dot_product(centre) - centre.magnitude() * centre.magnitude() + radius * radius;

    if (delta >= 0) {
        result.emplace_back(line.dot_product(centre) - std::sqrt(delta), get_aspect().get_color());
        result.emplace_back(line.dot_product(centre) + std::sqrt(delta), get_aspect().get_color());
    }

    return result;
}
