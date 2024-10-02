/*
 * Zadanie: Czy sie zatrzyma?
 *  Bezsensowne rozwiazanie nieoptymalne
 * Autor: Jakub Lacki
 */

#include<cstdio>

#define LOWBIT(x) (((x)&((x)-1)) ^ (x))

int main()
{
	long long n;
	scanf("%lld", &n);
	if(n > 70000000000000LL) // jestem rozwiazaniem wolnym
		while(1);
	if(n == LOWBIT(n))
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}
