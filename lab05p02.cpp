#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class testowa
{

private:
    void zapisz(string opis)
    {
        time_t czas = time(NULL);
        tm *czas_lokalny = localtime(&czas);
        fstream plik;
        plik.open("log.txt", ios::app);
        plik << opis << ": "
             << czas_lokalny->tm_hour << ":"
             << czas_lokalny->tm_min << ":"
             << czas_lokalny->tm_sec << endl;
        plik.close();
    }

public:
    testowa()
    {
        zapisz("Start");
    }
    ~testowa()
    {
        zapisz("Stop");
    }
};

int main()
{
    testowa *t1 = new testowa();
    cout << "Press any key";
    getchar();
    delete t1;
    return 0;
}