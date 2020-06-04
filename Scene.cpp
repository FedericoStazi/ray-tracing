//
// Created by federico on 11/04/2020.
//

#include "Scene.h"
#include "Utils/BaseGeometry/Values.h"

//tests all objects for intersection and returns the closest one
Scene::IntersectionData Scene::ray_intersection(const Line &ray, float time) const {

    IntersectionData closest_intersection;

    for (Object* object : objects)
        for (std::pair<float, Surface * > intersection : object->intersections(ray, time))
            if (intersection.first < closest_intersection.distance and intersection.first > 0)
                closest_intersection = IntersectionData(intersection.first, intersection.second, object);

    return closest_intersection;

}

//returns the color of a surface at a given point, using Phong's illumination model
Color Scene::surface_color(Scene::IntersectionData intersection_data, const Line& ray, int reflections, float time) const {

    Color result = ambient_intensity.scale(intersection_data.surface->get_aspect().get_k_diffuse());

    Vector3 intersection_point = ray.evaluate(intersection_data.distance - 10.0f * Values::eps, time);

    for (Light * light : lights) {

        Line light_line = Line::between_points(intersection_point, light->get_reference_frame().get_location(time));

        float light_distance = ray_intersection(light_line, time).distance;

        UnitVector3 surface_normal =
                intersection_data.object->get_reference_frame().unit_from_ref_frame(
                        intersection_data.surface->get_normal(
                            intersection_data.object->get_reference_frame().to_ref_frame(intersection_point, time), time), time);

        UnitVector3 viewer_vector = static_cast<UnitVector3>(ray.get_direction(time) * (-1));

        if (intersection_point.distance(light->get_reference_frame().get_location(time)) < light_distance) {

            // diffuse shading
            result = result.add(light->get_intensity().scale(
                    intersection_data.surface->get_aspect().get_k_diffuse().scale(
                         std::abs(light_line.get_direction(time).dot(surface_normal)))));

            // specular reflection
            result = result.add(light->get_intensity().scale(
                    intersection_data.surface->get_aspect().get_k_specular().scale(
                            std::pow(
                                    std::max(0.0f, surface_normal.reflect(light_line.get_direction(time)).dot(viewer_vector)),
                                    intersection_data.surface->get_aspect().get_roughness()))));

            // mirror reflection
            if (!intersection_data.surface->get_aspect().get_k_mirror().is_zero())
                result = result.add(intersection_data.surface->get_aspect().get_k_mirror().scale(
                        cast_ray(
                                Line(intersection_point, static_cast<UnitVector3>(surface_normal.reflect(viewer_vector))),
                                reflections - 1,
                                time
                        )));

        }

    }

    return result;

}

Color Scene::cast_ray(const Line& ray, int reflections, float time) const {
    IntersectionData closest_intersection = ray_intersection(ray, time);
    return (closest_intersection.surface == nullptr || reflections == 0) ? Color() : surface_color(closest_intersection, ray, reflections, time);
}
