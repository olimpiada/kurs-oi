// Autor: Jakub Radoszewski

#include "oi.h"
#include <cctype>
#include <cstring>
using namespace std;

int main() {
	oi::Scanner in(stdin, oi::PL);
  int n = in.readInt(2, 1000);
  in.readEoln();
  for (int i = 0; i < n; i++) {
    in.readInt(1, 1000);
    if (i < n - 1)
      in.readSpace();
    else
      in.readEoln();
  }
	in.readEof();
  printf("OK %d\n", n);
	return 0;
}
