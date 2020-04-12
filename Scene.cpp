//
// Created by federico on 11/04/2020.
//

#include <assert.h>
#include <iostream>
#include "Scene.h"
#include "Utils/BaseGeometry/Constants.h"

void Scene::add(Object *object) {
    objects.insert(object);
}

void Scene::add(Light *light) {
    lights.insert(light);
}

Scene::IntersectionData Scene::ray_intersection(const Line &ray, double time) const {

    IntersectionData closest_intersection;

    for (Object* object : objects)
        for (std::pair<double, Surface * > intersection : object->intersections(ray, time))
            if (intersection.first < closest_intersection.distance and intersection.first > 0)
                closest_intersection = IntersectionData(intersection.first, intersection.second, object);

    return closest_intersection;

}

Color Scene::surface_color(Scene::IntersectionData intersection_data, const Vector3& intersection_point, double time) const {

    double intensity = 0.0; //TODO

    for (Light * light : lights) {

        Line light_line = Line(
                TimeVector3(intersection_point),
                TimeUnitVector3(UnitVector3(light->get_reference_frame().get_location(time).subtract(intersection_point).normalized())));

        double light_distance = ray_intersection(light_line, time).distance;

        UnitVector3 surface_normal =
                intersection_data.object->get_reference_frame().unit_from_ref_frame(
                        intersection_data.surface->get_normal(
                            intersection_data.object->get_reference_frame().to_ref_frame(intersection_point, time), time), time);

        if (intersection_point.distance(light->get_reference_frame().get_location(time)) < light_distance)
            intensity += light->get_intensity() *
                    intersection_data.surface->get_aspect().get_k_diffuse() *
                    light_line.get_direction(time).dot_product(surface_normal);

    }

    return intersection_data.surface->get_aspect().get_color().intensity(intensity);

}

Color Scene::cast_ray(const Line& ray, double time) const {

    IntersectionData closest_intersection = ray_intersection(ray, time);

    return (closest_intersection.surface == nullptr) ? Color() : surface_color(
            closest_intersection,
            ray.get_location(time).add(ray.get_direction(time).scale(closest_intersection.distance - Constants::eps)),
            time
    );
}


