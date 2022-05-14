#pragma once
#include "Osoba.h"

class Pracownik: public Osoba
{
    private:
        int *przedmioty[10];
    public:
        //konstruktory
        Pracownik();
        Pracownik(const Pracownik &e);
        Pracownik(Pracownik &&e);
        Pracownik(string imie_nazwisko, string data, string miasto, string ulica, int nr1, int nr2);
        //destruktor
        ~Pracownik();
        //gettery i settery
        void set_przedmiot(int przedmiot);
        void del_przedmiot(int przedmiot);
        bool czy_uczy(int przedmiot);
        void przedstaw();
};