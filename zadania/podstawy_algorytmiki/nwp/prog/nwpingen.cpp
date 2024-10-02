#include <cstdio>
#include "oi.h"

oi::Random RG;

const char code[4] = "nwp";

int get_rand(int lo, int hi) 
{
  return (RG.rand() % (hi - lo + 1)) + lo;
}

char rc(int alpha)
{
    return 'a'+RG.rand()%alpha;
}

const int maxn = 2000;

void gen(int fn, const char* letter, int m, int n, int lcs, int alpha)
{
  char filename[30];
  sprintf(filename,"%s%d%s.in",code,fn,letter);
  FILE * f = fopen(filename,"w");
  char A[maxn+1],B[maxn+1],C[maxn+1];
  int RA[maxn+1], RB[maxn+1];
  for(int i=0; i<m; i++)
    RA[i] = (i<lcs);
  for(int i=0; i<n; i++)
    RB[i] = (i<lcs);
  for(int i=0; i<lcs; i++)
    C[i] = rc(alpha);
  RG.randomShuffle(RA,RA+m);
  RG.randomShuffle(RB,RB+n);
  int k = 0;
  for(int i=0; i<m; i++)
    if (RA[i])
      A[i] = C[k++];
    else
      A[i] = rc(alpha);
  A[m] = 0;
  k = 0;
  for(int i=0; i<n; i++)
    if (RB[i])
      B[i] = C[k++];
    else
      B[i] = rc(alpha);
  B[n] = 0;
  fprintf(f,"%s %s\n",A,B);
  fclose(f);
}


int main()
{
  RG.setSeed(1776);
  gen(1,"a",10,8,4,2);
  gen(1,"b",20,10,6,26);
  gen(2,"",33,58,13,4);
  gen(3,"",100,100,1,26);
  gen(4,"",101,78,40,26);
  for(int i=5; i<=9; i++)
  {
    gen(i,"a",get_rand(1000,2000),get_rand(1000,2000),get_rand(0,30),26);
    gen(i,"b",get_rand(1000,2000),get_rand(1000,2000),get_rand(0,1000),26);
    gen(i,"c",get_rand(1000,2000),get_rand(1000,2000),0,2+i%2);
  }
  gen(10,"a",2000,2000,10,26);
  gen(10,"b",2000,2000,461,26);
  gen(10,"c",2000,2000,1982,26);
  gen(10,"d",2000,2000,0,2);
}

