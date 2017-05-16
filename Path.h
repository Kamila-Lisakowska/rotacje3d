//
// Created by kamila on 15.05.17.
//

#ifndef ROBOT_PATH_H
#define ROBOT_PATH_H
/*!
 * \file  Path.hh
 *
 *  Plik zawiera definicję klasy realizującej przesunięcia robota.
 */

#include "Vector2d.h"
#include <vector>
#include <fstream>
using namespace std;
class Path {
private:
/*!         \brief
         * Inicjalizuje obiekt.
         */
    vector<Vector2d> vectors;
public:
    /*!         \brief
         * ZWraca wartość wektora
         */
    const vector<Vector2d> &getVectors() const;
    /*!         \brief
        * Tworzy nowy wektor przesunięcia.
        */
    void addVector(Vector2d vector);
    /*!         \brief
        * Rysuje ściezkę.
        */
    void move(Vector2d vector);
    /*!         \brief
        * Zapisuje nowe zmienne ścieżki do pliku
        */
    void saveToFile();
};


#endif //ROBOT_PATH_H
