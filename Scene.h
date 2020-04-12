//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_SCENE_H
#define CPP_GRAPHICS_SCENE_H

#include <set>
#include "Object/Object.h"
#include "Light/Light.h"
#include "Utils/Geometry/Line.h"
#include "Aspect/Color.h"
#include "Object/Object.h"
#include "Utils/BaseGeometry/Constants.h"

class Scene {

private:

    std::set<Object*> objects;
    std::set<Light*> lights;

    class IntersectionData {
    public:
        double distance;
        Surface * surface;
        Object * object;

        IntersectionData() : distance(Constants::inf), surface(nullptr), object(nullptr) {}
        IntersectionData(double distance, Surface *surface, Object *object) : distance(distance), surface(surface), object(object) {}
    };

    [[nodiscard]] IntersectionData ray_intersection(const Line& ray, double time) const;
    [[nodiscard]] Color surface_color(IntersectionData intersection_data, const Vector3& intersection_point, double time) const;

public:
    void add(Object* object);

    void add(Light* light);

    [[nodiscard]] Color cast_ray(const Line& ray, double time) const;

};


#endif //CPP_GRAPHICS_SCENE_H
