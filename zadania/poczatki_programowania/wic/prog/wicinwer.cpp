// Autor: Jakub Radoszewski

#include "oi.h"
#include <cctype>
#include <set>
using namespace std;

int main() {
	oi::Scanner in(stdin, oi::PL);
  int n = in.readInt(2, 1000);
  in.readEoln();
  set<int> zb;
  for (int i = 0; i < n; i++) {
    int a = in.readInt(1, 1000000);
    if (zb.count(a))
      in.error("Liczba powtarza sie");
    zb.insert(a);
    if (i < n - 1)
      in.readSpace();
    else
      in.readEoln();
  }
	in.readEof();
  printf("OK %d\n", n);
	return 0;
}
