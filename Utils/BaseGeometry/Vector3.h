//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_VECTOR3_H
#define CPP_GRAPHICS_VECTOR3_H

#include <string>
#include "../../Aspect/Color.h"
#include <Eigen/Core>
#include <Eigen/Geometry>

/// represents a 3d vector
class Vector3 : public Eigen::Vector3f {

    using Eigen::Vector3f::Vector3f;

public:

    [[nodiscard]] inline bool equals(const Vector3& v) const {
        return (*this - v).norm() < Values::eps;
    };

    [[nodiscard]] inline float distance(const Vector3& v) const {
        return (*this - other).norm();
    };

    [[nodiscard]] Vector3 rotate(float x, float y, float z) const;

    /// set z to 0
    [[nodiscard]] inline Vector3 zero_z() const {
        return Vector3(x(), y(), 0);
    };

    [[nodiscard]] inline std::string to_string() const{
        return "("+std::to_string(x())+","+std::to_string(y())+","+std::to_string(z())+")";
    }

    Vector3() : Eigen::Vector3f(0, 0, 0) {}

};
#endif //CPP_GRAPHICS_VECTOR3_H


