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

Scene::IntersectionData Scene::ray_intersection(const Line &ray, double time) const {

    IntersectionData closest_intersection;

    for (Object* object : objects)
        for (std::pair<double, Surface * > intersection : object->intersections(ray, time))
            if (intersection.first < closest_intersection.distance and intersection.first > 0)
                closest_intersection = IntersectionData(intersection.first, intersection.second, object);

    return closest_intersection;

}

Color Scene::surface_color(Scene::IntersectionData intersection_data, const Line& ray, int reflections, double time) const {

    Color result = ambient_intensity.scale(intersection_data.surface->get_aspect().get_k_diffuse());

    Vector3 intersection_point = ray.evaluate(intersection_data.distance - Constants::eps, time);

    for (Light * light : lights) {

        Line light_line = Line::between_points(intersection_point, light->get_reference_frame().get_location(time));

        double light_distance = ray_intersection(light_line, time).distance;

        UnitVector3 surface_normal =
                intersection_data.object->get_reference_frame().unit_from_ref_frame(
                        intersection_data.surface->get_normal(
                            intersection_data.object->get_reference_frame().to_ref_frame(intersection_point, time), time), time);

        UnitVector3 viewer_vector = UnitVector3(ray.get_direction(time).scale(-1));

        if (intersection_point.distance(light->get_reference_frame().get_location(time)) < light_distance) {

            // diffuse shading
            result = result.add(light->get_intensity().scale(
                    intersection_data.surface->get_aspect().get_k_diffuse().scale(
                         std::abs(light_line.get_direction(time).dot_product(surface_normal)))));

            // specular reflection
            result = result.add(light->get_intensity().scale(
                    intersection_data.surface->get_aspect().get_k_specular().scale(
                            pow(
                                    std::max(0.0, surface_normal.reflect(light_line.get_direction(time)).dot_product(viewer_vector)),
                                    intersection_data.surface->get_aspect().get_roughness()))));

            // mirror reflection
            if (!intersection_data.surface->get_aspect().get_k_mirror().is_zero())
                result = result.add(intersection_data.surface->get_aspect().get_k_mirror().scale(
                        cast_ray(
                                Line(intersection_point, UnitVector3(surface_normal.reflect(viewer_vector))),
                                reflections - 1,
                                time
                        )));

        }

    }

    return result;

}

Color Scene::cast_ray(const Line& ray, int reflections, double time) const {

    IntersectionData closest_intersection = ray_intersection(ray, time);

    return (closest_intersection.surface == nullptr || reflections == 0) ? Color() : surface_color(closest_intersection, ray, reflections, time);
}


