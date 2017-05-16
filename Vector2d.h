//
// Created by kamila on 05.05.17.
//

#ifndef ROTACJE3D_VECTOR3D_H
#define ROTACJE3D_VECTOR3D_H

#include <iostream>

class Vector2d {
private:
    double x;
    double y;

public:
    Vector2d ();
    static long howManyCreated;
    static long howManyNow;
    virtual ~Vector2d();

    Vector2d(double x, double y);
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);


};

std::istream& operator >> (std::istream &Strm, Vector2d &Wek);
std::ostream& operator << (std::ostream &Strm, const Vector2d &Wek);

#endif //ROTACJE3D_VECTOR3D_H
