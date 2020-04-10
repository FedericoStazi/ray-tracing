//
// Created by federico on 10/04/2020.
//

#include "UnitVector3.h"
#include "../TimeGeometry/TimeVector3.h"

UnitVector3::UnitVector3(const Vector3& v) : Vector3(v) {
    if (std::abs(v.magnitude() - 1) > TimeVector3::eps)
        throw NonUnitException();
}

UnitVector3::UnitVector3(double x, double y, double z) : UnitVector3(Vector3(x, y, z)) {}

UnitVector3::UnitVector3() : UnitVector3(Vector3()) {}
