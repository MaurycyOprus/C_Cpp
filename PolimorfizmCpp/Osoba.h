#pragma once
#include <iostream>
#include "Adres.h"
using namespace std;

class Osoba
{
    private:
        string* imie_nazwisko;
        string* data;
        Adres adres;
    public:
        //konstruktory
        Osoba();
        Osoba(const Osoba &e);
        Osoba(Osoba &&e);
        Osoba(string imie_nazwisko, string data, string miasto, string ulica, int nr1, int nr2);
        //destruktor
        virtual ~Osoba();
        //gettery i settery
        void set_imie_nazwisko(string input);
        string get_imie_nazwisko();
        void set_data(string data);
        string get_data();
        void set_adres(string miasto, string ulica, int nr1, int nr2);
        Adres get_adres();
        virtual void przedstaw();
};