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

Color Scene::surface_color(Scene::IntersectionData intersection_data, const Line& ray, int reflections, double time) const {

    //Color result(0.2, 0.2, 0.2); //TODO
    Color result(0, 0, 0); //TODO

    Vector3 intersection_point = ray.get_location(time).add(ray.get_direction(time).scale(intersection_data.distance - Constants::eps));

    for (Light * light : lights) {

        Line light_line = Line(
                TimeVector3(intersection_point),
                TimeUnitVector3(UnitVector3(light->get_reference_frame().get_location(time).subtract(intersection_point).normalized())));

        double light_distance = ray_intersection(light_line, time).distance;

        UnitVector3 surface_normal =
                intersection_data.object->get_reference_frame().unit_from_ref_frame(
                        intersection_data.surface->get_normal(
                            intersection_data.object->get_reference_frame().to_ref_frame(intersection_point, time), time), time);

        UnitVector3 viewer_vector = UnitVector3(ray.get_location(time).subtract(intersection_point).normalized());

        if (intersection_point.distance(light->get_reference_frame().get_location(time)) < light_distance) {

            // diffuse shading
            result = result.add(light->get_intensity().scale(
                    intersection_data.surface->get_aspect().get_k_diffuse().scale(
                         light_line.get_direction(time).dot_product(surface_normal))));

            // specular reflection
            result = result.add(light->get_intensity().scale(
                    intersection_data.surface->get_aspect().get_k_specular().scale(
                            pow(
                                    surface_normal.reflect(light_line.get_direction(time)).dot_product(viewer_vector),
                                    intersection_data.surface->get_aspect().get_roughness()))));

            /*
            // mirror reflection
            result = result.add(intersection_data.surface->get_aspect().get_k_mirror().scale(
                    cast_ray(
                            Line(intersection_point, UnitVector3(surface_normal.reflect(light_line.get_direction(time)))),
                            reflections - 1,
                            time
                    )));
            */

        }

    }

    return result;

}

Color Scene::cast_ray(const Line& ray, int reflections, double time) const {

    IntersectionData closest_intersection = ray_intersection(ray, time);

    return (closest_intersection.surface == nullptr || reflections == 0) ? Color() : surface_color(closest_intersection, ray, reflections, time);
}


