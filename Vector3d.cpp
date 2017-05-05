//
// Created by kamila on 05.05.17.
//

#include "Vector3d.h"
using namespace std;

Vector3d::Vector3d() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}
Vector3d::Vector3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector3d::getX() const {
    return x;
}

void Vector3d::setX(double x) {
    Vector3d::x = x;
}

double Vector3d::getY() const {
    return y;
}

void Vector3d::setY(double y) {
    Vector3d::y = y;
}

double Vector3d::getZ() const {
    return z;
}

void Vector3d::setZ(double z) {
    Vector3d::z = z;
}

std::istream& operator >> (std::istream &Strm, Vector3d &Wek){
    double a;
    Strm>>a;
    if (Strm.eof())
        return Strm;
    Wek.setX(a);
    Strm>>a;
    if (Strm.eof())
        return Strm;
    Wek.setY(a);
    Strm>>a;
    if (Strm.eof())
        return Strm;
    Wek.setZ(a);
}

std::ostream& operator << (std::ostream &Strm, const Vector3d &Wek){
    cout<<Wek.getX();
    cout<<" ";
    cout<<Wek.getY();
    cout<<" ";
    cout<<Wek.getZ();
    cout << "\n";
    return Strm;
}