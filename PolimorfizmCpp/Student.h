#pragma once
#include "Osoba.h"

class Student: public Osoba
{
    private:
        int* oceny[10];
    public:
        //konstruktory
        Student();
        Student(const Student &e);
        Student(Student &&e);
        Student(string imie_nazwisko, string data, string miasto, string ulica, int nr1, int nr2);
        //destruktor
        ~Student();
        //gettery i settery
        void set_ocena(int przedmiot, int ocena);
        int get_ocena(int przedmiot);
        void get_oceny();
        void przedstaw();
};