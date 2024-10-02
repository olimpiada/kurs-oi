// Zadanie Taśma
// Maciej Andrejczuk
// Rozwiązanie wzorcowe : weryfikujące

#include <iostream>
#include <cstdio>
#include <assert.h>

using namespace std;
#define MAXN 500000
#define MAXA 1000000000
int t[MAXN+3];

int main()
{
		int n;
		scanf("%d",&n);
		assert(n>=1 && n<=MAXN);
		for (int i=0; i<n ;i++)
		{
			scanf("%d",t+i);
			assert(t[i]>=1 && t[i]<=MAXA);
		}
		int k=n-1;
		while (k>0)
		{
			if (t[0]!=t[k]) break;
			if (t[n-k-1]!=t[n-1]) break;
			k--;
		}
		if (k>0) printf("%d\n",k);
		else printf("BRAK\n");
}
