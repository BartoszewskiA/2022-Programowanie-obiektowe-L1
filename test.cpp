#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int ZYCIE = 200;
const int MANA = 200;
struct cios
{
    int atak_fizyczny = 0;
    int atak_magiczny = 0;
    bool podstepny_atak = false; // szansa procentowa
};
//****************************************************************
class postac
{
public:
    virtual cios zadanie_ciosu() = 0;
    virtual string przyjecie_ciosu(cios c) = 0;
    virtual int get_zycie() = 0;
    virtual string przedstaw_sie() = 0;
    virtual string podaj_stan_postaci() = 0;
};
//****************************************************************

class barbarzynca : public postac
{
protected:
    string imie;
    int zycie;
    int szal;
    int atak_fizyczny;
    int atak_magiczny;
    int obrona_fizyczna;
    int obrona_magiczna;

public:
    barbarzynca(string Imie) : imie(Imie)
    {
        zycie = ZYCIE;
        szal = 0;
        atak_fizyczny = 30;
        atak_magiczny = 0;
        obrona_fizyczna = 10;
        obrona_magiczna = 0;
    }
    cios zadanie_ciosu()
    {
        cios c;
        szal = ZYCIE - zycie;
        int uderzenie = this->atak_fizyczny * ((rand() % 101) / 100.0);
        uderzenie = uderzenie + szal / 10;
        c.atak_fizyczny = uderzenie;
        c.atak_magiczny = 0;
        c.podstepny_atak = false;
        return c;
    }

    string przyjecie_ciosu(cios c)
    {
        stringstream obrazenia;
        obrazenia << "Obrazenia: ";
        if (c.podstepny_atak)
        {
            zycie -= c.atak_fizyczny;
            obrazenia << c.atak_fizyczny << " ";
            zycie -= c.atak_magiczny;
            obrazenia << c.atak_magiczny << " ";
        }
        else
        {
            int obr_fiz = c.atak_fizyczny - (obrona_fizyczna * ((rand() % 101) / 100.0));
            if (obr_fiz > 0)
                zycie -= obr_fiz;
            obrazenia << obr_fiz << " ";
            int obr_mag = c.atak_magiczny - (obrona_magiczna * ((rand() % 101) / 100.0));
            if (obr_mag > 0)
                zycie -= obr_mag;
            obrazenia << obr_mag << " ";
        }
        return obrazenia.str();
    }
    int get_zycie() { return zycie; }
    string przedstaw_sie()
    {
        stringstream temp;
        temp << imie << " barbazynca";
        return temp.str();
    }
    string podaj_stan_postaci()
    {
        stringstream temp;
        temp << "[zycie: " << zycie << " szal: " << szal << "]";
        return temp.str();
    }
};
//****************************************************************
class mag : public postac
{
protected:
    string imie;
    int zycie;
    int mana;
    int atak_fizyczny;
    int atak_magiczny;
    int obrona_fizyczna;
    int obrona_magiczna;

public:
    mag(string Imie) : imie(Imie)
    {
        zycie = ZYCIE;
        mana = MANA;
        atak_fizyczny = 5;
        atak_magiczny = 30;
        obrona_fizyczna = 0;
        obrona_magiczna = 20;
    }
    cios zadanie_ciosu()
    {
        cios c;
        if (mana > 0)
        {
            int czar = this->atak_magiczny * ((rand() % 101) / 100.0);
            mana -= czar / 2;
            c.atak_fizyczny = 0;
            c.atak_magiczny = czar;
            c.podstepny_atak = false;
        }
        else
        {
            c.atak_fizyczny = this->atak_fizyczny * ((rand() % 101) / 100.0);
            c.atak_magiczny = 0;
            c.podstepny_atak = false;
        }
        mana += 2;
        return c;
    }
    string przyjecie_ciosu(cios c)
    {
        stringstream obrazenia;
        obrazenia << "Obrazenia: ";
        if (c.podstepny_atak)
        {
            zycie -= c.atak_fizyczny;
            obrazenia << c.atak_fizyczny << " ";
            zycie -= c.atak_magiczny;
            obrazenia << c.atak_magiczny << " ";
        }
        else
        {
            if (mana > 0)
            {
                int zaklecie_ochronne = obrona_magiczna * ((rand() % 101) / 100.0);
                mana -= zaklecie_ochronne / 2;
                if ((c.atak_fizyczny - zaklecie_ochronne) > 0)
                    zycie -= (c.atak_fizyczny - zaklecie_ochronne);
                if ((c.atak_magiczny - zaklecie_ochronne) > 0)
                    zycie -= (c.atak_magiczny - zaklecie_ochronne);
            }
            else
            {
                zycie -= c.atak_fizyczny; // - (obrona_fizyczna * ((rand() % 101) / 100.0));
                zycie -= c.atak_magiczny; // - (obrona_magiczna * ((rand() % 101) / 100.0));
            }
        }
        return "";
    }
    int get_zycie() { return zycie; }
    string przedstaw_sie()
    {
        stringstream temp;
        temp << imie << " mag";
        return temp.str();
    }
    string podaj_stan_postaci()
    {
        stringstream temp;
        temp << "[zycie: " << zycie << " mana: " << mana << "]";
        return temp.str();
    }
};
//****************************************************************
class lotrzyk : public postac
{
protected:
    string imie;
    int zycie;
    int zrecznosc;
    int atak_fizyczny;
    int atak_magiczny;
    int obrona_fizyczna;
    int obrona_magiczna;

public:
    lotrzyk(string Imie) : imie(Imie)
    {
        zycie = ZYCIE;
        zrecznosc = 40; // 0% - 100%
        atak_fizyczny = 15;
        atak_magiczny = 0;
        obrona_fizyczna = 10;
        obrona_magiczna = 10;
    }
    cios zadanie_ciosu()
    {
        cios c;
        int uderzenie = this->atak_fizyczny * ((rand() % 101) / 100.0);
        c.atak_fizyczny = uderzenie;
        c.atak_magiczny = 0;
        if (rand() % 101 > (100 - zrecznosc))
            c.podstepny_atak = true;
        return c;
    }

    
    string przyjecie_ciosu(cios c)
    {
        stringstream obrazenia;
        obrazenia << "Obrazenia: ";
        if (c.podstepny_atak)
        {
            zycie -= c.atak_fizyczny;
            obrazenia << c.atak_fizyczny << " ";
            zycie -= c.atak_magiczny;
            obrazenia << c.atak_magiczny << " ";
        }
        else
        {
            if (rand() % 101 < (100 - zrecznosc))
            {
                int obr_fiz = c.atak_fizyczny - (obrona_fizyczna * ((rand() % 101) / 100.0));
                if (obr_fiz > 0)
                    zycie -= obr_fiz;
                obrazenia << obr_fiz << " ";
                int obr_mag = c.atak_magiczny - (obrona_magiczna * ((rand() % 101) / 100.0));
                if (obr_mag > 0)
                    zycie -= obr_mag;
                obrazenia << obr_mag << " ";
            }
            else
            {
                obrazenia << "unik ";
            }
        }
        return obrazenia.str();
    }

    int get_zycie() { return zycie; }
    string przedstaw_sie()
    {
        stringstream temp;
        temp << imie << " lotrzyk";
        return temp.str();
    }
    string podaj_stan_postaci()
    {
        stringstream temp;
        temp << "[zycie: " << zycie << "]";
        return temp.str();
    }
};
//****************************************************************

void wymiana_ciosow(postac *p1, postac *p2)
{
    cios c;
    int stop = 100;
    while (p1->get_zycie() > 0 && p2->get_zycie() > 0 && --stop > 0)
    {
        c = p1->zadanie_ciosu();
        // cout << c.atak_fizyczny << " " << c.atak_magiczny << " ";
        cout << p2->przedstaw_sie() << " " << p2->przyjecie_ciosu(c);
        cout << p2->get_zycie() << " | ";
        c = p2->zadanie_ciosu();
        // cout << c.atak_fizyczny << " " << c.atak_magiczny << " ";
        cout << p1->przedstaw_sie() << " " << p1->przyjecie_ciosu(c);
        cout << p1->get_zycie() << endl;
    }
}

void bitwa(postac *druzyna_zlych[], postac *druzyna_dobrych[])
{
    int zawodnik_zlych = 0;
    int zawodnik_dobrych = 0;

    while (zawodnik_zlych < 3 && zawodnik_dobrych < 3)
    {
        wymiana_ciosow(druzyna_zlych[zawodnik_zlych], druzyna_dobrych[zawodnik_dobrych]);
        if (druzyna_zlych[zawodnik_zlych]->get_zycie() <= 0)
            zawodnik_zlych++;
        if (druzyna_dobrych[zawodnik_dobrych]->get_zycie() <= 0)
            zawodnik_dobrych++;
    }
}

int main()
{
    srand(time(NULL));
    postac *druzyna_dobrych[3] = {
        new barbarzynca("Conan"),
        new mag("Gandalf"),
        new lotrzyk("Dumbledor")};

    postac *druzyna_zlych[3] = {
        new mag("Saruman"),
        new barbarzynca("Gora"),
        new lotrzyk("Masa")};

    bitwa(druzyna_zlych, druzyna_dobrych);

    for (int i = 0; i < 3; i++)
        cout << druzyna_dobrych[i]->przedstaw_sie()
             << " " << druzyna_dobrych[i]->podaj_stan_postaci() << endl;
    cout << endl
         << endl;
    for (int i = 0; i < 3; i++)
        cout << druzyna_zlych[i]->przedstaw_sie()
             << " " << druzyna_zlych[i]->podaj_stan_postaci() << endl;
    return 0;
}