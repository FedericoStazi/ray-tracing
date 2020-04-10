//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_VECTOR3_H
#define CPP_GRAPHICS_VECTOR3_H

#include <string>

class Vector3 {

private:

    double _x, _y, _z;

public:

    Vector3(double x, double y, double z);
    Vector3();

    [[nodiscard]] double x() const;
    [[nodiscard]] double y() const;
    [[nodiscard]] double z() const;

    [[nodiscard]] Vector3 set_x(double x) const;
    [[nodiscard]] Vector3 set_y(double y) const;
    [[nodiscard]] Vector3 set_z(double z) const;

    [[nodiscard]] double magnitude() const;

    [[nodiscard]] Vector3 normalized() const ;

    [[nodiscard]] Vector3 scale(double k) const;
    [[nodiscard]] Vector3 add(const Vector3& v) const;
    [[nodiscard]] Vector3 subtract(const Vector3& v) const;

    [[nodiscard]] double dot_product(const Vector3& v) const;
    [[nodiscard]] Vector3 cross_product(const Vector3& v) const;

    [[nodiscard]] double distance(const Vector3& v) const;

    [[nodiscard]] Vector3 rotate(double x, double y, double z) const;

    [[nodiscard]] virtual std::string to_string() const;

};

#endif //CPP_GRAPHICS_VECTOR3_H
