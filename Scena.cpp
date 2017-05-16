//
// Created by kamila on 08.05.17.
//

#include "Scena.h"
#include <chrono>
#include <cmath>

Scena::Scena() {
    lacze.DodajNazwePliku("cuboid.dat", PzG::RR_Ciagly, 1);
    lacze.DodajNazwePliku("cuboid1.dat", PzG::RR_Ciagly, 1);
    lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
    lacze.ZmienTrybRys(PzG::TR_2D);
    lacze.UstawZakresY(-50, 50);
    lacze.UstawZakresX(-50, 50);
    speed=100;
}

void Scena::Rysuj() {
    path.saveToFile();
    robot.saveToFile();
    lacze.Rysuj();
}


void Scena::go(double howFar) {
    double x = (robot.getCoordinate(0, 0) + robot.getCoordinate(2, 0)) / 2;
    double y = (robot.getCoordinate(0, 1) + robot.getCoordinate(2, 1)) / 2;
    Vector2d v = Vector2d(robot.getCoordinate(1, 0) - x, robot.getCoordinate(1, 1) - y);
    v.setX(v.getX() / speed);
    v.setY(v.getY() / speed);
    double r = 0;
    if (v.getX() == 0) r = v.getY();
    else if (v.getY() == 0) r = v.getX();
    else r = sqrt(pow(robot.getCoordinate(1, 0) - x, 2) + pow(robot.getCoordinate(1, 1) - y, 2)) / speed;
    double r1 = 0;
    do {
        if (robot.getCoordinate(1, 0) + v.getX() < lacze.Xmin())
            lacze.UstawZakresX(lacze.Xmin() + v.getX(), lacze.Xmax());
        else if (robot.getCoordinate(1, 0) + v.getX() > lacze.Xmax())
            lacze.UstawZakresX(lacze.Xmin(), lacze.Xmax() + v.getX());
        else if (robot.getCoordinate(1, 1) + v.getY() < lacze.Ymin())
            lacze.UstawZakresY(lacze.Ymin() + v.getY(), lacze.Ymax());
        else if (robot.getCoordinate(1, 1) + v.getY() > lacze.Ymax())
            lacze.UstawZakresY(lacze.Ymin(), lacze.Ymax() + v.getY());

        move(v);
        r1 += r;
        Rysuj();

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        std::chrono::high_resolution_clock::time_point t2;
        std::chrono::duration<double> time_span;
        do {
            t2 = std::chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        } while (time_span.count() < 0.01);
    } while (r1 < howFar);
}

void Scena::rotate(double angle) {
    double centerX = (robot.getCoordinate(0, 0) + robot.getCoordinate(1, 0) + robot.getCoordinate(2, 0)) / 3;
    double centerY = (robot.getCoordinate(0, 1) + robot.getCoordinate(1, 1) + robot.getCoordinate(2, 1)) / 3;
    angle = (angle * M_PI) / 180.0f;
    angle /= speed;
    for (int j = 0; j < speed; j++) {
        double s = sin(angle);
        double c = cos(angle);
        for (int i = 0; i < 3; i++) {
            double x = robot.getCoordinate(i, 0);
            double y = robot.getCoordinate(i, 1);
            x -= centerX;
            y -= centerY;

            // rotate point
            double xnew = x * c - y * s;
            double ynew = x * s + y * c;

            // translate point back:
            x = xnew + centerX;
            y = ynew + centerY;
            path.addVector(
                    Vector2d((robot.getCoordinate(0, 0) + robot.getCoordinate(1, 0) + robot.getCoordinate(2, 0)) / 3,
                             (robot.getCoordinate(0, 1) + robot.getCoordinate(1, 1) + robot.getCoordinate(2, 1)) / 3));
            robot.setCoordinate(i, 0, x);
            robot.setCoordinate(i, 1, y);
            std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            std::chrono::high_resolution_clock::time_point t2;
            std::chrono::duration<double> time_span;
            do {
                t2 = std::chrono::high_resolution_clock::now();
                time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

            } while (time_span.count() < 0.01);
            Rysuj();
        }
    }
}

void Scena::move(Vector2d vector) {
    path.addVector(Vector2d((robot.getCoordinate(0, 0) + robot.getCoordinate(1, 0) + robot.getCoordinate(2, 0)) / 3,
                            (robot.getCoordinate(0, 1) + robot.getCoordinate(1, 1) + robot.getCoordinate(2, 1)) / 3));
    for (int i = 0; i < 3; i++) {
        robot.setCoordinate(i, 0, robot.getCoordinate(i, 0) + vector.getX());
        robot.setCoordinate(i, 1, robot.getCoordinate(i, 1) + vector.getY());
    }

}


void Scena::setSpeed(int speed) {
    if(speed<10||speed>50)cout<<"Podaj wartosc z zakresu 10-50\n";
    else this->speed -= speed;
}

void Scena::changeScene(float x, float y) {
    lacze.UstawZakresX(lacze.Xmin()+x, lacze.Xmax()+x);
    lacze.UstawZakresY(lacze.Ymin()+y, lacze.Ymax()+y);
    Rysuj();
}


void Scena::defaultScene() {
    lacze.UstawZakresX(-50.0f,50.0f);
    lacze.UstawZakresY(-50.0f,50.0f);
    robot=Robot();
    path=Path();
Rysuj();
}

void Scena::translate(Vector2d vector) {
    robot.move(vector);
    path.move(vector);
    lacze.UstawZakresX((float) (lacze.Xmin() + vector.getX()), (float) (lacze.Xmax() + vector.getX()));
    lacze.UstawZakresY((float) (lacze.Ymin() + vector.getY()), (float) (lacze.Ymax() + vector.getY()));
    Rysuj();
}
