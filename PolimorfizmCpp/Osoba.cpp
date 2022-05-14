#include "Osoba.h"

Osoba::Osoba()
: imie_nazwisko(nullptr), 
data(nullptr){}

Osoba::Osoba(const Osoba &e)
{
    imie_nazwisko = new string(*e.imie_nazwisko);
    data = new string(*data);
}

Osoba::Osoba(Osoba &&e)
{
    imie_nazwisko = e.imie_nazwisko;
    data = e.data;
    e.imie_nazwisko = nullptr;
    e.data = nullptr;
}

Osoba::Osoba(string imie_nazwisko, string data, string miasto, string ulica, int nr1, int nr2)
{
    set_imie_nazwisko(imie_nazwisko);
    set_data(data);
    set_adres(miasto, ulica, nr1, nr2);
}

Osoba::~Osoba()
{
    if(imie_nazwisko != nullptr) delete imie_nazwisko;
    if(data != nullptr) delete data;
}

void Osoba::set_imie_nazwisko(string input)
{
    imie_nazwisko = new string(input);
}

string Osoba::get_imie_nazwisko()
{
    return *imie_nazwisko;
}

void Osoba::set_data(string input)
{
    if(input[2] != '/' || input[5] != '/')
    {
        cout<<"Nalezy podac date w formie dd/mm/yyyy."<<endl;
    }
    else
    {
        data = new string(input);
    }
}

string Osoba::get_data()
{
    return *data;
}

void Osoba::set_adres(string miasto, string ulica, int nr1, int nr2)
{
    adres.set_adres(miasto, ulica, nr1, nr2);
}

Adres Osoba::get_adres()
{
    return adres;
}

void Osoba::przedstaw()
{
    cout<<"Imie i nazwisko: "<<get_imie_nazwisko()<<endl;
    cout<<"Data urodzenia: "<<get_data()<<endl;
    cout<<"Adres zamieszkania: "<<adres.get_miasto()<<", "<<adres.get_ulica()<<" "<<adres.get_numer_budynku()<<"/"<<adres.get_numer_mieszkania()<<endl;
}