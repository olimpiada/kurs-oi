/*
 * Zadanie: Czy sie zatrzyma?
 *  Weryfikator danych wejsciowych
 * Autor: Jakub Łącki
 */

#include"oi.h"
using namespace std;

const long long MAXN=100LL*1000*1000*1000*1000;

int main()
{
	oi::Scanner in(stdin, oi::PL);
	long long n = in.readLL(2, MAXN);
	in.readEoln();
	in.readEof();
	printf("OK    n = %15lld\n", n);
	return 0;
}
