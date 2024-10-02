#include "oi.h"
#include <cstdio>
#include <cstring>

const int maxn = 200000;
const int maxm = 200000;
const int maxr = 1000000;

int main() {
  oi::Scanner in(stdin);
  int n = in.readInt(1,maxn);
  in.readSpace();
  int m = in.readInt(1,maxm);
  in.readEoln();
  for(int i=0; i<n; i++)
  {
    in.readInt(-maxr,maxr);
    if (i<n-1)
        in.readSpace();
  }
  in.readEoln();
  for(int i=0; i<m; i++)
  {
    char S[10];
    in.readString(S,9);
    if (strcmp(S,"MAX")!=0 && strcmp(S,"UPDATE")!=0)
        in.error("Nieznana operacja!");
    in.readEoln();
    if (strcmp(S,"MAX")==0)
    {
        in.readInt(1,n);
        in.readSpace();
        in.readInt(1,n);
        in.readEoln();
    } else
    {
        in.readInt(1,n);
        in.readSpace();
        in.readInt(-maxr,maxr);
        in.readEoln();
    }
  }
  in.readEof();
  printf("OK, n = %d, m = %d.\n",n,m);
  return 0;
}
