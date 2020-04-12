//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_SPHERE_H
#define CPP_GRAPHICS_SPHERE_H


#include "Surface.h"

class Sphere : public Surface{

private:

    double radius;

public:

    Sphere(const ReferenceFrame &referenceFrame, const Aspect &aspect, double radius);

    UnitVector3 get_normal(const Vector3 & v, double time) override;

    std::vector<std::pair<double, Surface *>> intersections(const Line& ray, double time) override;

};


#endif //CPP_GRAPHICS_SPHERE_H
