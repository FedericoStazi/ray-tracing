//
// Created by federico on 11/04/2020.
//

#include "Camera.h"

#include <utility>

ReferenceFrame Camera::generate_reference_frame(const Vector3 &position, const Vector3 &point) {

    Vector3 vector_down = Vector3(0, position.y(), 0);

    TimeUnitVector3 z_base = static_cast<TimeUnitVector3>(Line::between_points(point, position).get_direction(0));
    TimeUnitVector3 x_base = static_cast<TimeUnitVector3>(static_cast<Vector3>(vector_down.cross(z_base.time(0)).normalized()));
    TimeUnitVector3 y_base = static_cast<TimeUnitVector3>(static_cast<Vector3>(z_base.time(0).cross(x_base.time(0))));

    return ReferenceFrame(static_cast<TimeVector3>(position), Basis(x_base, y_base, z_base));

}