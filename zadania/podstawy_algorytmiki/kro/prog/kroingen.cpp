#include <cstdio>
#include <cstdlib>
#include "oi.h"

oi::Random RG;

const int small = 99;
const int big = 10000;
const int maxa = 10000;
const int maxb = 1000000000;


int main()
{
  FILE* f = fopen("kro1a.in","w");
  fprintf(f,"%d\n",small*small);
  for(int i=1; i<=small; i++)
    for(int j=1; j<=small; j++)
       fprintf(f,"%d %d\n",i,j);
  fclose(f);
  f = fopen("kro1b.in","w");
  fprintf(f,"%d\n",big);
  for(int i=0; i<big-4; i++)
    fprintf(f,"%d %d\n",RG.rand()%maxa+1,RG.rand()%maxb+1);
  fprintf(f,"%d %d\n",maxa,1);
  fprintf(f,"%d %d\n",maxa,maxb);
  fprintf(f,"%d %d\n",maxa-1,1);
  fprintf(f,"%d %d\n",maxa-1,maxb);
  fclose(f);
}


