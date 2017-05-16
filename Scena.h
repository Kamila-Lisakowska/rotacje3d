//
// Created by kamila on 08.05.17.
//

#ifndef ROTACJE3D_SCENA_H
#define ROTACJE3D_SCENA_H


#include "Matrix.h"
#include "Robot.h"
#include "lacze_do_gnuplota.h"
#include "Path.h"
#include <fstream>
class Scena {
private:
    PzG::LaczeDoGNUPlota lacze;
    Robot robot;
    Path path;
    int speed;
    vector<Path> objects;
public:
    Scena();
    PzG::LaczeDoGNUPlota getLacze();
    void Rysuj();
    void go(double howFar);
    void rotate(double angle);
    void move(Vector2d vector);
    void setSpeed(int speed);
    void changeScene(float x, float y);
    void defaultScene();
    void translate(Vector2d vector);
};


#endif //ROTACJE3D_SCENA_H
