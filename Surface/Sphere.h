//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_SPHERE_H
#define CPP_GRAPHICS_SPHERE_H


#include "Surface.h"

class Sphere : public Surface{

public:

    UnitVector3 get_normal(const Vector3 & v, float time) const override{
        return static_cast<UnitVector3>((v - (get_reference_frame().get_location(time))).normalized());
    }

    std::vector<std::pair<float, Surface *>> intersections(const Line& ray, float time) override;

    float furthest_distance(float time) const override {
        return radius;
    }

    Sphere(const ReferenceFrame &referenceFrame, const Aspect &aspect, float radius)
        : Surface(referenceFrame, aspect),
          radius(radius) {}

private:

    float radius;
};


#endif //CPP_GRAPHICS_SPHERE_H
