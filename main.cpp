#include <iostream>
#include <fstream>
#include <iomanip>
#include "Vector2d.h"
#include "Robot.h"
#include "lacze_do_gnuplota.h"
#include "Scena.h"

using namespace std;

void menu()
{
    cout<<"Utworzonych wektorow:"<<Vector2d::howManyCreated<<"\n";
    cout<<"Istniejacych wektorow:"<<Vector2d::howManyNow<<"\n";
    cout << "o - obrot robota"<< "\n";
    cout << "x - jazda robota do przodu" << "\n";
    cout << "q - przesuniecie sceny" << "\n";
    cout << "s - zmiana predkosci robota" << "\n";
    cout << "r - powrót do pierwotnego widoku"<<"\n";
    cout << "t - translacja"<<"\n";
    cout << "m - wyswietl menu" << "\n";
    cout << "k - koniec dzialania programu" << "\n";
}

long Vector2d :: howManyCreated ;
long Vector2d :: howManyNow ;
int main() {

    char choice='m';
    bool end=true;
    Scena scena;
    double vekX;
    double vekY;
    double go;
    float howMuchX;
    float howMuchY;
    menu();
    while (end) {
        cout << "\n";
        cout << "Twoj wybor? (m - menu) >";
        cin >> choice;
        double angle = 0;
        switch (choice) {
            case 'm':
                menu();
                break;
            case 'k':
                end = false;
                break;
            case 'o':
                cout << "Podaj kat obrotu w stopniach \n";
                cin >> angle;
                scena.rotate(angle);
                break;
/*            case 'p': //brak zabezpieczen jesli wpisane litery
                cout<<"Wprowadz wspolrzedna x"<<"\n";
                cin >> vekX;
                cout<<"Wprowadz wspolrzedna y"<<"\n";
                cin >> vekY;
                scena.move(Vector2d(vekX,vekY));
                break;*/
            case 'x':
                cout<<"Wprowadz o ile robot ma isc do przodu"<<"\n";
                cin >> go;
                scena.go(go);
                break;
            case 'q':
                cout<<"O ile przesunac scene?\n";

                cout<<"W osi X\n";
                cin>>howMuchX;
                cout<<"W osi Y\n";
                cin>>howMuchY;
                scena.changeScene(howMuchX,howMuchY);
                break;
            case 's':
                cout<<"Podaj predkosc\n";
                cout<<"Podaj wartosc z zakresu 10-50\n";
                int speed;
                cin>>speed;
                scena.setSpeed(speed);
                break;
            case 'r':
                cout<<"Powracam do domyslnego widoku\n";
                scena.defaultScene();
                break;
            case 't':
                cout<<"O ile wykonac translacje?\n";
                cout<<"W osi X\n";
                cin>>howMuchX;
                cout<<"W osi Y\n";
                cin>>howMuchY;
                scena.translate(Vector2d(howMuchX,howMuchY));
            default:
                menu();
                break;
        }
    }
    return 0;
}