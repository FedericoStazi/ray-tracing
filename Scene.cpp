//
// Created by federico on 11/04/2020.
//

#include "Scene.h"
#include "Utils/BaseGeometry/Constants.h"

void Scene::add(Object *object) {
    objects.insert(object);
}

void Scene::add(Light *light) {
    lights.insert(light);
}

Color Scene::cast_ray(const Line& ray, double time) const {

    std::pair<double, Color> closest_intersection = {Constants::inf, Color()};

    for (Object* object : objects)
        for (std::pair<double, Color> intersection : object->intersections(ray, time))
            if (intersection.first < closest_intersection.first and intersection.first > 0)
                closest_intersection = intersection;

    return closest_intersection.second;
}
