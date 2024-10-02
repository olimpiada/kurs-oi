/*
 * Zadanie: Czy sie zatrzyma?
 *  Rozwiazanie niepoprawne 6
 * Autor: Jakub Lacki
 */

#include<cstdio>

#define LIMIT 1000000

int main()
{
	unsigned long long n;
	int iter = 0;
	scanf("%llu", &n);
	while(n > 1 && iter < LIMIT)
	{
		iter ++;
		if(n % 2 == 0)
			n /= 2;
		else
			n = 3*n+3;
	}
	if(iter == LIMIT)
		printf("NIE\n");
	else
		printf("TAK\n");
	return 0;
}
