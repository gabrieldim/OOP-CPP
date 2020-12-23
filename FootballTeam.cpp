#include <iostream>
#include <cstring>
using namespace std;

class FudbalskaEkipa
{
protected:
    char trener[100];
    int golovi[10];

public:
    FudbalskaEkipa(char trener1[100], int golovi1[10])
    {
        strcpy(trener, trener1);
        for (int i = 0; i < 10; i++)
        {
            golovi[i] = golovi1[i];
        }
    }
    virtual int uspeh() = 0;
    bool operator>(FudbalskaEkipa &f)
    {
        if (uspeh() > f.uspeh())
        {
            return true;
        }
        else
            return false;
    }
    char *getTrener()
    {
        return trener;
    }
    virtual char *getIme() = 0;

    FudbalskaEkipa &operator+=(int g)
    {
        for (int i = 0; i < 10; i++)
        {
            golovi[i - 1] = golovi[i];
        }
        golovi[9] = g;
        return *this;
    }
};

class Klub : public FudbalskaEkipa
{
private:
    char ime[100];
    int brojTituli;

public:
    Klub(char trener1[100], int golovi1[10], char ime1[100], int brojTituli1)
        : FudbalskaEkipa(trener1, golovi1)
    {
        strcpy(ime, ime1);
        brojTituli = brojTituli1;
    }
    char *getIme()
    {
        return ime;
    }
    int uspeh()
    {
        int a = 0;
        int b = 0;
        for (int i = 0; i < 10; i++)
        {
            a += golovi[i];
        }
        a *= 3;
        b = brojTituli * 1000;

        return a + b;
    }
};

class Reprezentacija : public FudbalskaEkipa
{
private:
    char imeDrzava[100];
    int nastapi;

public:
    Reprezentacija(char trener1[100], int golovi1[10], char im[100], int n)
        : FudbalskaEkipa(trener1, golovi1)
    {
        strcpy(imeDrzava, im);
        nastapi = n;
    }
    int uspeh()
    {
        int a = 0, b = 0;
        for (int i = 0; i < 10; i++)
        {
            a += golovi[i];
        }
        a *= 3;
        b = nastapi * 50;
        return a + b;
    }
    char *getIme()
    {
        return imeDrzava;
    }
};

ostream &operator<<(ostream &out, FudbalskaEkipa &f)
{
    FudbalskaEkipa *tmp = &f;
    out << tmp->getIme() << endl;
    out << tmp->getTrener() << endl;
    out << tmp->uspeh() << endl;
    return out;
}

void najdobarTrener(FudbalskaEkipa **ekipa, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (ekipa[i]->uspeh() > ekipa[max]->uspeh())
        {
            max = i;
        }
    }
    cout << *ekipa[max];
}

int main()
{
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa *[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i)
    {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j)
        {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0)
        {
            ekipi[i] = new Klub(coach, goals, x, tg);
        }
        else if (type == 1)
        {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i)
    {
        delete ekipi[i];
    }
    delete[] ekipi;
    return 0;
}
