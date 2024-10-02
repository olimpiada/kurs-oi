#include "oi.h"
#include <cstdio>

int main() {
  oi::Scanner in(stdin);
  int n = in.readInt(3,1000*1000);
  in.readSpace();
  in.readInt(3,1000*1000);
  in.readEoln();
  char A[1000*1001];
  int len = in.readString(A,n+1);
  if (len!=n)
    in.error("Zla liczba znakow!\n");
  for(int i=0; i<n; i++)
    if (A[i]!='0' && A[i]!='1')
      in.error("Znak inny niż {0,1}!\n");
  in.readEoln();
  in.readEof();
  printf("OK, length: %d.\n",n);
  return 0;
}
