//
// Created by kamila on 05.05.17.
//

#ifndef ROTACJE3D_MATRIX_H
#define ROTACJE3D_MATRIX_H

#include <iostream>
#include <cmath>


class Matrix {
//private:
private:
    double matrix [3][3];
public:
    Matrix();
    void LoadMatrixOX (double angle);
    void LoadMatrixOY (double angle);
    void LoadMatrixOZ (double angle);
    double getMatrix (int a, int b);
    void ShowMatrix () const;
    Matrix operator * (Matrix b);
    void setMatrix(double x[3][3])
    {
        for (int i = 0; i <3; i++) {
            for (int j = 0; j <3; j++) {
                matrix[i][j]=x[i][j];
            }
        }
    }
    void Zero ();
};


#endif //ROTACJE3D_MATRIX_H
