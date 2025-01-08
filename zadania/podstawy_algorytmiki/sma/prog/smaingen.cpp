#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <memory.h>
#include <algorithm>
#include "oi.h"

oi::Random RG;

int t[1000010];


int random(int a, int b)
{
	return RG.rand()%(b-a+1) + a;
}

void answer(const char *filename)
{
//	char query[666];
//	sprintf(query, "./sma < %s.in > %s.out", filename, filename);

//	system(query);
}

void reczne(const char *filename, const char *test)
{
	FILE *out = fopen(filename, "w");
	fprintf(out, "%s", test);
	fclose(out);
}

void losowe(const char *filename, int ziarno, int n, int m)
{
	FILE *out = fopen(filename, "w");

	RG.setSeed(ziarno);
	fprintf(out, "%d %d\n", n, m);
	while(n--)
	  fprintf(out, "%d ", RG.rand()%m+1);
	fclose(out);
}

void powtorzenia(const char *filename, int ziarno, int n, int m)
{
	FILE *out = fopen(filename, "w");

	RG.setSeed(ziarno);
	fprintf(out, "%d %d\n", n, m);
	for(int i=0; i<n; i++)
	{
	  if(RG.rand()%3 == 0)
	  {
	    int powt = RG.rand()%8+1;
	    int val = RG.rand()%m+1;
	    while(i<n && powt--)
	    {
	      fprintf(out, "%d ", val);
	      i++;
	    }
	    i--;
	  }
	  else
	    fprintf(out, "%d ", RG.rand()%m+1);
	}
	fclose(out);
}

void rozne(const char *filename, int ziarno, int n)
{
	FILE *out = fopen(filename, "w");

	RG.setSeed(ziarno);
	fprintf(out, "%d %d\n", n, n);
	for(int i = 0 ; i<n; i++)
	  t[i]=i+1;
	RG.randomShuffle(t, t+n);
	for(int i = 0 ; i<n; i++)
	  fprintf(out, "%d ", t[i]);
	fclose(out);
}

void rozne2(const char *filename, int ziarno, int n)
{
	FILE *out = fopen(filename, "w");

	RG.setSeed(ziarno);
	fprintf(out, "%d %d\n", n, n-5);
	for(int i = 0 ; i<n; i++)
	  t[i]=i+1;
	for(int i=0; i<5; i++)
	  t[n-5+i]=RG.rand()%(n-5)+1;
	RG.randomShuffle(t, t+n);
	for(int i = 0 ; i<n; i++)
	  fprintf(out, "%d ", t[i]);
	fclose(out);
}

int main(int argc, char *argv[])
{
	reczne("sma1a.in", "5 5\n1 2 3 4 5\n");
	answer("sma1a");
	reczne("sma1b.in", "3 1\n1 1 1\n");
	answer("sma1b");

	losowe("sma2a.in", 2345123, 20, 5);
	answer("sma2a");
	reczne("sma2b.in", "6 2\n1 2 2 1 1 2\n");
	answer("sma2b");

	losowe("sma3a.in", 562, 5000, 4000);
	answer("sma3a");
	reczne("sma3b.in", "7 4\n1 2 3 4 3 2 1\n");
	answer("sma3b");

	losowe("sma4a.in", 2385, 5000, 500);
	answer("sma4a");
	rozne("sma4b.in", 7598, 5000);
	answer("sma4b");

	losowe("sma5a.in", 753956, 100000, 40000);
	answer("sma5a");
	powtorzenia("sma5b.in", 1235843, 100000, 9876);
	answer("sma5b");

	losowe("sma6a.in", 258364, 100000, 21000);
	answer("sma6a");
	rozne("sma6b.in", 15896, 100000);
	answer("sma6b");

	losowe("sma7a.in", 147854, 200000, 65000);
	answer("sma7a");
	powtorzenia("sma7b.in", 35974, 200000, 98200);
	answer("sma7b");

	rozne2("sma8.in", 35, 1000000);
	answer("sma8");

	losowe("sma9.in", 948, 1000000, 1000000);
	answer("sma9");

	rozne2("sma10.in", 55964, 1000000);
	answer("sma10");

	return 0;
}