#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class wektor
{
private:
    int x;
    int y;

public:
    wektor(int px = 0, int py = 0) : x(px), y(py) {}
    double getDlugosc()
    {
        return sqrt(x * x + y * y);
    }
    string toString()
    {
        stringstream temp;
        temp << "[" << x << ";" << y << "]";
        return temp.str();
    }
    friend wektor dodaj(wektor w1, wektor w2);
    friend wektor *dodaj_v2(wektor w1, wektor w2);
    friend wektor pomnoz(wektor w1, int a);
    ~wektor() { cout << toString() << " usuniety" << endl; }
};

int porownaj(wektor &w1, wektor &w2) // w1>w2 => 1; w1==w2 => 0; w1<w2 => -1
{
    if (w1.getDlugosc() > w2.getDlugosc())
        return 1;
    else if (w1.getDlugosc() == w2.getDlugosc())
        return 0;
    else
        return -1;
}

wektor dodaj(wektor w1, wektor w2)
{
    // int x = w1.x + w2.x;
    // int y = w1.y + w2.y;
    // wektor wynik(x,y);
    wektor wynik(w1.x + w2.x, w1.y + w2.y);
    return wynik;
}

wektor pomnoz(wektor w1, int a)
{
    int x = w1.x * a;
    int y = w1.y * a;
    wektor wynik(x, y);
    return wynik;
}

wektor *dodaj_v2(wektor w1, wektor w2)
{
    int x = w1.x + w2.x;
    int y = w1.y + w2.y;
    wektor *wynik = new wektor(x, y);
    return wynik;
}

int main()
{
    wektor wektorA(10, 14), wektorB(-20, -40);
    // if (porownaj(wektorA, wektorB) > 0)
    //     cout << "A>B";
    // else if (porownaj(wektorA, wektorB) == 0)
    //     cout << "A=B";
    // else
    //     cout << "A<B";
    // wektor wektorAplusB = dodaj(wektorA, wektorB);
    // cout << wektorAplusB.toString();
    wektor *wynik = dodaj_v2(wektorA, wektorB);
    cout << "wynik= " << wynik->toString() << endl;
    delete wynik;
    return 0;
}