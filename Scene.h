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

class Scene {

private:

    std::set<Object*> objects;
    std::set<Light*> lights;

public:

    void add(Object* object);
    void add(Light* light);

    [[nodiscard]] Color cast_ray(const Line& ray, double time) const;

};


#endif //CPP_GRAPHICS_SCENE_H
