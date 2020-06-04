//
// Created by federico on 10/04/2020.
//

#pragma clang diagnostic push
#ifndef CPP_GRAPHICS_UNITVECTOR3_H
#define CPP_GRAPHICS_UNITVECTOR3_H


#include "Vector3.h"
#include "Values.h"

class UnitVector3 : public Vector3 {

public:

    struct NonUnitException: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The vector does not have magnitude 1";
        }
    };

    /// reflect vector v with respect to this unit vector
    [[nodiscard]] inline Vector3 reflect(const Vector3 &v) const {
        return *this * (2 * (dot(v))) - v;
    }

    UnitVector3(const Vector3& v) : Vector3(v) {
        if (std::abs(v.norm() - 1) > Values::eps)
            throw NonUnitException();
    }

    UnitVector3(float x, float y, float z) : UnitVector3(Vector3(x, y, z)) {}

    UnitVector3() : UnitVector3(Vector3()) {}

};

#endif //CPP_GRAPHICS_UNITVECTOR3_H
