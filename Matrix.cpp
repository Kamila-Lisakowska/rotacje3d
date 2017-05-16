//
// Created by kamila on 05.05.17.
//
#include <cmath>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() {
    matrix[0][0]=1; matrix[0][1]=0;
    matrix[1][0]=0; matrix[1][1]=1;
}

void Matrix::LoadMatrixOX(double angle)  { //przyjmuje kąt w stopniach
    angle =( angle * M_PI ) / 180.0f;
    matrix[0][0]=cos(angle);
    matrix[0][1]=sin(angle);
    matrix[1][0]=-sin(angle);
    matrix[1][1]=cos(angle);

}

double Matrix::getMatrix(int a, int b) {
    return matrix[a][b];
}

void Matrix::ShowMatrix() const {
    for (int i = 0; i <3; i++) {
        for (int j = 0; j <3; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

}

Matrix Matrix::operator * (Matrix b) {
    Matrix result;
    result.matrix[0][0]=matrix[0][0]*b.matrix[0][0]+matrix[1][0]*b.matrix[0][1]+matrix[2][0]*b.matrix[2][0];
    result.matrix[1][0]=matrix[0][0]*b.matrix[1][0]+matrix[1][0]*b.matrix[1][1]+matrix[2][0]*b.matrix[1][2];
    result.matrix[2][0]=matrix[0][0]*b.matrix[2][0]+matrix[1][0]*b.matrix[2][1]+matrix[2][0]*b.matrix[2][2];

    result.matrix[0][1]=matrix[0][1]*b.matrix[0][0]+matrix[1][1]*b.matrix[0][1]+matrix[2][1]*b.matrix[0][2];
    result.matrix[1][1]=matrix[0][1]*b.matrix[1][0]+matrix[1][1]*b.matrix[1][1]+matrix[2][1]*b.matrix[1][2];
    result.matrix[2][1]=matrix[0][1]*b.matrix[2][0]+matrix[1][1]*b.matrix[2][1]+matrix[2][1]*b.matrix[2][2];

    result.matrix[0][2]=matrix[0][2]*b.matrix[0][0]+matrix[1][2]*b.matrix[0][1]+matrix[2][2]*b.matrix[0][2];
    result.matrix[1][2]=matrix[0][2]*b.matrix[1][0]+matrix[1][2]*b.matrix[1][1]+matrix[2][2]*b.matrix[1][2];
    result.matrix[2][2]=matrix[0][2]*b.matrix[2][0]+matrix[1][2]*b.matrix[2][1]+matrix[2][2]*b.matrix[2][2];
    return result;
}

void Matrix::Zero() {
    matrix[0][0]=1; matrix[0][1]=0;
    matrix[1][0]=0; matrix[1][1]=1;

}

