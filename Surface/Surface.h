//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_SURFACE_H
#define CPP_GRAPHICS_SURFACE_H

#include <vector>
#include "../Entity.h"
#include "../Aspect/Aspect.h"
#include "../Light/Light.h"

///Parent class of all surfaces
///Surfaces can't exist by themselves in the scene, they must be part of an object
///Surfaces have a vector of points, but it may not be needed (e.g. useful for a square, useless for a sphere)
class Surface : public Entity{

public:

    [[nodiscard]] const Aspect &get_aspect() const {
        return aspect;
    }

    ///Normal (in world's coordinates) from point v (in world's coordinates)
    virtual UnitVector3 get_normal(const Vector3 & v, float time) const {
        return get_reference_frame().get_orientation().get_z_base(time);
    }

    ///Intersections with ray (in object's coordinates)
    virtual std::vector<std::pair<float, Surface *>> intersections(const Line & ray, float time);

    /// Furthest distance from surface centre and surface points
    /// Used by object class to improve performance
    virtual float furthest_distance(float time) const {
        float result = 0;
        for (const Vector2& point : points)
            result = std::max(result, point.norm());
        return result;
    }

protected:

    void add(const Vector2& point) {
        points.push_back(point);
    }

    Surface(const ReferenceFrame &referenceFrame, const Aspect &aspect) : Entity(referenceFrame), aspect(aspect) {}

private:

    Aspect aspect;
    std::vector<Vector2> points;

};


#endif //CPP_GRAPHICS_SURFACE_H
