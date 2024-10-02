// Autor: Jakub Radoszewski

#include "oi.h"
using namespace std;

int main() {
	oi::Scanner in(stdin, oi::PL);

  int n = in.readInt(1, 1000000000);
  in.readEoln();
	in.readEof();
  printf("OK n = %10d\n", n);
	return 0;
}
