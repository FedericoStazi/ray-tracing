//
// Created by federico on 11/04/2020.
//

#include "Surface.h"

#include <utility>

Surface::Surface(const ReferenceFrame &referenceFrame, const Aspect &aspect) : Entity(referenceFrame), aspect(aspect) {}

const Aspect &Surface::get_aspect() const {
    return aspect;
}

void Surface::add(const Vector2& point) {
    points.push_back(point);
}

UnitVector3 Surface::get_normal(const Vector3 & v, double time) {
    return get_reference_frame().get_orientation().get_z_base(time);
}

std::vector<std::pair<double, Surface *>> Surface::intersections(const Line & ray, double time) {

    Vector2 uv = get_reference_frame().point_intersection(ray, time);

    bool inside = true;

    for (int i=0; i<points.size(); i++) {
        Vector2 a = points[i];
        Vector2 b = points[(i + 1 == points.size()) ? 0 : i + 1];
        if (b.subtract(a).cross_product(uv.subtract(b)).z() < 0)
            inside = false;
    }

    std::vector<std::pair<double, Surface *>> result;

    if (inside)
        result.emplace_back(get_reference_frame().k_intersection(ray, time),this);

    return result;
}
