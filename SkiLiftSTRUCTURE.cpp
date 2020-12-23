#include <stdio.h>
#include <string.h>

typedef struct SkiLift
{
	char ime[15];
	int max_skijaci;
	int voUpotreba;
} SkiLift;

typedef struct SkiCentar
{
	char ime[20];
	char drzava[20];
	SkiLift niza[20];
	int br_lifts;
	int kapacitet;
} skiCenter;

void najgolemKapacitet(skiCenter *sc, int n)
{
	int cuvajI, maxx = 0;
	int aa = 0;
	for (int i = 0; i < n; i++)
	{
		sc[i].kapacitet = 0;
		for (int j = 0; j < sc[i].br_lifts; j++)
		{
			if (sc[i].niza[j].voUpotreba == 1)
			{
				sc[i].kapacitet += sc[i].niza[j].max_skijaci;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (sc[i].kapacitet > maxx)
		{
			maxx = sc[i].kapacitet;
			cuvajI = i;
		}
		else if (sc[i].kapacitet == sc[cuvajI].kapacitet)
		{
			if (sc[i].br_lifts > sc[cuvajI].br_lifts)
			{
				cuvajI = i;
			}
		}
	}
	printf("%s\n%s\n%d", sc[cuvajI].ime, sc[cuvajI].drzava, sc[cuvajI].kapacitet);
}

int main()
{
	int i, j, n, broj;
	skiCenter sc[20];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		//printf("Ime:");
		scanf("%s", sc[i].ime);
		//printf("\nDrzava:");
		scanf("%s", sc[i].drzava);
		scanf("%d", &sc[i].br_lifts);

		for (j = 0; j < sc[i].br_lifts; j++)
		{
			scanf("%s", sc[i].niza[j].ime);
			scanf("%d", &sc[i].niza[j].max_skijaci);
			scanf("%d", &sc[i].niza[j].voUpotreba);
		}
	}
	najgolemKapacitet(sc, n);

	return 0;
}
