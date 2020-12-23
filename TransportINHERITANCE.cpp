class Transport
{
protected:
    char destinacija[100];
    int cena;
    int rastojanie;

public:
    Transport(char destinacija1[100] = "", int cena1 = 0, int rastojanie1 = 0)
    {
        strcpy(destinacija, destinacija1);
        cena = cena1;
        rastojanie = rastojanie1;
    }
    char *getDestinacija()
    {
        return destinacija;
    }
    int getCena()
    {
        return cena;
    }
    int getRastojanie()
    {
        return rastojanie;
    }
    virtual float cenaTransport() = 0;

    bool operator<(Transport &t)
    {
        if (rastojanie < t.rastojanie)
        {
            return true;
        }
        else
            return false;
    }
};

class AvtomobilTransport : public Transport
{
private:
    bool daliSofer;

public:
    AvtomobilTransport(char destinacija1[100] = "", int cena1 = 0, int rastojanie1 = 0, bool dali = false)
        : Transport(destinacija1, cena1, rastojanie1)
    {
        daliSofer = dali;
    }
    float cenaTransport()
    {
        if (daliSofer == true)
        {
            return cena * 1.2;
        }
        return cena;
    }
};

class KombeTransport : public Transport
{
private:
    int brLugje;

public:
    KombeTransport(char destinacija1[100] = "", int cena1 = 0, int rastojanie1 = 0, int br = 0)
        : Transport(destinacija1, cena1, rastojanie1)
    {
        brLugje = br;
    }
    float cenaTransport()
    {
        return cena - brLugje * 200;
    }
};

void sort(Transport **ponudi, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*ponudi[i + 1] < *ponudi[i])
            {
                Transport *tmp;
                tmp = ponudi[i];
                ponudi[i] = ponudi[i + 1];
                ponudi[i + 1] = tmp;
            }
        }
    }
}

void pecatiPoloshiPonudi(Transport **ponudi, int n, AvtomobilTransport &t)
{
    sort(ponudi, n);
    for (int i = 0; i < n; i++)
    {
        if (t.getCena() < ponudi[i]->getCena())
        {
            cout << ponudi[i]->getDestinacija() << " " << ponudi[i]->getRastojanie() << " " << ponudi[i]->cenaTransport() << endl;
        }
    }
}

// вашиот код треба да биде тука

int main()
{

    char destinacija[20];
    int tip, cena, rastojanie, lugje;
    bool shofer;
    int n;
    cin >> n;
    Transport **ponudi;
    ponudi = new Transport *[n];

    for (int i = 0; i < n; i++)
    {

        cin >> tip >> destinacija >> cena >> rastojanie;
        if (tip == 1)
        {
            cin >> shofer;
            ponudi[i] = new AvtomobilTransport(destinacija, cena, rastojanie, shofer);
        }
        else
        {
            cin >> lugje;
            ponudi[i] = new KombeTransport(destinacija, cena, rastojanie, lugje);
        }
    }

    AvtomobilTransport nov("Ohrid", 2000, 600, false);
    pecatiPoloshiPonudi(ponudi, n, nov);

    for (int i = 0; i < n; i++)
        delete ponudi[i];
    delete[] ponudi;
    return 0;
}
