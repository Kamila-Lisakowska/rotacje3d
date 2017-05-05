//
// Created by kamila on 04.05.17.
//

#ifndef ROTACJE3D_CUBOID_H
#define ROTACJE3D_CUBOID_H

#include <iostream>
#include "Vector3d.h"

using namespace std;

class Cuboid {
private:
    double coordinate[8][3];

public:
    Cuboid ();
    void Sides () const;
    void Move (Vector3d vector3d);
    void ViewCoordinate () const;
};


#endif //ROTACJE3D_CUBOID_H
