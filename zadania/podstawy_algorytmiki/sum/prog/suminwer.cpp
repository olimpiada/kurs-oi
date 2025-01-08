#include "oi.h"
#include <cstdio>

int main()
{
  oi::Scanner in(stdin);
  int Z = in.readInt(1, 100000);
  in.readEoln();
  while (Z--)
  {
    int a = in.readInt(2,2*1000*1000);
    in.readSpace();
    in.readInt(a,2*1000*1000);
    in.readEoln();
  }
  in.readEof();
  puts("OK.");
  return 0;
}
