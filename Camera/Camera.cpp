//
// Created by federico on 11/04/2020.
//

#include "Camera.h"

#include <utility>

Camera::Camera(const ReferenceFrame &referenceFrame, Scene scene) : Entity(referenceFrame), scene(std::move(scene)) {}

Scene Camera::get_scene() const {
    return scene;
}

UnitVector3 Camera::get_direction(double time) {
    return UnitVector3(get_reference_frame().get_orientation().get_z_base(time).scale(-1));
}
