#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include "oi.h"

using namespace std;

oi::Random RG;

const char code[4] = "ran";

const int maxn = 200*1000;

void rstr(FILE* f)
{
  for(int i=0; i<10; i++)
    fputc('a'+RG.rand()%26,f);
}

void gen_random(int filenumber, const char* filesuffix, int n, int range, bool find = true)
{
    char outfile[30];
    int s;
    sprintf(outfile,"%s%d%s.in",code,filenumber,filesuffix);
    fprintf(stderr,"%s...\n",outfile);
    FILE* out = fopen(outfile,"w");
    int A[maxn];
    for(int i=0; i<n; i++)
      A[i] = RG.rand()%range+1;
    if (find)
      do
      {
        s = A[RG.rand()%n]+A[RG.rand()%n];
      } while(s%2==0);
    else
    {
      s = RG.rand()%(2*range-2)+2;
      if (s%2==0)
        s--;
    }
    fprintf(out,"%d %d\n",n,s);
    for(int i=0; i<n; i++)
    {
      rstr(out);
      fprintf(out," %d\n",A[i]);
    }
    fclose(out);
}

int sizes[7] = {10, 100, 1000, 10000, 100000, 200000, 200000};

int main()
{
  RG.setSeed(28957);
  for(int j=1; j<=7; j++)
  {
    int t = sizes[j-1];
    int r;
    if (t<10000)
        r = 10*t;
    else
        r = 1000*1000*1000;
    gen_random(j,"a",t-(RG.rand()%(t/5)),r,j%2);
    gen_random(j,"b",t,r,!(j%2));
  }
}
