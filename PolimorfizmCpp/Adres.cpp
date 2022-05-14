#include "Adres.h"

void Adres::set_adres(string city, string street, int nr1, int nr2)
{
    miasto = new string(city);
    ulica = new string(street);
    numer_budynku = new int(nr1);
    numer_mieszkania = new int(nr2);
}

string Adres::get_miasto()
{
    return *miasto;
}

string Adres::get_ulica()
{
    return* ulica;
}

int Adres::get_numer_budynku()
{
    return* numer_budynku;
}

int Adres::get_numer_mieszkania()
{
    return* numer_mieszkania;
}