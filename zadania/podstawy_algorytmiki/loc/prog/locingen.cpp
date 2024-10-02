#include <cstdio>
#include <algorithm>
#include "oi.h"

using namespace std;

const char* code = "loc";

char A[1002][1002];

const int bbn = 100000;

oi::Random RG;

void gen(int testno, int TT, int minn, int maxn, double p)
{
  char filename[20];
  sprintf(filename,"%s%d.in",code,testno);
  FILE *out = fopen(filename,"w");
  fprintf(out,"%d\n",TT);
  while(TT--)
  {
    int m = minn + RG.rand() % (maxn - minn + 1);
    int n = minn + RG.rand() % (maxn - minn + 1);
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
      {
        A[i][j] = '.';
	if (RG.rand()%bbn/(double)bbn < p)
	  A[i][j] = '#';
      }
    int sx = RG.rand()%m;
    int sy = RG.rand()%n;
    int ex,ey;
    do
    {
      ex = RG.rand()%m;
      ey = RG.rand()%n;
    } while (sx == ex && sy == ey);
    A[sx][sy] = '@';
    A[ex][ey] = '>';
    fprintf(out,"%d %d\n",m,n);
    for(int i=0; i<m; i++)
    {
      for(int j=0; j<n; j++)
        fprintf(out,"%c",A[i][j]);
      fprintf(out,"\n");
    }
  }
  fclose(out);
}

int main()
{
  RG.setSeed(777555);
  gen(2,100,50,100,0.34);
  gen(3,3,500,1000,0.37);
  gen(4,1,1000,1000,0.01);
}
