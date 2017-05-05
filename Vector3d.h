//
// Created by kamila on 05.05.17.
//

#ifndef ROTACJE3D_VECTOR3D_H
#define ROTACJE3D_VECTOR3D_H

#include <iostream>

class Vector3d {
private:
    double x;
    double y;
    double z;

public:
    Vector3d ();
    Vector3d(double x, double y, double z);
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);


};

std::istream& operator >> (std::istream &Strm, Vector3d &Wek);
std::ostream& operator << (std::ostream &Strm, const Vector3d &Wek);

#endif //ROTACJE3D_VECTOR3D_H
