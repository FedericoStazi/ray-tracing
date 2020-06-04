//
// Created by federico on 03/06/2020.
//

#ifndef CPP_GRAPHICS_OPENCYLINDER_H
#define CPP_GRAPHICS_OPENCYLINDER_H


#include "Surface.h"

class OpenCylinder : public Surface{

public:

    UnitVector3 get_normal(const Vector3 & v, float time) const override;

    std::vector<std::pair<float, Surface *>> intersections(const Line & ray, float time) override;

    float furthest_distance(float time) const override {
        return std::sqrt(height * height / 4 + radius * radius);
    }

    OpenCylinder(const ReferenceFrame &referenceFrame, const Aspect &aspect, float radius, float height)
        : Surface(referenceFrame, aspect),
          radius(radius),
          height(height) {}

private:

    float radius, height;
};


#endif //CPP_GRAPHICS_OPENCYLINDER_H
