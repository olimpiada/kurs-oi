/*
 * Zadanie: Czy sie zatrzyma?
 *  Rozwiazanie niepoprawne 2
 * Autor: Jakub Lacki
 */

#include<cstdio>
#include<set>
using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	set<long long> odw;
	while(n > 1)
	{
		if(n % 2 == 0)
			n /= 2;
		else
			n = 3*n+3;
		if(odw.count(n))
		{
			printf("NIE\n");
			return 0;
		}
		odw.insert(n);
	}
	printf("TAK\n");
	return 0;
}
