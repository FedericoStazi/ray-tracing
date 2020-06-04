    //
// Created by federico on 10/04/2020.
//

#include "Basis.h"

#include <utility>

Basis::Basis(TimeUnitVector3 xBase, TimeUnitVector3 yBase, TimeUnitVector3 zBase) : x_base(std::move(xBase)),
                                                                                    y_base(std::move(yBase)),
                                                                                    z_base(std::move(zBase)) {

    auto* x = dynamic_cast<Eigen::Vector3f*>(static_cast<Vector3*>(&xBase));
    auto* y = dynamic_cast<Eigen::Vector3f*>(static_cast<Vector3*>(&yBase));
    auto* z = dynamic_cast<Eigen::Vector3f*>(static_cast<Vector3*>(&zBase));

    if (x and y and z) {
        _no_time = true;
        basis_matrix << *x, *y, *z;
        basis_matrix.transposeInPlace();
    }

}

Basis Basis::rotate(float x, float y, float z, float time) const {
    return Basis(
            static_cast<TimeUnitVector3>(get_x_base(time).rotate(x, y, z)),
            static_cast<TimeUnitVector3>(get_y_base(time).rotate(x, y, z)),
            static_cast<TimeUnitVector3>(get_z_base(time).rotate(x, y, z))
            );
}

//TODO: performance of this is important, maybe improve?
Eigen::Matrix3f Basis::get_matrix(float time) const {
    if (_no_time)
        return basis_matrix;
    else {
        Eigen::Matrix3f time_basis_matrix;

        auto x = static_cast<Eigen::Vector3f>(static_cast<Vector3>(get_x_base(time)));
        auto y = static_cast<Eigen::Vector3f>(static_cast<Vector3>(get_y_base(time)));
        auto z = static_cast<Eigen::Vector3f>(static_cast<Vector3>(get_z_base(time)));

        time_basis_matrix << x, y, z;
        time_basis_matrix.transposeInPlace();

        return time_basis_matrix;
    }
}

bool Basis::_is_orthonormal(float time) const {
    return
        static_cast<Vector3>(x_base.time(time).cross(y_base.time(time))).equals(z_base.time(time)) and
        static_cast<Vector3>(z_base.time(time).cross(x_base.time(time))).equals(y_base.time(time)) and
        static_cast<Vector3>(y_base.time(time).cross(z_base.time(time))).equals(x_base.time(time));
}
