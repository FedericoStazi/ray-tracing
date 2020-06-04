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
#include "Utils/BaseGeometry/Values.h"

/// Class representing the scene
/// Holds all the entities in the scene (objects, cameras, lights...)
class Scene {

public:

    void add(Object *object) {
        objects.insert(object);
    }

    void add(Light *light) {
        lights.insert(light);
    }

    /// Casts a ray in the scene, and returns the resulting color
    [[nodiscard]] Color cast_ray(const Line& ray, int reflections, float time) const;

private:

    Color ambient_intensity = Color(0.05, 0.05, 0.05);

    std::set<Object*> objects;
    std::set<Light*> lights;

    class IntersectionData {
    public:
        float distance;
        Surface * surface;
        Object * object;

        IntersectionData() : distance(Values::inf), surface(nullptr), object(nullptr) {}
        IntersectionData(float distance, Surface *surface, Object *object) : distance(distance), surface(surface), object(object) {}
    };

    [[nodiscard]] IntersectionData ray_intersection(const Line& ray, float time) const;
    [[nodiscard]] Color surface_color(IntersectionData intersection_data, const Line& ray, int reflections, float time) const;

};


#endif //CPP_GRAPHICS_SCENE_H
