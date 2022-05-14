#include "Student.h"

Student::Student()
{
    int tmp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < 10; i++)
    {
        oceny[i] = &tmp[i];
    }
}

Student::Student(const Student &e)
{
    for(int i=0; i < 10; i++)
    {
        oceny[i] = new int(*e.oceny[i]);
    }
}

Student::Student(Student &&e)
{
    for(int i=0; i < 10; i++)
    {
        oceny[i] = e.oceny[i];
    }
        for(int i=0; i < 10; i++)
    {
        e.oceny[i] = nullptr;
    }
}

Student::Student(string imie_nazwisko, string data, string miasto, string ulica, int nr1, int nr2)
{
    set_imie_nazwisko(imie_nazwisko);
    set_data(data);
    set_adres(miasto, ulica, nr1, nr2);
    int tmp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i=0; i < 10; i++)
    {
        oceny[i] = &tmp[i];
    }
}

Student::~Student(){}

void Student::set_ocena(int przedmiot, int ocena)
{
    if(ocena < 2 || ocena > 5 || przedmiot < 0 || przedmiot >= 10)
    {
        cout<<"Podana przez ciebie ocena lub identyfikator przedmiotu jest niepoprawny."<<endl;
    }
    else
    {
        oceny[przedmiot] = new int(ocena);
    }   
}

int Student::get_ocena(int przedmiot)
{
    if(*oceny[przedmiot] == 0)
    {
        cout<<"Brak oceny."<<endl;
    }
    return *oceny[przedmiot];
}

void Student::get_oceny()
{
    for(int i = 0; i < 10; i++)
    {
        if(*oceny[i] > 2 && *oceny[i] <= 5)
        {
            cout<<"Przedmiot nr "<<i+1<<": "<<*oceny[i]<<endl;
        }
        else
        {
            cout<<"Przedmiot nr "<<i+1<<": Brak oceny."<<endl;
        }
        
    }
}

void Student::przedstaw()
{
    cout<<"Imie i nazwisko: "<<get_imie_nazwisko()<<endl;
    cout<<"Data urodzenia: "<<get_data()<<endl;
    cout<<"Adres zamieszkania: "<<get_adres().get_miasto()<<", "<<get_adres().get_ulica()<<" "<<get_adres().get_numer_budynku()<<"/"<<get_adres().get_numer_mieszkania()<<endl;
    cout<<"Oceny:"<<endl;
    get_oceny();
}