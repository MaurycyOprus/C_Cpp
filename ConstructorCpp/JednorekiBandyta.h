#include <iostream>
#include <time.h>
#include "Logger.h"
#include "Stopper.h"
#ifndef BANDYTA_H
#define BANDYTA_H

using namespace std;

class JednorekiBandyta: public Logger, public Stopper
{
    //atrybuty
    private:
        double* koszt_1_gry;
        double* procent_do_puli_nagrod;
        double* prawdopodobienstwo_wygranej;
        double* pula_nagrod;
        int* liczba_rozegranych_gier;
        string* nazwa_uzytkownika;
        double* saldo_gracza;
        int* wygrane_gry;

    public:
    //konstuktor domyślny
        JednorekiBandyta();
    //destruktor
        ~JednorekiBandyta();
    //konstruktor kopiujący
        JednorekiBandyta(const JednorekiBandyta &kopia);
    //konstruktor przenoszący
        JednorekiBandyta(JednorekiBandyta &&kopia);
    //konstruktor konwertujący
        JednorekiBandyta(double konwerter);
    
    //gettery
        double get_koszt_1_gry();

        double get_procent__do_puli_nagrod();

        double get_pula_nagrod();

        int get_liczba_rozegranych_gier();

        double get_saldo_gracza();

        int get_wygrane_gry();

        string get_nickname();

        double get_prawdopodobienstwo_wygranej();

    // settery
        void set_koszt_1_gry(double wartosc);

        void set_procent_do_puli_nagrod(double wartosc);

        void set_prawdopodobienstwo_wygranej(double wartosc);

        void set_saldo_gracza(double wartosc);

        void set_nickname(string wartosc);

        void set_pula_nagrod(double wartosc);

        void set_liczba_rozegranych_gier(int wartosc);

        void set_wygrane_gry(int wartosc);

    // funkcja gry
        void graj();
};

#endif