//
// Created by federico on 10/04/2020.
//

#ifndef CPP_GRAPHICS_BASIS_H
#define CPP_GRAPHICS_BASIS_H


#include "../TimeGeometry/TimeUnitVector3.h"

class Basis {

private:

    TimeUnitVector3 x_base, y_base, z_base;
    Eigen::Matrix3f basis_matrix;

    bool _check_orthonormal = false; // if true checks if basis is orthonormal every time
    bool _no_time = false; //if true can use the same basis matrix every time

    [[nodiscard]] bool _orthonormal(float time) const;

public:

    struct NonOrthonormalBases: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The bases are not orthonormal";
        }
    };

    Basis(TimeUnitVector3 xBase, TimeUnitVector3 yBase, TimeUnitVector3 zBase);
    Basis();

    [[nodiscard]] UnitVector3 get_x_base(float time) const;
    [[nodiscard]] UnitVector3 get_y_base(float time) const;
    [[nodiscard]] UnitVector3 get_z_base(float time) const;

    Basis rotate(float x, float y, float z, float time);

    Eigen::Matrix3f get_matrix(float time) const;

};


#endif //CPP_GRAPHICS_BASIS_H
