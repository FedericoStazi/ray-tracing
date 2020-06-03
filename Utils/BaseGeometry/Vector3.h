//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_VECTOR3_H
#define CPP_GRAPHICS_VECTOR3_H

#include <string>
#include "../../Aspect/Color.h"
#include <Eigen/Core>
#include <Eigen/Geometry>

class Vector3 : public Eigen::Vector3f {

    using Eigen::Vector3f::Vector3f;

public:

    // TODO this is a test
    Vector3() : EiEigen::Vector3f() {};

    [[nodiscard]] bool equals(const Vector3& v) const;
    [[nodiscard]] float distance(const Vector3& v) const;
    [[nodiscard]] Vector3 rotate(float x, float y, float z) const;
    [[nodiscard]] virtual std::string to_string() const;

};

/*
class Vector3 {

private:

    float _x, _y, _z;

public:

    Vector3(float x, float y, float z);
    Vector3();

    [[nodiscard]] float x() const;
    [[nodiscard]] float y() const;
    [[nodiscard]] float z() const;

    [[nodiscard]] Vector3 set_x(float x) const;
    [[nodiscard]] Vector3 set_y(float y) const;
    [[nodiscard]] Vector3 set_z(float z) const;

    [[nodiscard]] float magnitude() const;
    [[nodiscard]] Vector3 normalized() const ;

    [[nodiscard]] bool equals(const Vector3& v) const;

    [[nodiscard]] const Vector3 scale(float k) const;
    [[nodiscard]] Vector3 add(const Vector3& v) const;
    [[nodiscard]] Vector3 subtract(const Vector3& v) const;

    [[nodiscard]] float dot_product(const Vector3& v) const;
    [[nodiscard]] Vector3 cross_product(const Vector3& v) const;

    [[nodiscard]] float distance(const Vector3& v) const;

    [[nodiscard]] Vector3 rotate(float x, float y, float z) const;

    [[nodiscard]] virtual std::string to_string() const;

};

 */

#endif //CPP_GRAPHICS_VECTOR3_H


