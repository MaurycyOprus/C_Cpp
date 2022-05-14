#include "FabrykaStudentow.h"

Student* FabrykaStudentow::utworz()
{
    string imie_nazwisko, data, miasto, ulica;
    string imie, nazwisko;
    int numer_budynku, numer_mieszkania;
    cout<<"__________________"<<endl;
    cout<<"Podaj dane osoby: "<<endl;
    cout<<"Imie: ";
    cin>>imie;
    cout<<"Nazwisko: ";
    cin>>nazwisko;
    cout<<"Data urodzenia (format dd/mm/yyyy): ";
    cin>>data;
    cout<<"Miasto: ";
    cin>>miasto;
    cout<<"Ulica: ";
    cin>>ulica;
    cout<<"Numer budynku: ";
    cin>>numer_budynku;
    cout<<"Numer mieszkania: ";
    cin>>numer_mieszkania;
    cout<<"__________________"<<endl;
    imie_nazwisko = imie + " " + nazwisko;
    return new Student(imie_nazwisko, data, miasto, ulica, numer_budynku, numer_mieszkania);
}