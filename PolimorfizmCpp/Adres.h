#pragma once
#include <iostream>
using namespace std;

class Adres
{
    private:
        string* miasto;
        string* ulica;
        int* numer_budynku;
        int* numer_mieszkania;
    public:
        void set_adres(string miasto, string ulica, int nr_budynku, int nr_mieszkania);
        string get_miasto();
        string get_ulica();
        int get_numer_budynku();
        int get_numer_mieszkania();
};