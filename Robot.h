//
// Created by kamila on 04.05.17.
//

#ifndef ROTACJE3D_CUBOID_H
#define ROTACJE3D_CUBOID_H

#include <iostream>
#include "Vector2d.h"
#include "Path.h"

using namespace std;
/*!
     * \brief Zestaw informacji dotyczący klasy Robot
     *
     * Klasa modeluje zestaw informacji dotyczący robota.
     * Boki robota są Vectorami 2d.
     */
class Robot{
private:

    Vector2d coordinate[3];
    fstream file;
public:
/*!
 * \brief Konstruktor robota
*/
Robot ();
    /*!
   * \brief Wyonuje rych robota (bez rysowania ścieżki
  */
void move(Vector2d vector);
    /*!
 * \brief Zapisuje do pliku współrzędne robota
*/
void saveToFile ();
    /*!
 * \brief Getter robota
*/
double getCoordinate(int a, int b) const;
    /*!
 * \brief Setter robota
*/
void setCoordinate(int a, int b,double value);
};


#endif //ROTACJE3D_CUBOID_H
