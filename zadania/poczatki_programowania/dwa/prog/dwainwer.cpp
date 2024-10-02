// Autor: Jakub Radoszewski

#include "oi.h"
using namespace std;

int main() {
	oi::Scanner in(stdin, oi::PL);
  int n = in.readInt(2, 100);
  in.readSpace();
  int m = in.readInt(2, 100);
  in.readEoln();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      in.readInt(1, 1000);
      if (j < m - 1)
        in.readSpace();
      else
        in.readEoln();
    }
	in.readEof();
  printf("OK  %4d  %4d\n", n, m);
	return 0;
}
