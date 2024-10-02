// Autor: Jakub Radoszewski

#include "oi.h"
using namespace std;

const int MIN = 1;
const int MAX = 1000000000;

int main() {
	oi::Scanner in(stdin, oi::PL);

  int n = in.readInt(1, 100000);
  in.readSpace();
  in.readInt(MIN, MAX);
  in.readEoln();
  for (int i = 0; i < n; i++) {
    in.readInt(MIN, MAX);
    if (i < n - 1) in.readSpace();
    else in.readEoln();
  }
	in.readEof();
  printf("OK n = %10d\n", n);
	return 0;
}
