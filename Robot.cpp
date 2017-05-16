//
// Created by kamila on 04.05.17.
//

#include "Robot.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Robot::Robot() {
    coordinate[0]= Vector2d (0.0f,0.0f);
    coordinate[1]= Vector2d(20.0f,5.0f);
    coordinate[2]= Vector2d(0.0f,10.0f);
}

void Robot::move(Vector2d vector) {

    for (int i = 0; i < 3; i++) {
        coordinate[i].setX(coordinate[i].getX() + vector.getX());
        coordinate[i].setY(coordinate[i].getY() + vector.getY());
    }
}


void Robot::saveToFile() {
    file.open("cuboid.dat", ios::out | ios::trunc);
    if (file.good()){
        for (int i = 0; i < 3; i++) {
            file << coordinate[i].getX() << " ";
            file << coordinate[i].getY() << " ";
            file << "\n";
        }
        file << coordinate[0].getX() << " ";
        file << coordinate[0].getY() << " ";
    }
    else
        cout << "Brak dostepu do pliku" << endl;
    file.close();

}

double Robot::getCoordinate(int a, int b) const {
    if(b==0)return coordinate[a].getX();
    if(b==1)return coordinate[a].getY();
}


void Robot::setCoordinate(int a, int b, double value) {
    if(b==0)coordinate[a].setX(value);
    if(b==1)coordinate[a].setY(value);
}






