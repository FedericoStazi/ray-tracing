//
// Created by federico on 09/04/2020.
//

#include <Eigen/Dense>
#include "Vector3.h"
#include "Constants.h"

bool Vector3::equals(const Vector3 &v) const {
    return (*this - v).norm() < Constants::eps;
}

Vector3 Vector3::rotate(float x, float y, float z) const {

    Eigen::Quaternionf m = Eigen::Quaternionf(
        Eigen::AngleAxisf(x, Eigen::Vector3f::UnitX())
        * Eigen::AngleAxisf(y,   Eigen::Vector3f::UnitY())
        *  Eigen::AngleAxisf(z,  Eigen::Vector3f::UnitZ()));

    return Vector3(m * (*this));

}

std::string Vector3::to_string() const {
    return "("+std::to_string(x())+","+std::to_string(y())+","+std::to_string(z())+")";
}

float Vector3::distance(const Vector3& other) const {
    return (*this - other).norm();
}

/*
Vector3::Vector3(float x, float y, float z) : _x(x), _y(y), _z(z) {}

Vector3::Vector3() : Vector3(1, 0, 0) {}

float Vector3::x() const {
    return _x;
}

float Vector3::y() const {
    return _y;
}

float Vector3::z() const {
    return _z;
}

Vector3 Vector3::set_x(float x) const {
    return Vector3(x, y(), z());
}

Vector3 Vector3::set_y(float y) const {
    return Vector3(x(), y, z());
}

Vector3 Vector3::set_z(float z) const {
    return Vector3(x(), y(), z);
}

float Vector3::norm() const {
    return std::sqrt(x() * x() + y() * y() + z() * z());
}

Vector3 Vector3::normalized() const {
    return scale(1 / norm());
}

bool Vector3::equals(const Vector3 &v) const {
    return subtract(v).magnitude() < Constants::eps;
}

const Vector3 Vector3::scale(float k) const {
    return Vector3(x() * k, y() * k, z() * k);
}

Vector3 Vector3::add(const Vector3& other) const {
    return Vector3(x() + other.x(), y() + other.y(), z() + other.z());
}

float Vector3::dot_product(const Vector3& other) const {
    return x() * other.x() + y() * other.y() + z() * other.z();
}

Vector3 Vector3::cross_product(const Vector3& other) const {
    return Vector3(
            y() * other.z() - z() * other.y(),
            z() * other.x() - x() * other.z(),
            x() * other.y() - y() * other.x()
    );
}

float Vector3::distance(const Vector3& other) const {
    return scale(-1).add(other).magnitude();
}

Vector3 Vector3::rotate(float x, float y, float z) const {

    std::vector<std::vector<float>> v = {{this->x()}, {this->y()}, {this->z()}};
    return
        Matrix::x_rotation(x)
        .multiply(Matrix::y_rotation(y))
        .multiply(Matrix::z_rotation(z))
        .multiply(Matrix(v)).to_Vector();

}

std::string Vector3::to_string() const {
    return "("+std::to_string(x())+","+std::to_string(y())+","+std::to_string(z())+")";
}

Vector3 Vector3::subtract(const Vector3& v) const {
    return add(v.scale(-1));
}
*/