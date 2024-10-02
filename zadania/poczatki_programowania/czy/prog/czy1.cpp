/*
 * Zadanie: Czy sie zatrzyma?
 *  Rozwiazanie alternatywne 1
 * Autor: Jakub Lacki
 */

#include<cstdio>

bool potega2(long long n)
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
	long long n;
	scanf("%lld", &n);
	if(potega2(n))
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}
