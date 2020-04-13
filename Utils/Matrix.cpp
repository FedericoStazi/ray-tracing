//
// Created by federico on 09/04/2020.
//

#include <cmath>
#include "Matrix.h"

Matrix::Matrix(int height, int width) : height(height), width(width) {

    elements = std::vector<std::vector<double>>(height);
    for (auto & row : elements)
        row = std::vector<double>(width, 0);

}

Matrix::Matrix(std::vector<std::vector<double>> & elements) : elements(elements) {

    height = elements.size();
    width = elements[0].size();

}

Matrix Matrix::multiply(Matrix other) {

    if (width != other.height)
        throw matrix_size_mismatch();

    Matrix result(height, other.width);

    for (int i=0; i<result.height; i++)
        for (int j=0; j<result.width; j++)
            for (int k=0; k < width; k++)
                result.elements[i][j] += at(i, k) * other.at(k, j);

    return result;

}

double Matrix::at(int i, int j) {

    if (i < 0 or i >= height or j < 0 or j >= width)
        throw matrix_out_of_bounds();

    return elements[i][j];
}

Matrix Matrix::rotation(double a) {
    std::vector<std::vector<double>> mat = {
            {std::cos(a), -std::sin(a)},
            {std::sin(a), std::cos(a)}
    };
}

Matrix Matrix::x_rotation(double a) {
    std::vector<std::vector<double>> mat = {
            {1, 0, 0},
            {0, std::cos(a), -std::sin(a)},
            {0, std::sin(a), std::cos(a)}
    };
    return Matrix(mat);
}

Matrix Matrix::y_rotation(double a) {
    std::vector<std::vector<double>> mat = {
            {std::cos(a), 0, std::sin(a)},
            {0, 1, 0},
            {-std::sin(a), 0, std::cos(a)}
    };
    return Matrix(mat);
}

Matrix Matrix::z_rotation(double a) {
    std::vector<std::vector<double>> mat = {
            {std::cos(a), -std::sin(a), 0},
            {std::sin(a), std::cos(a), 0},
            {0, 0, 1}
    };
    return Matrix(mat);
}

Vector3 Matrix::to_Vector() {
    if (height == 3 and width == 1)
        return Vector3(at(0, 0), at(1, 0), at(2, 0));
    else if (height == 4 and width == 1)
        return Vector3(at(0, 0) / at(3, 0), at(1, 0) / at(3, 0), at(2, 0) / at(3, 0));
    else
        return Vector3();
}

