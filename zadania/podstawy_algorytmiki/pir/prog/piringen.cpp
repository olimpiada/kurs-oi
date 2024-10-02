#include <cstdio>
#include "oi.h"

oi::Random RG;

const char code[4] = "pir";

const int BBN = 1000*1000;

int get_rand(int lo, int hi) 
{
  return (RG.rand() % (hi - lo + 1)) + lo;
}

void gen(int fn, int min_len, int max_len, int max_mod, double prob) 
{
  char filename[30];
  sprintf(filename,"%s%d.in",code,fn);
  FILE * f = fopen(filename,"w");
  int len = get_rand(min_len, max_len);
  int mod = get_rand(2, max_mod);

  fprintf(f,"%d %d\n", len, mod);
  fprintf(f,"1");
  
  for (int i = 1; i < len - 1; ++i) 
    fprintf(f,(RG.rand()%BBN < (int)(prob*BBN)) ? "1" : "0");

  fprintf(f,"1\n");
  fclose(f);
}

void gen_max(int fn, int len, int mod)
{
  char filename[30];
  sprintf(filename,"%s%d.in",code,fn);
  FILE * f = fopen(filename,"w");
  fprintf(f,"%d %d\n", len, mod);
  for(int i=0; i<len; i++)
    fprintf(f,"1");
  fprintf(f,"\n");
  fclose(f);
}


int main()
{
  RG.setSeed(1444);
  for(int i=2; i<=4; i++)
    gen(i,10,50,10000,0.5+i*0.1);
  for(int i=5; i<=7; i++)
    gen(i,100,500,100000,0.7+i*0.05);
  for(int i=8; i<=10; i++)
    gen(i,500*1000,1000*1000,1000*1000,0.899+i*0.01);
  gen_max(11,1000*1000,999997);
}

