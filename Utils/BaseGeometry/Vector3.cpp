//
// Created by federico on 09/04/2020.
//

#include <Eigen/Dense>
#include "Vector3.h"
#include "Values.h"

Vector3 Vector3::rotate(float x, float y, float z) const {

    Eigen::Quaternionf m = Eigen::Quaternionf(
        Eigen::AngleAxisf(x, Eigen::Vector3f::UnitX())
        * Eigen::AngleAxisf(y,   Eigen::Vector3f::UnitY())
        *  Eigen::AngleAxisf(z,  Eigen::Vector3f::UnitZ()));

    return Vector3(m * (*this));

}