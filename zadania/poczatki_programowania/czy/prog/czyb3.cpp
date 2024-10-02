/*
 * Zadanie: Czy sie zatrzyma?
 *  Rozwiazanie niepoprawne 3
 * Autor: Jakub Lacki
 */

#include<cstdio>

bool potega2(int n)
{
	if(n == 1)
		return true;
	else if(n % 2 == 0)
		return potega2(n/2);
	else
		return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	if(potega2(n))
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}
