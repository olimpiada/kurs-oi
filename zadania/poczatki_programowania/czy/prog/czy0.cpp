/*
 * Zadanie: Czy sie zatrzyma?
 *  Rozwiazanie wzorcowe
 * Autor: Jakub Lacki
 */

#include<cstdio>

#define LOWBIT(x) (((x)&((x)-1)) ^ (x))

int main()
{
	long long n;
	scanf("%lld", &n);
	if(n == LOWBIT(n))
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}
