/*
 * Zadanie: Czy sie zatrzyma?
 *  Rozwiazanie niepoprawne 7
 * Autor: Jakub Lacki
 */


#include<cstdio>

#define LIMIT 1000

int main()
{
	long long n;
	int iter = 0;
	scanf("%lld", &n);
	while(n != 1 && iter < LIMIT)
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
