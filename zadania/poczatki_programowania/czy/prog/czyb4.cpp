/*
 * Zadanie: Czy sie zatrzyma?
 *  Rozwiazanie niepoprawne 4
 * Autor: Jakub Lacki
 */



#include<cstdio>

#define LOWBIT(x) (((x)&((x)-1)) ^ (x))

int main()
{
	int n;
	scanf("%d", &n);
	if(n == LOWBIT(n))
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}
