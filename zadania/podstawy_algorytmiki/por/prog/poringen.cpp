#include <cstdio>
#include <algorithm>
#include <vector>
#include "oi.h"

using namespace std;

oi::Random RG;

const char* code = "por";

void gen_random(int testno, int TT, int maxn, int maxv)
{
  char filename[20];
  sprintf(filename,"%s%d.in",code,testno);
  FILE *out = fopen(filename,"w");
  fprintf(out,"%d\n",TT);
  while(TT--)
  {
    vector< pair<int,int> > edges;
    int n = RG.rand()%(maxn/2) + maxn/2;
    int m = 0;
    for(int i=2; i<=n; i++)
    {
      vector<int> ng;
      int v = RG.rand()%maxv;
      for(int j=0; j<v; j++)
        ng.push_back(RG.rand()%(i-1)+1);
      sort(ng.begin(),ng.end());
      ng.erase(unique(ng.begin(),ng.end()),ng.end());
      RG.randomShuffle(ng.begin(),ng.end());
      m += ng.size();
      for(int j=0; j<(int)ng.size(); j++)
        edges.push_back(pair<int,int>(i,ng[j]));
    }
    RG.randomShuffle(edges.begin(), edges.end());
    fprintf(out,"%d %d\n",n,m);
    for(int i=0; i<(int)edges.size(); i++)
    {
      if (RG.rand()%2)
        swap(edges[i].first,edges[i].second);
      fprintf(out,"%d %d\n",edges[i].first,edges[i].second);
    }
    fprintf(out,"%d\n",RG.rand()%n + 1);
  }
  fclose(out);
}

void gen_big(int testno, int n)
{
  char filename[20];
  sprintf(filename,"%s%d.in",code,testno);
  FILE *out = fopen(filename,"w");
  vector<int> A;
  fprintf(out,"2\n");
  for(int i=1; i<=n; i++)
    A.push_back(i);
  RG.randomShuffle(A.begin(),A.end());
  fprintf(out,"%d %d\n",n,n-1);
  for(int i=0; i<n-1; i++)
    fprintf(out,"%d %d\n",A[i],A[i+1]);
  fprintf(out,"%d\n",A[0]);
  RG.randomShuffle(A.begin(),A.end());
  fprintf(out,"%d %d\n",n,n);
  for(int i=0; i<n-1; i++)
    fprintf(out,"%d %d\n",A[i],A[i+1]);
  fprintf(out,"%d %d\n",A[n-1],A[0]);
  fprintf(out,"%d\n",A[1]);
  fclose(out);
}

int main()
{
    RG.setSeed(48128);
    gen_random(2,1000,50,5);
    gen_random(3,100,1000,4);
    gen_random(4,100,500,100);
    gen_random(5,6,200000,6);
    gen_big(6,200000);
}
