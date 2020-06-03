//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_SPHERE_H
#define CPP_GRAPHICS_SPHERE_H


#include "Surface.h"

class Sphere : public Surface{

private:

    float radius;

public:

    Sphere(const ReferenceFrame &referenceFrame, const Aspect &aspect, float radius);

    UnitVector3 get_normal(const Vector3 & v, float time) override;

    std::vector<std::pair<float, Surface *>> intersections(const Line& ray, float time) override;

    float furthest_distance(float time) override;

};


#endif //CPP_GRAPHICS_SPHERE_H
