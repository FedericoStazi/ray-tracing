//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_OBJECT_H
#define CPP_GRAPHICS_OBJECT_H


#include <utility>
#include <vector>
#include <set>
#include "../Aspect/Color.h"
#include "../Utils/Geometry/Line.h"
#include "../Entity.h"
#include "../Surface/Surface.h"
#include "../Light/Light.h"

///Class representing a visible object in the scene composed of multiple Surfaces
class Object : public Entity {

public:

    ///Return all the intersection as k parameter of the ray (world's coordinates) and Surface pointer pair
    std::vector<std::pair<float, Surface *>> intersections(const Line& ray, float time) const;

protected:

    Object(const ReferenceFrame &referenceFrame) : Entity(referenceFrame) {}

    void add(Surface *surface) {
        surfaces.insert(surface);
        furthest_distance = std::max(
            furthest_distance,
            surface->get_reference_frame().get_location(0).norm() + surface->furthest_distance(0)
            );
    }

private:

    std::set<Surface*> surfaces;

    //maximum possible distance of points from this object's centre, used for performance improvement
    //TODO: currently only works for non moving objects
    float furthest_distance = 0;

};


#endif //CPP_GRAPHICS_OBJECT_H
