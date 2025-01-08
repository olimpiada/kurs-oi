/*
 *  Generator danych wejsciowych
 * Autor: Jakub Lacki
 */

#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

#define ID "czy"

const long long MAXN=100LL*1000*1000*1000*1000;

void generuj(string test, long long n)
{
    FILE* plik;
    string nazwa_pliku;

    nazwa_pliku = string(ID) + test + ".in";
    fprintf(stderr, "%s...\n", nazwa_pliku.c_str());
    plik = fopen(nazwa_pliku.c_str(), "w");

    fprintf(plik, "%lld\n", n);

    fclose(plik);
}

int main()
{
	generuj("1", 2);
	generuj("2", 3);
	generuj("3", 4);
	generuj("4", 5);
	generuj("5", 8);
	generuj("6", 9);

	generuj("7", 1LL<<10);
	generuj("8", 1LL<<16);
	generuj("9", 1LL<<17);
	generuj("10", (1<<17)*173);
	generuj("11", (1LL<<31)-1);
	generuj("12", 1LL<<31);
	generuj("13", 1LL<<32);
	generuj("14", 1LL<<36);
	generuj("15", 1LL<<39);

	generuj("16", 859133039546LL); // ubija symulacje na long long
	generuj("17", 366713142269LL); // ubija symulacje na long long

	generuj("18", 1LL<<42);
	generuj("19", 1LL<<46);

	generuj("20", (1LL<<42) - (1LL << 39));
	generuj("21", (1LL<<41) + (1LL << 35));
	generuj("22", (1LL<<46)-1);
	generuj("23", (1LL<<46)+1);

	generuj("24", 99999999999973LL); // liczba pierwsza

	generuj("25", 48382123491939LL); // losowa liczba nieparzysta
	generuj("26", (1LL<<34)*3733LL); // losowa liczba parzysta

	generuj("27", 76687377879921LL); // ponad 1000 krokow symulacji
	generuj("28", 92809481833024LL); // ponad 1000 krokow symulacji

	generuj("29", MAXN-1);
	generuj("30", MAXN);
    return 0;
}
