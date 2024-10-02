// Autor: Jakub Radoszewski

#include "oi.h"
#include <set>
#include <algorithm>
using namespace std;

set<pair<int, int> > zb;

int main() {
	oi::Scanner in(stdin, oi::PL);

  int n = in.readInt(1, 500000);
  in.readEoln();
  for (int i = 0; i < n; i++) {
    in.readInt(1, 1000000);
    if (i < n - 1)
      in.readSpace();
    else
      in.readEoln();
  }
	in.readEof();
  printf("OK n = %6d\n", n);
	return 0;
}
