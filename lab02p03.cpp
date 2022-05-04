#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const int DL = 10;

class wektor
{
private:
    int x;
    int y;

public:
    int getX() { return x; }
    int getY() { return y; }
    double getDlugosc();
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    void losujXY(int a, int b);
};

double wektor::getDlugosc()
{
    return sqrt(x * x + y * y);
}

void wektor::losujXY(int a, int b)
{
    x = rand() % (b - a + 1) + a;
    y = rand() % (b - a + 1) + a;
}

wektor *tab[DL];

void wylosuj(int a, int b);
void wypisz();
double szukaj_max();
void posprzataj();

int main()
{
    wylosuj(-100, 100);
    wypisz();
    cout << endl
         << "max=" << szukaj_max();
    posprzataj();
    return 0;
}

void wylosuj(int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < DL; i++)
    {
        tab[i] = new wektor;
        tab[i]->losujXY(-10,10);
    }
}

void wypisz()
{
    for (int i = 0; i < DL; i++)
        cout << "[" << tab[i]->getX() << ";" << tab[i]->getY() << "] ";
}

double szukaj_max()
{
    double max = 0;
    for (int i = 0; i < DL; i++)
        if (tab[i]->getDlugosc() > max)
            max = tab[i]->getDlugosc();
    return max;
}

void posprzataj()
{
    for (int i = 0; i < DL; i++)
        delete tab[i];
}