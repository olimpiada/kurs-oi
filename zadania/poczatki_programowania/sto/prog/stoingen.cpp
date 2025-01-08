/*
 * Zadanie: Stół
 *  Generator danych wejsciowych
 * Autor: Jakub Lacki
 */

#include<cstdio>
#include<string>
#include"oi.h"
using namespace std;

#define ID "sto"

const int MAXAB=500*1000*1000;
const int MAXK=500*1000*1000;

void test(string t, int a, int b, int k)
{
    FILE* plik;
    string nazwa_pliku;

    nazwa_pliku = string(ID) + t + ".in";
    fprintf(stderr, "%s...\n", nazwa_pliku.c_str());

    plik = fopen(nazwa_pliku.c_str(), "w");
    fprintf(plik, "%d %d %d\n", a, b, k);
    fclose(plik);
}

oi::Random rg;

int main()
{
    test("1a", 1, 1, 1);
    test("1b", 2, 2, 1);
    test("1c", 1, 1, 2);
    test("1d", 11, 5, 3);
    test("1e", 8, 12, 3);

    test("2a", 17, 23, 4);
    test("2b", 23, 17, 3);

    test("3a", 35*127, 68, 35);
    test("3b", 68, 35*127-1, 35);
    test("3c", 113*12-13, 113*17-100, 113);

    test("4a", 113*443, 2*113-1, 113);
    test("4b", 2*444-1, 444*1333, 444);
    test("4c", 37431, 5832, 5831);

    test("5a", 85851, 17, 3);
    test("5b", 222, 174331, 111);
    test("5c", 7852*3+7, 7852*2+5, 7852);


    test("6a", 412341, 7847874, 2);
    test("6b", 894*1213-1, 894*3311-3, 894);
    test("6c", 13242*9, 12341*17, 12341);

    test("7a", 945838, 949492, 11234);
    test("7b", 599341, 85858921, 444);
    test("7c", 9848123, 34812, 491923);

    test("8a", MAXAB/3, MAXAB/2, MAXAB/3/4+1);
    test("8b", MAXAB/11, MAXAB/7, MAXAB/20);
    test("8c", MAXAB, MAXAB, 3);
    test("8d", MAXAB/200, MAXAB, MAXAB/400);

    test("9a", MAXAB, 1, 1);
    test("9b", MAXAB, MAXAB-1, MAXAB);
    test("9c", MAXAB, MAXAB, MAXAB/8+1);

    test("10a", MAXAB, MAXAB, MAXK);
    test("10b", MAXAB, MAXAB, 1);
    test("10c", MAXAB, MAXAB, 333667);
    test("10d", MAXAB-1, MAXAB, 5);
    return 0;
}
