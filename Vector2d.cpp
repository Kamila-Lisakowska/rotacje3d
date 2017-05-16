//
// Created by kamila on 05.05.17.
//

#include "Vector2d.h"
using namespace std;

Vector2d::Vector2d() {
    howManyCreated++;
    howManyNow++;
    this->x = 0.0;
    this->y = 0.0;
}
Vector2d::Vector2d(double x, double y) {
    howManyCreated++;
    howManyNow++;
    this->x = x;
    this->y = y;
}

double Vector2d::getX() const {
    return x;
}

void Vector2d::setX(double x) {
    this->x = x;
}

double Vector2d::getY() const {
    return y;
}

void Vector2d::setY(double y) {
    this->y = y;
}

Vector2d::~Vector2d() {
    howManyNow--;
}


std::istream& operator >> (std::istream &Strm, Vector2d &Wek){
    double a;
    Strm>>a;
    if (Strm.eof())
        return Strm;
    Wek.setX(a);
    Strm>>a;
    if (Strm.eof())
        return Strm;
    Wek.setY(a);
}

std::ostream& operator << (std::ostream &Strm, const Vector2d &Wek){
    cout<<Wek.getX();
    cout<<" ";
    cout<<Wek.getY();
    cout << "\n";
    return Strm;
}