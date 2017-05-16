//
// Created by kamila on 15.05.17.
//

#ifndef ROBOT_PATH_H
#define ROBOT_PATH_H


#include "Vector2d.h"
#include <vector>
#include <fstream>
using namespace std;
class Path {
private:
    vector<Vector2d> vectors;
public:
    const vector<Vector2d> &getVectors() const;

public:
    void addVector(Vector2d vector);
    void move(Vector2d vector);
     void saveToFile();
};


#endif //ROBOT_PATH_H
