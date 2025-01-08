/*
 * Zadanie: Stół
 *  Weryfikator danych wejsciowych
 * Autor: Jakub Łącki
 */

#include<algorithm>
#include"oi.h"
using namespace std;

const int MAXAB=500*1000*1000;
const int MAXAK=500*1000*1000;

int main()
{
    oi::Scanner input(stdin, oi::PL);
    int a, b, k;
    a = input.readInt(1, MAXAB);
    input.readSpace();
    b = input.readInt(1, MAXAB);
    input.readSpace();
    k = input.readInt(1, MAXAB);
    input.readEoln();
    input.readEof();

    /* Który przypadek zachodzi? */
    char p1, p2, p3;
    p1 = p2 = p3 = ' ';
    if(k > min(a,b))
        p1 = '*';
    else if(2*k > min(a,b))
        p2 = '*';
    else
        p3 = '*';
    printf("OK a = %10d b = %10d k = %10d %c%c%c\n", a, b, k, p1, p2, p3);
    return 0;
}
