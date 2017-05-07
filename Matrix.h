//
// Created by kamila on 05.05.17.
//

#ifndef ROTACJE3D_MATRIX_H
#define ROTACJE3D_MATRIX_H

#include <iostream>
#include <cmath>


class Matrix {
//private:
public:
    double matrix [3][3];
public:
    Matrix();
    void LoadMatrixOX (double angle);
    void LoadMatrixOY (double angle);
    void LoadMatrixOZ (double angle);
};


#endif //ROTACJE3D_MATRIX_H
