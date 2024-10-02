// Autor: Jakub Radoszewski

#include "oi.h"
using namespace std;

const int MAX = 1000 * 1000 * 1000;

int main() {
	oi::Scanner in(stdin, oi::PL);

  int a, b, c;
  a = in.readInt(1, MAX);
  in.readSpace();
  b = in.readInt(1, MAX);
  in.readSpace();
  c = in.readInt(1, MAX);
  in.readEoln();
  in.readEof();

  printf("OK a = %10d  b = %10d  c = %10d\n", a, b, c);
	return 0;
}
