//
// Created by federico on 03/06/2020.
//

#include <iostream>
#include "OpenCylinder.h"
#include "../Utils/BaseGeometry/Values.h"

OpenCylinder::OpenCylinder(const ReferenceFrame &referenceFrame, const Aspect &aspect,
                           float radius, float height) : Surface(referenceFrame, aspect), radius(radius), height(height) {}

UnitVector3 OpenCylinder::get_normal(const Vector3 &v, float time) {
    Vector3 w = v - get_reference_frame().get_location(time);
    return static_cast<UnitVector3>(Vector2(
        w.dot(get_reference_frame().get_orientation().get_x_base(time)),
        w.dot(get_reference_frame().get_orientation().get_y_base(time))
        ).normalized());
}

// line is in object's coordinates
std::vector<std::pair<float, Surface *>> OpenCylinder::intersections(const Line &ray, float time) {

    std::vector<std::pair<float, Surface *>> result;

    Line ray_trans = get_reference_frame().to_ref_frame(ray, time);
    Vector3 line2d = get_reference_frame().to_plane(ray_trans.get_direction(time), time);
    float proj_norm = line2d.norm();
    line2d.normalize();

    // cylinder's centre is translated so that ray starts from the origin
    Vector3 centre2d = get_reference_frame().to_plane(static_cast<Vector3>((-1) * (ray.get_location(time))), time);

    float delta = (line2d.dot(centre2d) * line2d.dot(centre2d) - centre2d.squaredNorm() + radius * radius);

    if (delta >= 0) {
        float k = (line2d.dot(centre2d) - std::sqrt(delta)) / proj_norm;
        if (abs(ray_trans.evaluate(k, time).z()) < height/2)
            result.emplace_back(k, this);
        k = (line2d.dot(centre2d) + std::sqrt(delta)) / proj_norm;
        if (abs(ray_trans.evaluate(k, time).z()) < height/2)
            result.emplace_back(k, this);
    }

    return result;

}

float OpenCylinder::furthest_distance(float time) {
    return std::sqrt(height * height / 4 + radius * radius);
}
