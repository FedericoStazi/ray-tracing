//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_SURFACE_H
#define CPP_GRAPHICS_SURFACE_H

#include <vector>
#include "../Entity.h"
#include "../Aspect/Aspect.h"
#include "../Light/Light.h"

class Surface : public Entity{

private:

    Aspect aspect;
    std::vector<Vector2> points;

protected:

    Surface(const ReferenceFrame &referenceFrame, const Aspect &aspect);

    void add(const Vector2& point);

public:

    [[nodiscard]] const Aspect &get_aspect() const;

    // object referred coordinates

    virtual UnitVector3 get_normal(const Vector3 & v, float time);

    virtual std::vector<std::pair<float, Surface *>> intersections(const Line & ray, float time);

    virtual float furthest_distance(float time);

};


#endif //CPP_GRAPHICS_SURFACE_H
