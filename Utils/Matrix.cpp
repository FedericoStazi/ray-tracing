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
            {cos(a), -sin(a)},
            {sin(a), cos(a)}
    };
}

Matrix Matrix::rotation(double x, double y, double z) {

    std::vector<std::vector<double>> mat_x = {
            {1, 0, 0},
            {0, cos(x), -sin(x)},
            {0, sin(x), cos(x)}
    };
    std::vector<std::vector<double>> mat_y = {
            {cos(y), 0, sin(y)},
            {0, 1, 0},
            {-sin(y), 0, cos(y)}
    };
    std::vector<std::vector<double>> mat_z = {
            {cos(z), -sin(z), 0},
            {sin(z), cos(z), 0},
            {0, 0, 1}
    };

    return Matrix(mat_z).multiply(Matrix(mat_y)).multiply(Matrix(mat_x));

}

Vector3 Matrix::to_Vector() {
    if (height == 3 and width == 1)
        return Vector3(at(0, 0), at(1, 0), at(2, 0));
    else if (height == 4 and width == 1)
        return Vector3(at(0, 0) / at(3, 0), at(1, 0) / at(3, 0), at(2, 0) / at(3, 0));
    else
        return Vector3();
}

