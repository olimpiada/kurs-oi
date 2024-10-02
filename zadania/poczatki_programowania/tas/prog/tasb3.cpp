// Zadanie Taśma
// Maciej Andrejczuk
// Rozwiązanie niepoprawne
// Losuje dużo razy 2 liczby i sprawdza czy są różne

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define ILE 1500000
#define MAXN 500000

int t[MAXN+3];

int main()
{
	srand(77);
		int n;
		scanf("%d",&n);
		for (int i=0; i<n ;i++)
			scanf("%d",t+i);
		
		int wynik=0;
		for (int i=0; i<ILE; i++)
		{
			int a=rand()%n;
			int b=rand()%n;
			if (t[a]!=t[b]) wynik=max(wynik,abs(b-a));
		}
		if (wynik>0) printf("%d\n",wynik);
		else printf("BRAK\n");
}

