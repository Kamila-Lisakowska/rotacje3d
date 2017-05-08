#include <iostream>
#include <fstream>
#include <iomanip>
#include "Vector3d.h"
#include "Cuboid.h"
#include "lacze_do_gnuplota.h"

using namespace std;

void menu()
{
    cout << "o - obrot prostpadłościanu o zadany kat" << "\n";
    cout << "p - przesuniecie prostopadłościanu o zadany wektor" << "\n";
    cout << "w - wyswietlenie wspolrzednych wierzcholkow" << "\n";
    cout << "s - sprawdzenie dlugosci przeciwleglych bokow" << "\n";
    cout << "g - wyswietlenie prostopadłościanu"<<"\n";
    cout << "m - wyswietl menu" << "\n";
    cout << "k - koniec dzialania programu" << "\n";
}
int main() {
    char choice='m';
    bool end=true;
    Vector3d wek;
    Cuboid cub;
    PzG::LaczeDoGNUPlota  Lacze;
    fstream file;


    menu();
    cout<<"blabla"<<endl;
    while (end!=false) {
        cout << "\n";
        cout << "Twoj wybor? (m - menu) >";
        cin >> choice;
        switch (choice) {
            case 'm':
                menu();
                break;
            case 'k':
                end = false;
                break;
            case 'o': //dopisać
                break;
            case 'p': //brak zabezpieczen jesli wpisane litery
                cout << "Wprowadz wspolrzedne wektora translacji w postaci trzech liczb\n"
                        "tzn. wspolrzednych: x y z"<<"\n";
                cin >> wek;
                cub.Move(wek);
                break;
            case 'w':
                cub.ViewCoordinate();
                break;
            case 's':
                cub.Sides();
                break;
            case 'g':
                file.open("cuboid.dat",ios::out | ios::trunc);
                if(file.good()==true)
                    cub.SaveToFile(file);
                else
                    cout<<"Brak dostepu do pliku"<<endl;
                file.close();
                    //wyświetlanie
                Lacze.DodajNazwePliku("cuboid.dat",PzG::RR_Ciagly,1);
                Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
                Lacze.ZmienTrybRys(PzG::TR_3D);
                Lacze.UstawZakresZ(-35,35);
                Lacze.UstawZakresY(-35,35);
                Lacze.UstawZakresX(-35,35);
                Lacze.Rysuj();
                break;

        }
    }
    return 0;
}