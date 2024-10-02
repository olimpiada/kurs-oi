#include "oi.h"
#include <cstdio>

const int maxn = 2000;

int main() {
  oi::Scanner in(stdin);
  char A[maxn+3];
  char B[maxn+3];
  int m = in.readString(A,maxn+1);
  in.readSpace();
  int n = in.readString(B,maxn+1);
  for(int i=0; i<m; i++)
    if (A[i]<'a' || A[i]>'z')
      in.error("Znak inny niż [a-z]!\n");
  for(int i=0; i<n; i++)
    if (B[i]<'a' || B[i]>'z')
      in.error("Znak inny niż [a-z]!\n");
  in.readEoln();
  in.readEof();
  printf("OK, lengths: %d,%d.\n",m,n);
  return 0;
}
