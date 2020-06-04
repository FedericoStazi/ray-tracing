//
// Created by federico on 10/04/2020.
//

#ifndef CPP_GRAPHICS_BASIS_H
#define CPP_GRAPHICS_BASIS_H


#include "../TimeGeometry/TimeUnitVector3.h"

class Basis {

public:

    struct NonOrthonormalBases: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The bases are not orthonormal";
        }
    };

    Basis rotate(float x, float y, float z, float time) const;

    ///Express basis as a matrix whose columns are x,y,z
    ///Can be used for faster change of basis
    [[nodiscard]] Eigen::Matrix3f inline get_matrix(float time) const;

    [[nodiscard]] UnitVector3 inline get_x_base(float time) const {
        if (!_check_orthonormal or Basis::_is_orthonormal(time))
            return x_base.time(time);
        else
            throw Basis::NonOrthonormalBases();
    }

    [[nodiscard]] UnitVector3 inline get_y_base(float time) const {
        if (!_check_orthonormal or Basis::_is_orthonormal(time))
            return y_base.time(time);
        else
            throw Basis::NonOrthonormalBases();
    }
    [[nodiscard]] UnitVector3 inline get_z_base(float time) const {
        if (!_check_orthonormal or Basis::_is_orthonormal(time))
            return z_base.time(time);
        else
            throw Basis::NonOrthonormalBases();
    }

    Basis(TimeUnitVector3 xBase, TimeUnitVector3 yBase, TimeUnitVector3 zBase);

    Basis() : Basis(
        TimeUnitVector3(1, 0, 0),
        TimeUnitVector3(0, 1, 0),
        TimeUnitVector3(0, 0, 1)
        ) {}

private:

    [[nodiscard]] bool inline _is_orthonormal(float time) const;

    TimeUnitVector3 x_base, y_base, z_base;
    Eigen::Matrix3f basis_matrix;

    // parameters impacting performance
    bool _check_orthonormal = false; // if true checks if basis is orthonormal every time
    bool _no_time = false; //if true can use the same basis matrix every time

};


#endif //CPP_GRAPHICS_BASIS_H
