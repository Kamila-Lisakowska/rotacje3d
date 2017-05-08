//
// Created by kamila on 08.05.17.
//

#ifndef ROTACJE3D_SCENA_H
#define ROTACJE3D_SCENA_H


#include "Matrix.h"
#include "Cuboid.h"

class Scena {
private:
    Matrix mat;
    Cuboid cub;
public:
    const Matrix &getMat() const;

    void setMat(const Matrix &mat);

    const Cuboid &getCub() const;

    void setCub(const Cuboid &cub);

};


#endif //ROTACJE3D_SCENA_H
