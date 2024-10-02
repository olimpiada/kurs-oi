#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include "oi.h"

using namespace std;

oi::Random RG;

const char code[4] = "inw";

const int maxr = 1000*1000;
int A[600010];

void gen_random(int filenumber, const char* filesuffix, int n, int range)
{
  char outfile[30];
  sprintf(outfile,"%s%d%s.in",code,filenumber,filesuffix);
  fprintf(stderr,"%s...\n",outfile);
  FILE* out = fopen(outfile,"w");
  fprintf(out,"%d\n",n);
  for(int i=0; i<2*n; i++)
    A[i] = RG.rand()%(range-1)+1;
  sort(A,A+2*n);
  int m = unique(A,A+2*n) - A;
  
  assert(m>=n);
  RG.randomShuffle(A,A+m);
  fprintf(out,"%d",A[0]);
  for(int i=1; i<n; i++)
    fprintf(out," %d",A[i]);
  fprintf(out,"\n");
  fclose(out);
}


void gen_max(int filenumber, const char* filesuffix, int length, bool rev = true)
{
  char outfile[30];
  sprintf(outfile,"%s%d%s.in",code,filenumber,filesuffix);
  fprintf(stderr,"%s...\n",outfile);
  FILE* out = fopen(outfile,"w");
  fprintf(out,"%d\n",length);
  for(int i=0; i<length; i++)
    fprintf(out, (i==0 ? "%d" : " %d"), (rev ? length-i : i+1) );
  fprintf(out, "\n");
  fclose(out);
}

int sizes[7] = {10, 100, 1000, 10000, 100000, 300000, 300000};


int main()
{
  RG.setSeed(41884);
  for(int j=1; j<=7; j++)
  {
    int t = sizes[j-1];
    gen_random(j,"a",t-(RG.rand()%(t/5)),2*t);
    gen_random(j,"b",t,min(10*t,maxr));
    if (j<=2)
      gen_max(j,"c",t,j%2);
  }
  gen_max(6,"c",300000,false);
  gen_max(7,"c",300000,true);
}
