//
// Created by kamila on 05.05.17.
//
#include <cmath>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() {
    matrix[0][0]=0; matrix[0][1]=0; matrix[0][2]=0;
    matrix[1][0]=0; matrix[1][1]=0; matrix[1][2]=0;
    matrix[2][0]=0; matrix[2][1]=0; matrix[2][2]=0;
}

void Matrix::LoadMatrixOX(double angle)  { //przyjmuje kąt w stopniach
    angle =( angle * M_PI ) / 180.0f;
    matrix[0][0]=cos(angle);
    matrix[0][1]=sin(angle);
    matrix[0][2]=0;
    matrix[1][0]=-sin(angle);
    matrix[1][1]=cos(angle);
    matrix[1][2]=0;
    matrix[2][0]=0;
    matrix[2][1]=0;
    matrix[2][2]=1;
}

void Matrix::LoadMatrixOY(double angle) { // źle
    angle =( angle * M_PI ) / 180.0f;
    matrix[0][0]=cos(angle);
    matrix[0][1]=0;
    matrix[0][2]=-sin(angle);
    matrix[1][0]=0;
    matrix[1][1]=1;
    matrix[1][2]=0;
    matrix[2][0]=sin(angle);//
    matrix[2][1]=0;
    matrix[2][2]=cos(angle);
}

void Matrix::LoadMatrixOZ(double angle) {
    angle =( angle * M_PI ) / 180.0f;
    matrix[0][0]=1;
    matrix[0][1]=0;
    matrix[0][2]=0;
    matrix[1][0]=0;
    matrix[1][1]=cos(angle);
    matrix[1][2]=sin(angle);
    matrix[2][0]=0;//
    matrix[2][1]=-sin(angle);
    matrix[2][2]=cos(angle);
}

