#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct wpis
{
    string wyraz;
    int ile;
};

wpis *tab[1000];

void zeruj_tablice();
void dodaj(string x);
void wypisz();
void wyczysc();
void czytaj_plik();

int main()
{
    zeruj_tablice();
    czytaj_plik();
    wyczysc();
    return 0;
}

void zeruj_tablice()
{
    for (int i = 0; i < 1000; i++)
        tab[i] = NULL;
}

void dodaj(string x)
{
    int poz = 0;
    while (tab[poz] != NULL)
    {
        if (tab[poz]->wyraz == x)
            break;
        poz++;
    }

    if (tab[poz] == NULL)
    {
        tab[poz] = new wpis;
        tab[poz]->wyraz = x;
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
        cout << tab[poz]->wyraz
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
    string wiersz, s;
    int poz = 0, poz_p = 0;

    plik.open("dane.txt", ios::in);
    while (!plik.eof())
    {
        getline(plik, wiersz);
        poz = 0;

        while (wiersz.length() > 0)
        {
            while (wiersz[poz] != ' ' && poz < wiersz.length())
            {
                poz++;
            }
            if (poz == wiersz.length())
                s = wiersz;
            else
            {
                s = wiersz.substr(0, poz);
                while (wiersz[poz]==' ' && poz<wiersz.length())
                {
                    poz++;
                }
                wiersz = wiersz.substr(poz, wiersz.length() - poz-1);
                cout << s << endl;
            }
            
        }
    }

    plik.close();
}