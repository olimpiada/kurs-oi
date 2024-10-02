// Autor: Jakub Radoszewski

#include "oi.h"
using namespace std;

int main() {
	oi::Scanner in(stdin, oi::PL);
  char k = in.readChar();
  if (k < 'a' || k >= 'a' + 8)
    in.error("Zla kolumna");
  in.readSpace();
  int w = in.readInt(1, 8);
  in.readEoln();
  in.readEof();
  printf("OK  %c%d\n", k, w);
	return 0;
}
