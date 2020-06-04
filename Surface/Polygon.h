//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_POLYGON_H
#define CPP_GRAPHICS_POLYGON_H


#include "Surface.h"

class Polygon : public Surface {

public:

    //Polygon from a vectors of 2d points in the plane's coordinates
    Polygon(const ReferenceFrame &referenceFrame, const Aspect &aspect, const std::vector<Vector2>& points)
        : Surface(referenceFrame, aspect) {
            for (const Vector2& point : points)
                add(point);
        }

};


#endif //CPP_GRAPHICS_POLYGON_H
