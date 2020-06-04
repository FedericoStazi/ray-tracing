//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_CIRCLE_H
#define CPP_GRAPHICS_CIRCLE_H

#include <vector>
#include "Surface.h"

class Circle : public Surface {

public:

    std::vector<std::pair<float, Surface *>> intersections(const Line& ray, float time) override;

    float furthest_distance(float time) const override {
        return radius;
    }

    Circle(const ReferenceFrame &referenceFrame, const Aspect &aspect, float radius)
        : Surface(referenceFrame, aspect),
          radius(radius) {}

private:

    float radius;

};


#endif //CPP_GRAPHICS_CIRCLE_H
