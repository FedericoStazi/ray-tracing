//
// Created by federico on 09/04/2020.
//

#include "Vector3.h"

#include <utility>
#include <cmath>

Vector3::Vector3(TimeFunction x, TimeFunction y, TimeFunction z) : fx(std::move(x)), fy(std::move(y)), fz(std::move(z)) {}

Vector3::Vector3(double x, double y, double z) : fx(x), fy(y), fz(z) {}

Vector3::Vector3() : Vector3(0, 0, 0) {}

Vector3::Vector3FixedTime Vector3::time(double time) {
    return Vector3::Vector3FixedTime(fx.get(time), fy.get(time), fz.get(time));
}

Vector3::Vector3FixedTime::Vector3FixedTime(double x, double y, double z) : _x(x), _y(y), _z(z) {}

Vector3::Vector3FixedTime::Vector3FixedTime() : _x(0), _y(0), _z(0) {}

double Vector3::Vector3FixedTime::x() const {
    return _x;
}

double Vector3::Vector3FixedTime::y() const {
    return _y;
}

double Vector3::Vector3FixedTime::z() const {
    return _z;
}

Vector3::Vector3FixedTime Vector3::Vector3FixedTime::set_x(double x) const {
    return Vector3::Vector3FixedTime(x, y(), z());
}

Vector3::Vector3FixedTime Vector3::Vector3FixedTime::set_y(double y) const {
    return Vector3::Vector3FixedTime(x(), y, z());
}

Vector3::Vector3FixedTime Vector3::Vector3FixedTime::set_z(double z) const {
    return Vector3::Vector3FixedTime(x(), y(), z);
}

double Vector3::Vector3FixedTime::magnitude() const {
    return std::sqrt(x() * x() + y() * y() + z() * z());
}

Vector3::Vector3FixedTime Vector3::Vector3FixedTime::scale(double k) const {
    return Vector3::Vector3FixedTime(x() * k, y() * k, z() * k);
}

Vector3::Vector3FixedTime Vector3::Vector3FixedTime::normalized() const {

    return scale(1 / magnitude());

}

Vector3::Vector3FixedTime Vector3::Vector3FixedTime::add(Vector3::Vector3FixedTime other) const {
    return Vector3::Vector3FixedTime(x() + other.x(), y() + other.y(), z() + other.z());
}

double Vector3::Vector3FixedTime::dot_product(Vector3::Vector3FixedTime other) const {
    return x() * other.x() + y() * other.y() + z() * other.z();
}

Vector3::Vector3FixedTime Vector3::Vector3FixedTime::cross_product(Vector3::Vector3FixedTime other) const {
    return Vector3::Vector3FixedTime(
            y() * other.z() - z() * other.y(),
            z() * other.x() - x() * other.z(),
            x() * other.y() - y() * other.x()
    );
}

double Vector3::Vector3FixedTime::distance(Vector3::Vector3FixedTime other) const {
    return scale(-1).add(other).magnitude();
}

Vector3::Vector3FixedTime Vector3::Vector3FixedTime::rotate(double x, double y, double z) const {

    return Vector3::Vector3FixedTime();

    /*
    std::vector<std::vector<double>> v = {{x()}, {y()}, {z()}};
    return Matrix::rotation(x, y, z).multiply(Matrix(v)).to_Vector();
*/
}

std::string Vector3::Vector3FixedTime::to_string() const {
    return "("+std::to_string(x())+","+std::to_string(y())+","+std::to_string(z())+")";
}

Vector3::Vector3FixedTime Vector3::Vector3FixedTime::subtract(Vector3::Vector3FixedTime v) const {
    return add(v.scale(-1));
}
