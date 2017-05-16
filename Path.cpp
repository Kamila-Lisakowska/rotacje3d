//
// Created by kamila on 15.05.17.
//

#include "Path.h"

const vector<Vector2d> &Path::getVectors() const {
    return vectors;
}

void Path::addVector(Vector2d vector) {
vectors.push_back(vector);
}

void Path::saveToFile() {
    fstream file;
    file.open("cuboid1.dat", ios::out | ios::trunc);
    if (file.good()){
        for (unsigned int i = 0; i < getVectors().size(); i++) {
            file << getVectors().at(i).getX() << " ";
            file << getVectors().at(i).getY() << " ";
            file << "\n";
        }
    }
    else
        cout << "Brak dostepu do pliku" << endl;
   file.close();
}

void Path::move(Vector2d vector) {
    for(unsigned int i=0;i<vectors.size();i++){
        vectors.at(i).setX(vectors.at(i).getX()+vector.getX());
        vectors.at(i).setY(vectors.at(i).getY()+vector.getY());
    }

}
