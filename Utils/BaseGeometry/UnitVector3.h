//
// Created by federico on 10/04/2020.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"
#ifndef CPP_GRAPHICS_UNITVECTOR3_H
#define CPP_GRAPHICS_UNITVECTOR3_H


#include "Vector3.h"

class UnitVector3 : public Vector3 {

public:

    struct NonUnitException: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The vector does not have magnitude 1";
        }
    };

    explicit UnitVector3(const Vector3& v);
    UnitVector3(double x, double y, double z);
    UnitVector3();

    Vector3 reflect(const Vector3& v);

};

#endif //CPP_GRAPHICS_UNITVECTOR3_H

#pragma clang diagnostic pop