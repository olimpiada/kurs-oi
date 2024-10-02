// Autor: Jakub Radoszewski

#include "oi.h"
using namespace std;

int main() {
	oi::Scanner in(stdin, oi::PL);

  int a = in.readInt(1, 2000000000);
  in.readSpace();
  int b = in.readInt(1, 2000000000);
  in.readSpace();
  int k = in.readInt(1, 2000000000);
  in.readEoln();
	in.readEof();
  printf("OK  a = %10d  b = %10d  k = %10d\n", a, b, k);
	return 0;
}
