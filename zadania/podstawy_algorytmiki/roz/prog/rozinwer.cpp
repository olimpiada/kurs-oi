#include "oi.h"
#include <cstdio>

int main() {
  oi::Scanner in(stdin);
  int Z = in.readInt(1, 1000);
  in.readEoln();
  while (Z--)
  {
    in.readInt(2,1000*1000*1000);
    in.readEoln();
  }
  in.readEof();
  puts("OK.");
  return 0;
}
