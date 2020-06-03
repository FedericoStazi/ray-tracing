//
// Created by federico on 10/04/2020.
//

#ifndef CPP_GRAPHICS_BASIS_H
#define CPP_GRAPHICS_BASIS_H


#include "../TimeGeometry/TimeUnitVector3.h"

class Basis {

private:

    TimeUnitVector3 x_base, y_base, z_base;
    bool _check_orthonormal = false; // if true checks if basis is orthonormal every time

    [[nodiscard]] bool _orthonormal(double time) const;

public:

    struct NonOrthonormalBases: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The bases are not orthonormal";
        }
    };

    Basis(TimeUnitVector3 xBase, TimeUnitVector3 yBase, TimeUnitVector3 zBase);
    Basis();

    [[nodiscard]] UnitVector3 get_x_base(double time) const;
    [[nodiscard]] UnitVector3 get_y_base(double time) const;
    [[nodiscard]] UnitVector3 get_z_base(double time) const;

    Basis rotate(double x, double y, double z, double time);

};


#endif //CPP_GRAPHICS_BASIS_H
