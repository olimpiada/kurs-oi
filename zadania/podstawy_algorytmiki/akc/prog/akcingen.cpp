#include <cstdio>
#include <algorithm>
#include "oi.h"

oi::Random RG;

using namespace std;

const char * code = "akc";
const int DIFF = 100;

void gen1(const char* test, int n, int maxm, int q)
{
  char filename[30];
  sprintf(filename,"%s%s.in",code,test);
  fprintf(stderr,"%s...\n",filename);
  FILE *f = fopen(filename,"w");
  int A[1000002];
  fprintf(f,"%d\n",n);
  for(int i=0; i<n; i++)
    A[i] = RG.rand()%(2*maxm+1) - maxm;
  sort(A,A+n);
  for(int i=0; i<n; i++)
  {
    if (i) fprintf(f," ");
    fprintf(f,"%d",A[i]);
  }
  fprintf(f,"\n%d\n",(2*maxm+3)*q);
  for(int j=0; j<q; j++)
    for(int i=-maxm-1; i<=maxm+1; i++)
      fprintf(f,"%d\n",i);
  fclose(f);
}

void gen2(const char* test, int maxn, int maxm, int q)
{
  char filename[30];
  sprintf(filename,"%s%s.in",code,test);
  fprintf(stderr,"%s...\n",filename);
  FILE *f = fopen(filename,"w");
  int A[1000002];
  int n = RG.rand()%maxn + 1;
  fprintf(f,"%d\n",n);
  for(int i=0; i<n; i++)
    A[i] = RG.rand()%(2*maxm+1) - maxm;
  sort(A,A+n);
  for(int i=0; i<n; i++)
  {
    if (i) fprintf(f," ");
     fprintf(f,"%d",A[i]);
  }
  fprintf(f,"\n%d\n",2*q);
  for(int j=0; j<q; j++)
    fprintf(f,"%d\n",RG.rand()%(2*maxm+1)-maxm);
  for(int j=0; j<q; j++)
    fprintf(f,"%d\n",A[RG.rand()%n]);
  fclose(f);
}

void gen_long(const char* test, int k, int p)
{
  char filename[30];
  sprintf(filename,"%s%s.in",code,test);
  fprintf(stderr,"%s...\n",filename);
  FILE *f = fopen(filename,"w");
  fprintf(f,"%d\n",k*p);
  int TT = RG.rand()%10;
  for(int i=0; i<k; i++)
  {
    if (i) fprintf(f," ");
    for(int j=0; j<p; j++)
    {
      if (j) fprintf(f," ");
      fprintf(f,"%d", TT+i*DIFF);
    }
  }
  fprintf(f,"\n");
  fprintf(f,"%d\n",10*k*(p/2));
  for(int r=0; r<5; r++)
  for(int j=0; j<p/2; j++)
    for(int i=0; i<k; i++)
      fprintf(f,"%d\n%d\n",TT+i*DIFF,TT+i*DIFF+1);
  fclose(f);
}

int main()
{
  RG.setSeed(81422);
  gen1("1a",31,10,2);
  gen1("1b",43,20,2);
  gen1("1c",37,50,3);
  gen2("1d",1001,100,100);
  gen2("1e",1347,3000,100);
  gen2("1f",5000,1000000000,100);
  gen2("1g",4512,10000,100);
  gen_long("1h",100,1000);
  gen_long("1i",7,14285);
  gen_long("1j",2,49999);
  gen1("1k",100000,20000,2);
  gen1("1l",99999,17,10000);
  gen2("1m",100000,10000,100000);
  gen2("1n",100000,1000000000,500000);
}

