//
// Created by federico on 11/04/2020.
//

#include "Polygon.h"

Polygon::Polygon(const ReferenceFrame &referenceFrame, const std::vector<Vector2>& pts, const Aspect &aspect) : Surface(referenceFrame, aspect) {
    for (const Vector2& point : pts)
        points.push_back(point);
}

std::vector<std::pair<double, Color>> Polygon::intersections(Line ray, double time) {

    Vector2 uv = get_reference_frame().point_intersection(ray, time);

    bool inside = true;

    for (int i=0; i<points.size(); i++) {
        Vector2 a = points[i];
        Vector2 b = points[(i + 1 == points.size()) ? 0 : i + 1];
        if (b.subtract(a).cross_product(uv.subtract(b)).z() < 0)
            inside = false;
    }

    std::vector<std::pair<double, Color>> result;

    if (inside)
        result.emplace_back(get_reference_frame().k_intersection(ray, time), get_aspect().get_color());

    return result;

}
