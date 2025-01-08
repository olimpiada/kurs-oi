// Zadanie Taśma
// Maciej Andrejczuk
// Rozwiązanie niewydajne
// Dla każdej liczby, jeśli się jeszcze nie pojawiła w ciągu
// przegląda wszystkie następne

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
#define MAXN 500000

int t[MAXN+3];

int main()
{
		int n;
		scanf("%d",&n);
		for (int i=0; i<n ;i++)
			scanf("%d",t+i);

		set<int> s;
		int wynik=0;
		for (int i=0; i<n; i++)
		{
			if (s.find(t[i])!=s.end()) continue;
			s.insert(t[i]);
			for (int j=i+1; j<n; j++)
				if (t[i]!=t[j])
					wynik=max(wynik,j-i);
		}
		if (wynik>0) printf("%d\n",wynik);
		else printf("BRAK\n");
}
