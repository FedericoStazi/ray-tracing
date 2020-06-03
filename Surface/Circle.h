//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_CIRCLE_H
#define CPP_GRAPHICS_CIRCLE_H

#include <vector>
#include "Surface.h"

class Circle : public Surface {

private:

    float radius;

public:

    Circle(const ReferenceFrame &referenceFrame, const Aspect &aspect, float radius);

    std::vector<std::pair<float, Surface *>> intersections(const Line& ray, float time) override;

    float furthest_distance(float time) override;

};


#endif //CPP_GRAPHICS_CIRCLE_H
