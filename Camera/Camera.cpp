//
// Created by federico on 11/04/2020.
//

#include "Camera.h"

#include <utility>

Camera::Camera(const ReferenceFrame &referenceFrame, Scene scene) : Entity(referenceFrame), scene(std::move(scene)) {}

ReferenceFrame generate_reference_frame(const Vector3 &position, const Vector3 &point) {

    Vector3 vector_down = Vector3(0, position.y(), 0);

    TimeUnitVector3 z_base = TimeUnitVector3(Line::between_points(point, position).get_direction(0));
    TimeUnitVector3 x_base = TimeUnitVector3(vector_down.cross_product(z_base.time(0)).normalized());
    TimeUnitVector3 y_base = TimeUnitVector3(z_base.time(0).cross_product(x_base.time(0)));

    return ReferenceFrame(TimeVector3(position), Basis(x_base, y_base, z_base));

}

Camera::Camera(const Vector3 &position, const Vector3 &point, Scene scene) : Camera(generate_reference_frame(position, point), std::move(scene)) {}

Scene Camera::get_scene() const {
    return scene;
}

UnitVector3 Camera::get_direction(double time) {
    return UnitVector3(get_reference_frame().get_orientation().get_z_base(time).scale(-1));
}
