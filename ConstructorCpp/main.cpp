#include "JednorekiBandyta.h"
#include <ctime>

//pkt. 14
void funkcja_przyjmujaca_przez_wartosc(JednorekiBandyta Bandyta)
{
    cout<<"funkcja przez wartosc"<<endl;
}

//pkt. 18
//Aby wywołał się konstruktor konwertujący należy podać jedynie wartość.
void funkcja_przyjmujaca_przez_stala_ref_R_value(const JednorekiBandyta &Bandyta)
{
    cout<<"const R-value"<<endl;
}

//pkt. 20
//Nie udało mi się wywołać kontruktora w żaden sposób.
void funkcja_zwykle_R_value(JednorekiBandyta &Bandyta)
{
    cout<<"zwykle R-value"<<endl;
}

//pkt. 22
//Działa przy podaniu samej wartości.
void L_value(JednorekiBandyta &&Bandyta)
{
    cout<<"L-value ref"<<endl;
}

//pkt. 26
//Aby móc korzystać z klasy Logger w klasie JednorekiBandyta musiałem ustawić dzidziczoną klasę Logger na public.

//pkt. 29
//Aby parametr debug typu bool działał należało tego bool'a ustawić jako true.

//pkt. 32
//Wielodziedziczenie może sprawić, że jedna klasa istnieje kilkukrotnie w jednym drzewie dziedziczenia (taki kod się nie skompiluje).
//W Javie wielodziedziczenie zastąpione jest implementowaniem jednej klasie wielu interfejsów.
int main()
{   
    srand(time(NULL));
    JednorekiBandyta Bandyta;
    Bandyta.log("WITAJ!");
    Bandyta.set_koszt_1_gry(5);
    Bandyta.set_procent_do_puli_nagrod(50);
    Bandyta.set_prawdopodobienstwo_wygranej(0.1);
    Bandyta.set_pula_nagrod(0);
    Bandyta.set_liczba_rozegranych_gier(0);
    Bandyta.set_nickname("noname");
    Bandyta.set_saldo_gracza(0);
    Bandyta.set_wygrane_gry(0);
    string y;
    int opcja;
    double x;
    bool petla = true;
    cout<<"Podaj nickname: ";
    cin>>y;
    Bandyta.set_nickname(y);
    while(petla)
    {   cout<<"_____________________________________________________\n"
        <<"1.Doladuj saldo. \n2.Zagraj. \n3.Ustal koszt 1 gry. \n4.Pokaz koszt 1 gry. \n5.Ustal procent przekazywany do puli nagrod." 
        <<"\n6.Pokaz procent przekazywany do puli nagrod. \n7.Ustal szanse na wygrana. \n8.Pokaz szanse na wygrana. \n9.Pokaz pule nagrod."
        <<"\n10.Pokaz liczbe rozegranych gier. \n11.Pokaz liczbe wygranych gier \n12.Pokaz saldo. \n13.Wyjdz. \nTwoj wybor: ";  
        cin>>opcja;
        switch (opcja)
        {
            case 1:
                cout<<"Ile chcesz wplacic?\n";
                cout<<"Podaj wartosc: "<<endl;
                cin>>x;
                Bandyta.set_saldo_gracza(x);
                break;
            case 2:
                if (Bandyta.get_saldo_gracza()-Bandyta.get_koszt_1_gry() >= 0)
                {
                    Bandyta.graj();
                }
                else
                {
                    cout<<"Za malo srodkow na koncie."<<endl;
                }
                break;
            case 3:
                cout<<"Ustaw koszt 1 gry: "<<endl;
                cin>>x;
                Bandyta.set_koszt_1_gry(x);
                break;
            case 4:
                cout<<"Cena jednej gry wynosi: "<<Bandyta.get_koszt_1_gry()<<endl;
                break;
            case 5:
                cout<<"Ustal procent przekazywany do puli nagrod: "<<endl;
                cin>>x;
                Bandyta.set_procent_do_puli_nagrod(x);
                break;
            case 6:
                cout<<"Procent przekazywany do puli nagrod wynosi: "<<Bandyta.get_procent__do_puli_nagrod()<<" %"<<endl;
                break;
            case 7:
                cout<<"Ustal szanse na wygrana: "<<endl;
                cin>>x;
                Bandyta.set_prawdopodobienstwo_wygranej(x);
                break;
            case 8:
                cout<<"Pokaz szanse na wygrana: "<<Bandyta.get_prawdopodobienstwo_wygranej()*100<<" %"<<endl;
                break;
            case 9:
                cout<<"Pula nagrod wynosi: "<<Bandyta.get_pula_nagrod()<<endl;
                break;
            case 10:
                cout<<"Liczba rozegranych gier wynosi: "<<Bandyta.get_liczba_rozegranych_gier()<<endl;
                break;
            case 11:
                cout<<"Liczba wygranych gier wynosi: "<<Bandyta.get_wygrane_gry()<<endl;
                break;
            case 12:
                cout<<"Twoje saldo wynosi: "<<Bandyta.get_saldo_gracza()<<endl;
                break;
            case 13:
                cout<<Bandyta.get_nickname()<<" - Wygrales "<<Bandyta.get_wygrane_gry()<<" gier. Wyplaciles: "<<Bandyta.get_saldo_gracza()<<endl;
                petla = false;
                break;
            default:
                cout<<"Zly input. Sprobuj jeszcze raz."<<endl;
            
        }
    }
}