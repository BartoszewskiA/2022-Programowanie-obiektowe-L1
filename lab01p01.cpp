#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct wpis
{
    char znak;
    int ile;
};

wpis *tab[1000];

void zeruj_tablice();
void dodaj(char x);
void wypisz();
void wyczysc();
void czytaj_plik();

    int main()
{
    zeruj_tablice();
    // dodaj('a');
    // dodaj('a');
    // dodaj('b');
    // dodaj('c');
    // dodaj('a');
    czytaj_plik();
    wypisz();
    wyczysc();
    return 0;
}

void zeruj_tablice()
{
    for (int i = 0; i < 1000; i++)
        tab[i] = NULL;
}

void dodaj(char x)
{
    int poz = 0;
    while (tab[poz] != NULL)
    {
        if (tab[poz]->znak == x)
            break;
        poz++;
    }

    if (tab[poz] == NULL)
    {
        tab[poz] = new wpis;
        tab[poz]->znak = x;
        tab[poz]->ile = 1;
    }
    else
    {
        tab[poz]->ile = tab[poz]->ile + 1;
    }
}

void wypisz()
{
    int poz = 0;
    while (tab[poz] != NULL)
    {
        cout << tab[poz]->znak
             << "-"
             << tab[poz]->ile
             << "  ";
        poz++;
    }
}

void wyczysc()
{
    int poz = 0;
    while (tab[poz] != NULL)
    {
        delete tab[poz];
        poz++;
    }
}

void czytaj_plik()
{
    fstream plik;
    string wiersz;
    plik.open("dane.txt", ios::in);
    while (!plik.eof())
    {
        getline(plik,wiersz);
        for (int i=0; i<wiersz.length(); i++)
            dodaj(wiersz[i]);
    }

    plik.close();
}