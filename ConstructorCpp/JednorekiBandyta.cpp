#include <iostream>
#include "JednorekiBandyta.h"
#include "Logger.h"

//konstruktor domyślny
JednorekiBandyta :: JednorekiBandyta()
    : koszt_1_gry(nullptr), 
    procent_do_puli_nagrod(nullptr), 
    pula_nagrod(nullptr), 
    liczba_rozegranych_gier(nullptr), 
    saldo_gracza(nullptr), 
    wygrane_gry(nullptr), 
    nazwa_uzytkownika(nullptr), 
    prawdopodobienstwo_wygranej(nullptr)
    {
        reset();
        std::cout<<"konstruktor domyslny\n"<<endl;
    }

//destruktor
JednorekiBandyta :: ~JednorekiBandyta()
{
    if (koszt_1_gry != nullptr) delete koszt_1_gry;
    if (procent_do_puli_nagrod != nullptr) delete procent_do_puli_nagrod;
    if (pula_nagrod != nullptr) delete pula_nagrod;
    if (liczba_rozegranych_gier != nullptr) delete liczba_rozegranych_gier;
    if (saldo_gracza != nullptr) delete saldo_gracza;
    if (wygrane_gry != nullptr) delete wygrane_gry;
    if (nazwa_uzytkownika != nullptr) delete nazwa_uzytkownika;
    if (prawdopodobienstwo_wygranej != nullptr) delete prawdopodobienstwo_wygranej;
    std::cout<<"destruktor" <<endl;
}
//konstruktor kopiujący
JednorekiBandyta :: JednorekiBandyta(const JednorekiBandyta &kopia)
{
    koszt_1_gry = new double(*kopia.koszt_1_gry);
    procent_do_puli_nagrod = new double(*kopia.procent_do_puli_nagrod);
    pula_nagrod = new double(*kopia.pula_nagrod);
    liczba_rozegranych_gier = new int(*kopia.liczba_rozegranych_gier);
    saldo_gracza = new double(*kopia.saldo_gracza);
    wygrane_gry = new int(*kopia.wygrane_gry);
    nazwa_uzytkownika = new string(*kopia.nazwa_uzytkownika);
    prawdopodobienstwo_wygranej = new double(*kopia.prawdopodobienstwo_wygranej);
    std::cout<<"konstruktor kopiujacy"<<endl;
}
//konstruktor przenoszący
JednorekiBandyta :: JednorekiBandyta(JednorekiBandyta &&kopia)
{
    koszt_1_gry = kopia.koszt_1_gry;
    procent_do_puli_nagrod = kopia.procent_do_puli_nagrod;
    pula_nagrod = kopia.pula_nagrod;
    liczba_rozegranych_gier = kopia.liczba_rozegranych_gier;
    saldo_gracza = kopia.saldo_gracza;
    wygrane_gry = kopia.wygrane_gry;
    nazwa_uzytkownika = kopia.nazwa_uzytkownika;
    prawdopodobienstwo_wygranej = kopia.prawdopodobienstwo_wygranej;
    kopia.koszt_1_gry = nullptr;
    kopia.procent_do_puli_nagrod = nullptr;
    kopia.pula_nagrod = nullptr;
    kopia.liczba_rozegranych_gier = nullptr;
    kopia.saldo_gracza = nullptr;
    kopia.wygrane_gry = nullptr;
    kopia.nazwa_uzytkownika = nullptr;
    kopia.prawdopodobienstwo_wygranej = nullptr;
    std::cout<<"konstruktor przenoszacy"<<endl;
}
//konstruktor konwertujący
JednorekiBandyta :: JednorekiBandyta(double konwerter)
{
    pula_nagrod = new double(konwerter);

    procent_do_puli_nagrod = nullptr;
    koszt_1_gry = nullptr;
    liczba_rozegranych_gier = nullptr;
    saldo_gracza = nullptr;
    wygrane_gry = nullptr;
    nazwa_uzytkownika = nullptr;
    prawdopodobienstwo_wygranej = nullptr;
    std::cout<<"konstruktor konwertujacy"<<endl;
}

//gettery
double JednorekiBandyta :: get_koszt_1_gry()
{
    start();
    return *koszt_1_gry;
    stop();
}

double JednorekiBandyta :: get_procent__do_puli_nagrod()
{
    start();
    return *procent_do_puli_nagrod;
    stop();
}

double JednorekiBandyta :: get_pula_nagrod()
{
    start();
    return *pula_nagrod;
    stop();
}

int JednorekiBandyta :: get_liczba_rozegranych_gier()
{
    start();
    return *liczba_rozegranych_gier;
    stop();
}

double JednorekiBandyta :: get_saldo_gracza()
{
    start();
    return *saldo_gracza;
    stop();
}

int JednorekiBandyta :: get_wygrane_gry()
{
    start();
    return *wygrane_gry;
    stop();
}

string JednorekiBandyta :: get_nickname()
{
    start();
    return *nazwa_uzytkownika;
    stop();
}

double JednorekiBandyta :: get_prawdopodobienstwo_wygranej()
{
    start();
    return *prawdopodobienstwo_wygranej;
    stop();
}


//settery
void JednorekiBandyta :: set_koszt_1_gry(double wartosc)
{
    if (wartosc > 0)
    {
        start();
        koszt_1_gry =  new double(wartosc);
        stop();
    }
    else
    {
        cout<<"Koszt jednej gry musi wynosic wiecej niz 0.";
    }
    
}
void JednorekiBandyta :: set_procent_do_puli_nagrod(double wartosc)
{
    if (wartosc >= 1 && wartosc <= 70)
    {
        start();
        procent_do_puli_nagrod = new double(wartosc);
        stop();
    }
    else
    {
        cout<<"Nalezy podac wartosc z przedzialu <1;70>."<<endl;
    }
    
}

void JednorekiBandyta :: set_prawdopodobienstwo_wygranej(double wartosc)
{
    if (wartosc >= 0.1 && wartosc <= 0.2)
    {
        start();
        prawdopodobienstwo_wygranej = new double(wartosc);
        stop();
    }
    else
    {
        cout<<"Nalezy podac wartosc z przedzialu <0.1;0.2>."<<endl;
    }
    
}

void JednorekiBandyta :: set_saldo_gracza(double wartosc)
{
    if (wartosc >= 0)
    {
        start();
        saldo_gracza = new double(wartosc);
        stop();
    }
    else
    {
        cout<<"Nie udalo sie wplacic srodkow. Sprobuj jeszcze raz."<<endl;
    }
    
}

void JednorekiBandyta :: set_nickname(string wartosc)
{
    start();
    nazwa_uzytkownika = new string(wartosc);
    stop();
}

void JednorekiBandyta :: set_pula_nagrod(double wartosc)
{
    start();
    pula_nagrod = new double(wartosc);
    stop();
}

void JednorekiBandyta :: set_liczba_rozegranych_gier(int wartosc)
{
    start();
    liczba_rozegranych_gier = new int(wartosc);
    stop();
}

void JednorekiBandyta :: set_wygrane_gry(int wartosc)
{
    start();
    wygrane_gry = new int(wartosc);
    stop();
}

// funkcja gry w jednorekiego bandyte
void JednorekiBandyta :: graj()
{   
    start();
    *saldo_gracza -= *koszt_1_gry;
    *liczba_rozegranych_gier += 1;
    *pula_nagrod += *koszt_1_gry * (*procent_do_puli_nagrod/100);
    if (rand()%2 < *prawdopodobienstwo_wygranej)
    {
        *wygrane_gry += 1;
        *saldo_gracza += *pula_nagrod;
        cout<<"Wygrales: "<<*pula_nagrod<<endl;
        *pula_nagrod = 0;
    } 
    else
    {
        cout<<"Przegrales! Sprobuj jeszcze raz."<<endl;
    }
    stop();
}