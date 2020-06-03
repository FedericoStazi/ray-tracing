//
// Created by federico on 10/04/2020.
//

#include "Basis.h"

#include <utility>

bool Basis::_orthonormal(double time) const {
    return
        x_base.time(time).cross_product(y_base.time(time)).equals(z_base.time(time)) and
        z_base.time(time).cross_product(x_base.time(time)).equals(y_base.time(time)) and
        y_base.time(time).cross_product(z_base.time(time)).equals(x_base.time(time));
}

Basis::Basis(TimeUnitVector3 xBase, TimeUnitVector3 yBase, TimeUnitVector3 zBase) : x_base(std::move(xBase)),
                                                                                    y_base(std::move(yBase)),
                                                                                    z_base(std::move(zBase)) {}

Basis::Basis() : x_base(TimeUnitVector3(1, 0, 0)),
                 y_base(TimeUnitVector3(0, 1, 0)),
                 z_base(TimeUnitVector3(0, 0, 1)) {}

UnitVector3 Basis::get_x_base(double time) const {
    if (!_check_orthonormal or Basis::_orthonormal(time))
        return x_base.time(time);
    else
        throw Basis::NonOrthonormalBases();
}

UnitVector3 Basis::get_y_base(double time) const {
    if (!_check_orthonormal or Basis::_orthonormal(time))
        return y_base.time(time);
    else
        throw Basis::NonOrthonormalBases();
}

UnitVector3 Basis::get_z_base(double time) const {
    if (!_check_orthonormal or Basis::_orthonormal(time))
        return z_base.time(time);
    else
        throw Basis::NonOrthonormalBases();
}

Basis Basis::rotate(double x, double y, double z, double time) {
    return Basis(
            TimeUnitVector3(get_x_base(time).rotate(x, y, z)),
            TimeUnitVector3(get_y_base(time).rotate(x, y, z)),
            TimeUnitVector3(get_z_base(time).rotate(x, y, z))
            );
}
