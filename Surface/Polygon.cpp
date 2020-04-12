//
// Created by federico on 11/04/2020.
//

#include "Polygon.h"

Polygon::Polygon(const ReferenceFrame &referenceFrame, const Aspect &aspect, const std::vector<Vector2>& pts) : Surface(referenceFrame, aspect) {
    for (const Vector2& point : pts)
        add(point);
}
