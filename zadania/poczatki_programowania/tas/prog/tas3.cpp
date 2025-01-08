// Zadanie Taśma
// Maciej Andrejczuk
// Rozwiązanie 'online' bez zapamiętywania liczb
// Złożoność pamięciowa O(1)

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
		int n;
		scanf("%d",&n);
		int pierwszy=0;
		int kolejny=-1;
		int kolejnego_numer=-1;
		int ostatni=0;
		int wynik=0;
		for (int i=0; i<n; i++)
		{
			int a;
			scanf("%d",&a);
			if (i==0) pierwszy=a;
			else
			{
				if (a!=pierwszy)
				{
					if (kolejnego_numer<0)
					{
						kolejny=a;
						kolejnego_numer=i;
					}
					wynik=max(wynik,i);
				}
				ostatni=a;
			}
		}
		if (kolejny>0 && ostatni!=kolejny)
			wynik=max(wynik,n-kolejnego_numer-1);
		if (wynik>0) printf("%d\n",wynik);
		else printf("BRAK\n");
}
