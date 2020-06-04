//
// Created by federico on 03/06/2020.
//

#ifndef CPP_GRAPHICS_OPENCYLINDER_H
#define CPP_GRAPHICS_OPENCYLINDER_H


#include "Surface.h"

class OpenCylinder : public Surface{

private:

    float radius, height;

public:

    OpenCylinder(const ReferenceFrame &referenceFrame, const Aspect &aspect, float radius, float height);

    UnitVector3 get_normal(const Vector3 & v, float time);

    std::vector<std::pair<float, Surface *>> intersections(const Line & ray, float time);

    float furthest_distance(float time);

};


#endif //CPP_GRAPHICS_OPENCYLINDER_H
