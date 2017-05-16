//
// Created by kamila on 04.05.17.
//

#ifndef ROTACJE3D_CUBOID_H
#define ROTACJE3D_CUBOID_H

#include <iostream>
#include "Vector2d.h"
#include "Matrix.h"
#include "Path.h"

using namespace std;

class Robot{
private:
    Vector2d coordinate[3];
    fstream file;
public:
    Robot ();
    void move(Vector2d vector);
    void Multiplication (Matrix m);
    void saveToFile ();
    double getCoordinate(int a, int b) const;
    void setCoordinate(int a, int b,double value);
};


#endif //ROTACJE3D_CUBOID_H
