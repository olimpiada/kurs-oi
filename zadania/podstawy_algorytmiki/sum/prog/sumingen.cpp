#include <cstdio>
#include <algorithm>

#include "oi.h"

using namespace std;


oi::Random RG;

int main()
{
  const int maxt = 100000;
  const int maxn = 2000000;
  RG.setSeed(1444);
  FILE * out = fopen("sum1.in","w");
  fprintf(out,"%d\n",999);
  for(int q=2; q<=1000; q++)
    fprintf(out,"%d %d\n",2, q);
  fclose(out);
  out = fopen("sum2.in","w");
  fprintf(out,"%d\n",maxt);
  for(int q=0; q<maxt; q++)
  {
    int a = RG.rand()%(maxn-2)+2;
    int b = RG.rand()%(maxn-2)+2;
    if (a>b)
      swap(a,b);
    fprintf(out,"%d %d\n",a, b);
  }
  fclose(out);
}
