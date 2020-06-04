//
// Created by federico on 11/04/2020.
//

#include <cmath>
#include "Sphere.h"
#include "../Utils/BaseGeometry/Values.h"

std::vector<std::pair<float, Surface *>> Sphere::intersections(const Line& ray, float time) {

    std::vector<std::pair<float, Surface *>> result;

    // sphere's centre is translated so that ray starts from the origin
    Vector3 line = ray.get_direction(time);
    Vector3 centre = get_reference_frame().get_location(time) - (ray.get_location(time));

    float delta = line.dot(centre) * line.dot(centre) - centre.squaredNorm() + radius * radius;

    if (delta >= 0) {
        result.emplace_back(line.dot(centre) - std::sqrt(delta), this);
        result.emplace_back(line.dot(centre) + std::sqrt(delta), this);
    }

    return result;
}
