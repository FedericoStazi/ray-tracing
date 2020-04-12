//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_POLYGON_H
#define CPP_GRAPHICS_POLYGON_H


#include "Surface.h"

class Polygon : public Surface {

public:

    Polygon(const ReferenceFrame &referenceFrame, const std::vector<Vector2>& points, const Aspect &aspect);

    std::vector<std::pair<double, Color>> intersections(Line ray, double time) override;

};


#endif //CPP_GRAPHICS_POLYGON_H
