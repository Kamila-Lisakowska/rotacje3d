//
// Created by kamila on 04.05.17.
//

#include "Cuboid.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
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
    b=sqrt(abs(pow((coordinate[4][0]-coordinate[5][0]),2)+pow((coordinate[4][1]-coordinate[5][1]),2)+pow((coordinate[4][2]-coordinate[5][2]),2)));
    if (a==b)
        cout<<"Wybrane boki sa sobie rowne"<<"\n";
    else
        cout<<"Wybrane boki nie sa sobie rowne"<<"\n";
}

void Cuboid::Move(Vector3d vector3d) {
    for (int i = 0; i < 8; i++){
        int a;
        a=vector3d.getX();
        coordinate[i][0]+=a;
        coordinate[i][1]+=vector3d.getY();
        coordinate[i][2]+=vector3d.getZ();
    }
}

void Cuboid::ViewCoordinate() const {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j <3; j++) {
            cout<<coordinate[i][j]<<" ";
        }
        i++;
        cout<<"\n";
        for (int j = 0; j <3; j++) {
            cout<<coordinate[i][j]<<" ";
        }
        cout<<"\n"<<"\n";
    }
}

void Cuboid::Multiplication(Matrix m)  {
    for (int i = 0; i <8; i++) {
        for (int j = 0; j <3; j++) {
            coordinate[i][j]=m.getMatrix(j,0)*coordinate[i][0]+m.getMatrix(j,1)*coordinate[i][1]+m.getMatrix(j,2)*coordinate[i][2];
        }
    }
}

void Cuboid::SaveToFile(fstream &file) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j <3; j++) {
            file<<coordinate[i][j]<<" ";
        }
        i++;
        file<<"\n";
        for (int j = 0; j <3; j++) {
            file<<coordinate[i][j]<<" ";
        }
        file<<"\n"<<"\n";
    }
        for (int i = 0; i <3; ++i) {
            file<<coordinate[0][i]<<" ";
        }
        file<<"\n";
    for (int i = 0; i <3; ++i) {
        file<<coordinate[1][i]<<" ";
    }

}

double Cuboid::getCoordinate(int a, int b) const {
    return coordinate[a][b];
}

void Cuboid::Rotate(Matrix &m) {
    Matrix robocza, robocza2;
    char a = 'a';
    bool end = true;
    double angle = 0;
    int b = 0;
    cout << "Podaj sekwencje oznaczen osi oraz katy obrotu w stopniach \n";
    while (end != false) {
        cin >> a;
        switch (a) {
            case 'x':
                cin >> angle;
                robocza.LoadMatrixOX(angle);
                robocza2 = robocza2 * robocza;
                break;
            case 'y':
                cin >> angle;
                robocza.LoadMatrixOY(angle);
                robocza2 = robocza2 * robocza;
                break;
            case 'z':
                cin >> angle;
                robocza.LoadMatrixOZ(angle);
                robocza2 = robocza2 * robocza;
                break;
            case '.':
                end = false;
                break;
            default:
                cout << ":( Bledne oznaczenie osi. Dopuszczalne znaki to: x y z .\n :( Sprobuj jeszcze raz. \n";
                robocza2.Zero();
                cin.sync();
                break;

        }
    }
    m = robocza2;
    cout << "Ile razy operacja obrotu ma byc powtorzona? \n";
    end = true;
    while (end != false) {
        cin >> b;
        if (b < 0)
            cout << "Podaj liczbe wieksza od zera  \n";
        else end = false;
    }
    for (int i = 0; i < b; ++i) {
        Multiplication(m);
    }
}

void Cuboid::RepeatRotate(Matrix m) {
    Multiplication(m);
}



