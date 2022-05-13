#include <stdio.h>

struct dane
{
    char imie[16];
    char nazwisko[32];
    int nr_startowy;
    float skok_1;
    float skok_2;
    float suma_skokow;
};

void aktualizacja_T1(dane T1[], dane skoczek[], int x)
{
    T1[x] = skoczek[x];
    int a, b;
    for (a = 0; a < x; a++)
    {
        for (b = 0; b < x - a; b++)
        {
            if (T1[b].skok_1 > T1[b + 1].skok_1)
            {
                struct dane temp = T1[b];
                T1[b] = T1[b + 1];
                T1[b + 1] = temp;
            }
            if (T1[b].skok_1 == T1[b + 1].skok_1 && T1[b].nr_startowy > T1[b + 1].nr_startowy)
            {
                struct dane temp = T1[b];
                T1[b] = T1[b + 1];
                T1[b + 1] = temp;
            }
        }

    }
};

void aktualizacja_T2(dane T2[], dane T1[], int x)
{
    T2[x] = T1[x];
    int a, b;
    for (a = 0; a < x; a++)
    {
        for (b = 0; b < x - a; b++)
        {
            if (T2[b].suma_skokow < T2[b + 1].suma_skokow)
            {
                struct dane temp = T2[b];
                T2[b] = T2[b + 1];
                T2[b + 1] = temp;
            }
            if (T2[b].suma_skokow == T2[b + 1].suma_skokow && T2[b].nr_startowy > T2[b + 1].nr_startowy)
            {
                struct dane temp = T2[b];
                T2[b] = T2[b + 1];
                T2[b + 1] = temp;
            }
        }

    }
};

int main()
{
    int liczba_skoczkow;
    FILE* plik;
    fopen_s(&plik, "ListaStartowa.txt", "r");
    struct dane T1[50];
    struct dane T2[50];
    int i = 0;
    dane* skoczek = new dane[50];
    if (plik != NULL)
    {
        fscanf_s(plik, "%s", skoczek[i].imie, 16);
        fscanf_s(plik, "%s", skoczek[i].nazwisko, 32);
        fscanf_s(plik, "%d", &skoczek[i].nr_startowy);
        while (feof(plik) == 0)
        {
            printf("%s %s %d\n", skoczek[i].imie, skoczek[i].nazwisko, skoczek[i].nr_startowy);
            printf("Dlugosc skoku nr 1:");
            scanf_s("%f", &skoczek[i].skok_1);
            printf("%f\n", skoczek[i].skok_1);
            aktualizacja_T1(T1, skoczek, i);

            i++;
            fscanf_s(plik, "%s", skoczek[i].imie, 16);
            fscanf_s(plik, "%s", skoczek[i].nazwisko, 32);
            fscanf_s(plik, "%d", &skoczek[i].nr_startowy);
        }
        fclose(plik);
        delete[] skoczek;

        liczba_skoczkow = i;
        for (i = 0; i < liczba_skoczkow; i++)
        {
            printf("%s %s %d %f\n", T1[i].imie, T1[i].nazwisko, T1[i].nr_startowy, T1[i].skok_1);
            printf("Dlugosc skoku nr 2:");
            scanf_s("%f", &T1[i].skok_2);
            T1[i].suma_skokow = T1[i].skok_1 + T1[i].skok_2;
            aktualizacja_T2(T2, T1, i);
        }
        FILE* wyniki;
        fopen_s(&wyniki, "Wyniki.txt", "w");
        for (i = 0; i < liczba_skoczkow; i++)
        {
            printf("Miejsce %d: %s %s %d Skok nr 1: %f Skok nr 2: %f Suma skokow: %f\n", i + 1, T2[i].imie, T2[i].nazwisko, T2[i].nr_startowy, T2[i].skok_1, T2[i].skok_2, T2[i].suma_skokow);
            fprintf(wyniki, "Miejsce %d: %s %s %d Skok nr 1: %f Skok nr 2: %f Suma skokow: %f\n", i + 1, T2[i].imie, T2[i].nazwisko, T2[i].nr_startowy, T2[i].skok_1, T2[i].skok_2, T2[i].suma_skokow);
        }
    }
    else
    {
        printf("Nie udalo sie otworzyc pliku.\n");
    }
}