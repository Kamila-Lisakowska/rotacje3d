//
// Created by kamila on 04.05.17.
//

#include "Cuboid.h"
#include <cmath>
using namespace std;

Cuboid::Cuboid() {
    coordinate[0][0]=1.0f;  coordinate[0][1]=1.0f; coordinate[0][2]=0.0f;
    coordinate[1][0]=11.0f; coordinate[1][1]=1.0f; coordinate[1][2]=0.0f;
    coordinate[2][0]=1.0f;  coordinate[2][1]=6.0f; coordinate[2][2]=0.0f;
    coordinate[3][0]=11.0f; coordinate[3][1]=6.0f; coordinate[3][2]=0.0f;
    coordinate[4][0]=1.0f;  coordinate[4][1]=6.0f; coordinate[4][2]=7.0f;
    coordinate[5][0]=11.0f; coordinate[5][1]=6.0f; coordinate[5][2]=7.0f;
    coordinate[6][0]=1.0f;  coordinate[6][1]=1.0f; coordinate[6][2]=7.0f;
    coordinate[7][0]=11.0f; coordinate[7][1]=1.0f; coordinate[7][2]=7.0f;
}

void Cuboid::Sides() const {
    double a;
    double b;
    a=sqrt(abs(pow((coordinate[0][0]-coordinate[1][0]),2)+pow((coordinate[0][1]-coordinate[1][1]),2)+pow((coordinate[0][2]-coordinate[1][2]),2)));
    b=sqrt(abs(pow((coordinate[6][0]-coordinate[7][0]),2)+pow((coordinate[6][1]-coordinate[7][1]),2)+pow((coordinate[6][2]-coordinate[7][2]),2)));
    if (a==b)
        cout<<"Wybrane boki sa sobie rowne"<<"\n";
    else
        cout<<"Wybrane boki nie sa sobie rowne"<<"\n";
}
