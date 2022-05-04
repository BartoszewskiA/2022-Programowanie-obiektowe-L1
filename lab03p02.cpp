#include <iostream>
#include <ctime>

using namespace std;
class pudelko
{
private:
    string kotek;

public:
    pudelko() { kotek = ""; }
    string otworz()
    {
        if (kotek.length() == 0)
        {
            int los = rand() % 2;
            if (los == 1)
                kotek = "zywy ";
            else
                kotek = "martwy ";
        }
        return kotek;
    }
};

int main()
{
    srand(time(NULL));
    pudelko p1;
    cout << p1.otworz();
    cout << p1.otworz();
    cout << p1.otworz();
    cout << p1.otworz();
    cout << p1.otworz();
    return 0;
}