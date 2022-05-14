#include "Pracownik.h"

Pracownik::Pracownik()
{
    int tmp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 10; i++)
    {
        przedmioty[i] = &tmp[i];
    }
}

Pracownik::Pracownik(const Pracownik &e)
{
    for (int i = 0; i < 10; i++)
    {
        przedmioty[i] = new int(*e.przedmioty[i]);
    }
}

Pracownik::Pracownik(Pracownik &&e)
{
    for (int i = 0; i < 10; i++)
    {
        przedmioty[i] = e.przedmioty[i];
    }
    for (int i = 0; i < 10; i++)
    {
        e.przedmioty[i] = nullptr;
    }
}

Pracownik::Pracownik(string imie_nazwisko, string data, string miasto, string ulica, int nr1, int nr2)
{
    set_imie_nazwisko(imie_nazwisko);
    set_data(data);
    set_adres(miasto, ulica, nr1, nr2);
    int tmp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 10; i++)
    {
        przedmioty[i] = &tmp[i];
    }
}

Pracownik::~Pracownik(){}

void Pracownik::set_przedmiot(int index)
{
    przedmioty[index] = new int(1);
}

void Pracownik::del_przedmiot(int index)
{
    if(*przedmioty[index] == 1)
    {
        *przedmioty[index] = 0;
    }
}

bool Pracownik::czy_uczy(int index)
{
    if(*przedmioty[index] == int(1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Pracownik::przedstaw()
{
    cout<<"Imie i nazwisko: "<<get_imie_nazwisko()<<endl;
    cout<<"Data urodzenia: "<<get_data()<<endl;
    cout<<"Adres zamieszkania: "<<get_adres().get_miasto()<<", "<<get_adres().get_ulica()<<" "<<get_adres().get_numer_budynku()<<"/"<<get_adres().get_numer_mieszkania()<<endl;
    cout<<"Prowadzone przedmioty: "<<endl;
    for (int i = 0; i < 10; i++)
    {
        if(czy_uczy(i) == true)
        {
            if(i == 0)
            {
                cout<<"- programowanie obiektowe"<<endl;
            }
            if(i == 1)
            {
                cout<<"- podstawy techniki cyfrowej"<<endl;
            }
            if(i == 2)
            {
                cout<<"- fizyka dla informatykow"<<endl;
            }
            if(i == 3)
            {
                cout<<"- metody probabilistyczne"<<endl;
            }
            if(i == 4)
            {
                cout<<"- programowanie systemowe i wspolbiezne"<<endl;
            }
            if(i == 5)
            {
                cout<<"- jezyk angielski"<<endl;
            }
            if(i == 6)
            {
                cout<<"- podstawy automatyki"<<endl;
            }
            if(i == 7)
            {
                cout<<"- podstawy robotyki"<<endl;
            }
            if(i == 8)
            {
                cout<<"- optymalizacja kombinatoryczna"<<endl;
            }
            if(i == 0)
            {
                cout<<"- programowanie deklaratywne"<<endl;
            }
        }
    } 
}