#include <cstdio>

#include "oi.h"

oi::Random RG;

int main()
{
  const int TT = 1000;
  RG.setSeed(1444);
  FILE * out = fopen("roz3.in","w");
  fprintf(out,"%d\n",TT);
  for(int q=0; q<TT; q++)
    fprintf(out,"%d\n",RG.rand()%999999999+2);
  fclose(out);
}
