#include <cstdio>
#include <algorithm>
#include "oi.h"

oi::Random RG;

typedef long long LL;

const char* code = "tar";

const LL maxb = 1000LL*1000*1000*1000*1000*1000LL;

void gen_all(LL limit, char test)
{
  char filename[20];
  sprintf(filename,"%s1%c.in",(char*)code,test);
  FILE *f = fopen(filename,"w");
  fprintf(f,"%Ld\n",limit*limit);
  for(LL i=1; i<=limit; i++)
    for(LL j=1; j<=limit; j++)
      fprintf(f,"%Ld %Ld\n",i,j);
  fclose(f);
}

void gen_random(int howmany, LL limit, char test)
{
  char filename[20];
  sprintf(filename,"%s1%c.in",(char*)code,test);
  FILE *f = fopen(filename,"w");
  fprintf(f,"%d\n",howmany);
  for(LL i=1; i<=howmany; i++)
  {
    LL a = RG.randULL()%(limit*limit)+1;
    LL x = RG.randULL()%limit+1;
    LL b = x*x*x + a*x;
    if (RG.rand()%3==0)
      b  = b - b/2 + RG.randULL()%b;
    if (b>maxb)
      b = RG.randULL()%maxb+1;
    fprintf(f,"%Ld %Ld\n",a,b);
  }
  fclose(f);
}

int main()
{
  gen_all(100,'a');
  gen_random(10000,1000,'b');
  gen_random(10000,1000*1000,'c');
}
