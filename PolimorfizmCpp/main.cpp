#include "Osoba.h"
#include "Student.h"
#include "Pracownik.h"
#include "FabrykaOsob.h"
#include "FabrykaStudentow.h"
#include "FabrykaPracownikow.h"
#include <string>
#include <map>
#include <vector>
using namespace std;

void foo(Osoba &e)
{
    e.przedstaw();
}

void bar(Osoba* e)
{
    e->przedstaw();
}

int main()
{
    Osoba Kox1;
    Kox1.set_imie_nazwisko("Alphonso Davies");
    Kox1.set_data("02/11/2000");
    Kox1.set_adres("Monachium", "Traminer", 7, 23);

    Student Kox2;
    Kox2.set_imie_nazwisko("Maurycy Oprus");
    Kox2.set_data("11/01/2000");
    Kox2.set_adres("Poznan", "Rozana", 18, 33);
    Kox2.set_ocena(0, 1);
    Kox2.set_ocena(2, 4);
    Kox2.set_ocena(9, 3);
    Kox2.set_ocena(15, 3);

    Pracownik Kox3;
    Kox3.set_imie_nazwisko("Leonardo DiCaprio");
    Kox3.set_data("11/11/1974");
    Kox3.set_adres("Los Angeles", "Main St", 9100, 4);
    Kox3.set_przedmiot(1);
    Kox3.set_przedmiot(5);
    Kox3.set_przedmiot(28);

    foo(Kox1);
    bar(&Kox1);

    foo(Kox2);
    bar(&Kox2);

    foo(Kox3);
    bar(&Kox3);

    //zad.12
    //dziala tylko funckja przedstaw z klasy Osoba
    
    //zad.14
    //działa odpowiednia funkcja przedstaw z odpowiedniej klasy

    //zad.15
    Pracownik *p1 = new Pracownik;
    Osoba *o1 = static_cast<Osoba *>(p1);
    Osoba *o2 = static_cast<Pracownik *>(o1);
    //powinno uzyc sie ta sama klase

    Osoba *o3 = new Osoba;
    Pracownik *p2 = static_cast<Pracownik *>(o3);

    //zad.16
    Pracownik *p3 = new Pracownik;
    Osoba *o4 = dynamic_cast<Osoba *>(p3);
    //Pracownik *p4 = dynamic_cast<Osoba *>(o4);
    //Nie mozna uzyc wartosci Osoba* do zainicjowania typu Pracownik*.
    Pracownik *p4 = dynamic_cast<Pracownik *>(o4);

    //zad.17
    Osoba *o5 = new Osoba;
    Pracownik *p5 = dynamic_cast<Pracownik *>(o5);
    if(p5 == nullptr)
    {
        cout<<"Blad rzutowania!"<<endl;
    }
    else
    {
        p5->przedstaw();
    }

    map<string, FabrykaOsob*> m;
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();

    vector<Osoba *> tablicaOsob;
    string currentCommand;

    //glowna petla 
    while(true)
    {
        cout<<"Wybierz polecenie:\n pracownik\n student\n przedstaw\n wyjscie\nWpisz jedno z powyzszych:\n";
        cin>>currentCommand;
        if(currentCommand == "student" || currentCommand == "pracownik")
        {
            tablicaOsob.push_back(m[currentCommand]->utworz());
        }
        else if(currentCommand == "przedstaw")
        {
            for(int i = 0; i < tablicaOsob.size(); i++)
            {
                tablicaOsob[i]->przedstaw();
            }
        }
        else
        {
            break;
        }   
    }
}