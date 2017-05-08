//
// Created by kamila on 08.05.17.
//

#include "Scena.h"

const Matrix &Scena::getMat() const {
    return mat;
}

void Scena::setMat(const Matrix &mat) {
    Scena::mat = mat;
}

const Cuboid &Scena::getCub() const {
    return cub;
}

void Scena::setCub(const Cuboid &cub) {
    Scena::cub = cub;
}
