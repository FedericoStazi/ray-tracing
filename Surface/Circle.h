//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_CIRCLE_H
#define CPP_GRAPHICS_CIRCLE_H

#include <vector>
#include "Surface.h"

class Circle : public Surface {

private:

    double radius;

public:

    Circle(const ReferenceFrame &referenceFrame, const Aspect &aspect, double radius);
    std::vector<std::pair<double, Surface *>> intersections(const Line& ray, double time) override;

};


#endif //CPP_GRAPHICS_CIRCLE_H
