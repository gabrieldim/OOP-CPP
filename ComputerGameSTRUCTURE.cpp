#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
struct Igrac
{
    int poeni;
    int nivo;
    char ime[15];
};
struct KompjuterskaIgra
{
    int brojIgraci;
    Igrac igraci[30];
    char ime[30];
};

void najdobarIgrac(KompjuterskaIgra *lista, int n)
{
    int maxIgraci = -99999;
    int cuvajIndeksIgra;
    for (int i = 0; i < n; i++)
    {
        if (lista[i].brojIgraci > maxIgraci)
        {
            maxIgraci = lista[i].brojIgraci;
            cuvajIndeksIgra = i;
        }
    }
    int maxPoeni = -9999;
    int cuvajIndeksIgrac;
    for (int i = 0; i < lista[cuvajIndeksIgra].brojIgraci; i++)
    {
        if (maxPoeni < lista[cuvajIndeksIgra].igraci[i].poeni)
        {
            maxPoeni = lista[cuvajIndeksIgra].igraci[i].poeni;
            cuvajIndeksIgrac = i;
        }
        else if (maxPoeni == lista[cuvajIndeksIgra].igraci[i].poeni)
        {
            if (lista[cuvajIndeksIgra].igraci[i].nivo > lista[cuvajIndeksIgra].igraci[cuvajIndeksIgrac].nivo)
            {
                cuvajIndeksIgrac = i;
            }
        }
    }
    cout << "Najdobar igrac e igracot so korisnicko ime " << lista[cuvajIndeksIgra].igraci[cuvajIndeksIgrac].ime << " koj ja igra igrata " << lista[cuvajIndeksIgra].ime << endl;
}

int main()
{
    int n;
    cin >> n;
    KompjuterskaIgra igri[n];
    for (int i = 0; i < n; i++)
    {
        cin >> igri[i].ime;
        cin >> igri[i].brojIgraci;
        for (int j = 0; j < igri[i].brojIgraci; j++)
        {
            cin >> igri[i].igraci[j].ime;
            cin >> igri[i].igraci[j].nivo;
            cin >> igri[i].igraci[j].poeni;
        }
    }
    najdobarIgrac(igri, n);

    return 0;
}
