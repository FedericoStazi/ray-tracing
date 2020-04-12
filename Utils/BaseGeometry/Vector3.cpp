//
// Created by federico on 09/04/2020.
//

#include <cmath>
#include "Vector3.h"
#include "../Matrix.h"
#include "../TimeGeometry/TimeVector3.h"
#include "Constants.h"

Vector3::Vector3(double x, double y, double z) : _x(x), _y(y), _z(z) {}

Vector3::Vector3() : Vector3(1, 0, 0) {}

double Vector3::x() const {
    return _x;
}

double Vector3::y() const {
    return _y;
}

double Vector3::z() const {
    return _z;
}

Vector3 Vector3::set_x(double x) const {
    return Vector3(x, y(), z());
}

Vector3 Vector3::set_y(double y) const {
    return Vector3(x(), y, z());
}

Vector3 Vector3::set_z(double z) const {
    return Vector3(x(), y(), z);
}

double Vector3::magnitude() const {
    return std::sqrt(x() * x() + y() * y() + z() * z());
}

Vector3 Vector3::normalized() const {
    return scale(1 / magnitude());
}

bool Vector3::equals(const Vector3 &v) const {
    return subtract(v).magnitude() < Constants::eps;
}

Vector3 Vector3::scale(double k) const {
    return Vector3(x() * k, y() * k, z() * k);
}

Vector3 Vector3::add(const Vector3& other) const {
    return Vector3(x() + other.x(), y() + other.y(), z() + other.z());
}

double Vector3::dot_product(const Vector3& other) const {
    return x() * other.x() + y() * other.y() + z() * other.z();
}

Vector3 Vector3::cross_product(const Vector3& other) const {
    return Vector3(
            y() * other.z() - z() * other.y(),
            z() * other.x() - x() * other.z(),
            x() * other.y() - y() * other.x()
    );
}

double Vector3::distance(const Vector3& other) const {
    return scale(-1).add(other).magnitude();
}

Vector3 Vector3::rotate(double x, double y, double z) const {

    std::vector<std::vector<double>> v = {{this->x()}, {this->y()}, {this->z()}};
    return
        Matrix::rotation(x)
        .multiply(Matrix::rotation(y))
        .multiply(Matrix::rotation(z))
        .multiply(Matrix(v)).to_Vector();

}

std::string Vector3::to_string() const {
    return "("+std::to_string(x())+","+std::to_string(y())+","+std::to_string(z())+")";
}

Vector3 Vector3::subtract(const Vector3& v) const {
    return add(v.scale(-1));
}
