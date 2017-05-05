#include <iostream>
#include<fstream>
#include <iomanip>

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


    menu();
    while (end!=false) {
        cout << "\n";
        cout << "Twoj wybor? (m - menu) >";
        cin >> choice;
        switch(choice){
        case 'm':
            menu();
        break;
        case 'k':
            end=false;
        break;
    }
    return 0;
}