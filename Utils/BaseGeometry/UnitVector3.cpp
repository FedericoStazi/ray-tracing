//
// Created by federico on 10/04/2020.
//

#include "UnitVector3.h"
#include "Constants.h"

UnitVector3::UnitVector3(const Vector3& v) : Vector3(v) {
    if (std::abs(v.norm() - 1) > Constants::eps)
        throw NonUnitException();
}

UnitVector3::UnitVector3(float x, float y, float z) : UnitVector3(Vector3(x, y, z)) {}

UnitVector3::UnitVector3() : UnitVector3(Vector3()) {}

Vector3 UnitVector3::reflect(const Vector3 &v) {
    return *this * (2 * (dot(v))) - v;
}
