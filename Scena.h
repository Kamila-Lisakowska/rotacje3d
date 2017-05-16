//
// Created by kamila on 08.05.17.
//

#ifndef ROTACJE3D_SCENA_H
#define ROTACJE3D_SCENA_H


#include "Robot.h"
#include "lacze_do_gnuplota.h"
#include "Path.h"
#include <fstream>
/*!
    * \brief Scena
    *
    *Klasa pozwala na rysowanie ruchu robota oraz ścieżki, którą robot podąża.
    */
class Scena {
private:
    PzG::LaczeDoGNUPlota lacze;
    Robot robot;
    Path path;
    int speed; //speed of rotate and move. This is the same for move and rotate. Rotation's and moving's values are not used.
public:
    /*!
    * \brief Konstruktor Sceny
    */
    Scena();
    /*!
   * \brief Zapisuej współrzędne do pliku oraz rysuje
   */
    void Rysuj();
    /*!
   * \brief Wykonuje ruch robota. Zadaną odległość dzieli poprzez przyjętą prędkość. Przyjmuje wartość o jaką ma być przesunięty robot.
   */
    void go(double howFar);
    /*!
  * \brief Wykonuje obrót robota. Wczytuje kąt w stopniach, o jaki należy obrócić.
  */
    void rotate(double angle);
    /*!
* \brief Zmienia współrzędne robota na współrzędne po obrocie
*/
    void move(Vector2d vector);
    /*!
* \brief Zmienia prędkość ruchu robota
*/
    void setSpeed(int speed);
    /*!
* \brief Przesunięcie sceny, przyjmuje wartości o jakie należy scenę przesunąć w osi OX i OY
*/
    void changeScene(float x, float y);
    /*!
* \brief Przywraca początkowy widok
*/
    void defaultScene();
    /*!
* \brief Przeprowadza translację całej sceny z robotem i ścieżką o zadany wektor
*/
    void translate(Vector2d vector);
};
#endif //ROTACJE3D_SCENA_H
