// Autor: Jakub Radoszewski

#include "oi.h"
#include <set>
#include <algorithm>
using namespace std;

set<pair<int, int> > zb;

int main() {
	oi::Scanner in(stdin, oi::PL);

  int n = in.readInt(2, 100000);
  in.readEoln();
  int min_x = 1000000, max_x = 0;
  int min_y = 1000000, max_y = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    x = in.readInt(0, 1000000);
    in.readSpace();
    y = in.readInt(0, 1000000);
    if (zb.count(make_pair(x, y)))
      in.error("Punkt powtarza sie");
    zb.insert(make_pair(x, y));\
    in.readEoln();
    if (x < min_x)
      min_x = x;
    if (x > max_x)
      max_x = x;
    if (y < min_y)
      min_y = y;
    if (y > max_y)
      max_y = y;
  }
	in.readEof();
  if (min_x == max_x || min_y == max_y)
    in.error("Prostokat ma zerowe pole");
  printf("OK n = %10d\n", n);
	return 0;
}
