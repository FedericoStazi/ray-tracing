//
// Created by federico on 11/04/2020.
//

#include "Surface.h"

#include <utility>

std::vector<std::pair<float, Surface *>> Surface::intersections(const Line & ray, float time) {

    Vector2 uv = get_reference_frame().point_intersection(ray, time);

    bool inside = true;

    for (int i=0; i<points.size(); i++) {
        Vector2 a = points[i];
        Vector2 b = points[(i + 1 == points.size()) ? 0 : i + 1];
        if ((b - a).cross(uv - b).z() < 0)
            inside = false;
    }

    std::vector<std::pair<float, Surface *>> result;

    if (inside)
        result.emplace_back(get_reference_frame().k_intersection(ray, time),this);

    return result;
}