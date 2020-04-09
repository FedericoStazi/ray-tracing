//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_VECTOR3_H
#define CPP_GRAPHICS_VECTOR3_H

#include "TimeFunction.h"

class Vector3 {

private:

    TimeFunction fx, fy, fz;


    class Vector3FixedTime {

    private:

        double _x, _y, _z;

    public:

        Vector3FixedTime(double x, double y, double z);
        Vector3FixedTime();

        [[nodiscard]] double x() const;
        [[nodiscard]] double y() const;
        [[nodiscard]] double z() const;

        [[nodiscard]] Vector3FixedTime set_x(double x) const;
        [[nodiscard]] Vector3FixedTime  set_y(double y) const;
        [[nodiscard]] Vector3FixedTime  set_z(double z) const;

        [[nodiscard]] double magnitude() const;
        [[nodiscard]] Vector3FixedTime normalized() const ;

        [[nodiscard]] Vector3FixedTime scale(double k) const;
        [[nodiscard]] Vector3FixedTime add(Vector3FixedTime v) const;
        [[nodiscard]] Vector3FixedTime subtract(Vector3FixedTime v) const;

        [[nodiscard]] double dot_product(Vector3FixedTime v) const;
        [[nodiscard]] Vector3FixedTime cross_product(Vector3FixedTime v) const;

        [[nodiscard]] double distance(Vector3FixedTime v) const;

        [[nodiscard]] Vector3FixedTime rotate(double x, double y, double z) const;

        [[nodiscard]] std::string to_string() const;

    };


public:

    constexpr static double eps = 1e-8;
    constexpr static double inf = std::numeric_limits<double>::infinity();

    Vector3(TimeFunction x, TimeFunction y, TimeFunction z);
    Vector3(double x, double y, double z);
    Vector3();

    Vector3FixedTime time(double time);

};


#endif //CPP_GRAPHICS_VECTOR3_H
