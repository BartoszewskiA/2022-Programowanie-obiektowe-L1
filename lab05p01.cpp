#include <iostream>
#include <ctime>

using namespace std;

class Random
{
public:
    Random()
    {
        srand(time(NULL));
    }
    int nextInt()
    {
        return rand();
    }
    int nextInt(int b) // <0,b)
    {
        return rand() % b;
    }
    int nextInt(int a, int b) // <a,b)
    {
        return rand() % (b - a) + a;
    }
    double nextDouble() // <0,1)
    {
        int x = rand() % 1000;
        return (double)x / 1000;
    }
    bool nextMoneta()
    {
        int x = rand() % 2;
        if (x == 1)
            return true;
        else
            return false;
    }

    string nextMoneta2()
    {
        int x = rand() % 2;
        if (x == 1)
            return "orzel";
        else
            return "reszka";
    }
    int nextKostka() // <1,6>
    {
        return nextInt(6) + 1;
    }
};

Random *random = new Random;

int main()
{
    return 0;
}