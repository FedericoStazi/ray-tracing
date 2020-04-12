//
// Created by federico on 09/04/2020.
//

#ifndef CPP_GRAPHICS_MATRIX_H
#define CPP_GRAPHICS_MATRIX_H


#include <exception>
#include <vector>
#include "BaseGeometry/Vector3.h"

struct matrix_size_mismatch: public std::exception {
    [[nodiscard]] const char * what () const noexcept override {
        return "Can't perform operation on these matrices";
    }
};

struct matrix_out_of_bounds: public std::exception {
    [[nodiscard]] const char * what () const noexcept override {
        return "Can't access element, indices out of bounds";
    }
};

class Matrix {
private:
    int height, width;
    std::vector<std::vector<double>> elements;

public:

    Matrix(int height, int width);
    explicit Matrix(std::vector<std::vector<double>> & elements);

    double at(int i, int j);

    Matrix multiply(Matrix other);

    static Matrix x_rotation(double a);
    static Matrix y_rotation(double a);
    static Matrix z_rotation(double a);

    Vector3 to_Vector();

    static Matrix rotation(double a);
};


#endif //CPP_GRAPHICS_MATRIX_H
