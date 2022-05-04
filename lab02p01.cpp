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
};

double wektor::getDlugosc()
{
    return sqrt(x * x + y * y);
}

wektor tab[DL];

void wylosuj(int a, int b);
void wypisz();
double szukaj_max();

int main()
{
    wylosuj(-100, 100);
    wypisz();
    cout << endl
         << "max=" << szukaj_max();
    return 0;
}

void wylosuj(int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < DL; i++)
    {
        tab[i].setX(rand() % (b - a + 1) + a);
        tab[i].setY(rand() % (b - a + 1) + a);
    }
}

void wypisz()
{
    for (int i = 0; i < DL; i++)
        cout << "[" << tab[i].getX() << ";" << tab[i].getY() << "] ";
}

double szukaj_max()
{
    double max = 0;
    for (int i = 0; i < DL; i++)
        if (tab[i].getDlugosc() > max)
            max = tab[i].getDlugosc();
    return max;
}