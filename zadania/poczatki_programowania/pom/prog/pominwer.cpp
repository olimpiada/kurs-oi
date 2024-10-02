// Autor: Jakub Radoszewski

#include "oi.h"
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000000;

int main() {
	oi::Scanner in(stdin, oi::PL);

  int p = 0;
  in.readInt(0, 0); in.readEoln();
  int ile = 1;
  int wynik = 0;
  while (p != -1 && ile < MAX_N)
  {
    int q = in.readInt(-1, MAX_M); in.readEoln();
    if (q != -1 && q < p)
      in.error("Ciag nie jest niemalejacy!");
    if (q != p && q > 0) ++wynik;
    p = q;
    ++ile;
  }
  if (p != -1) in.error("Ciag liczb jest za dlugi");
  in.readEof();
  printf("OK ile = %7d wynik = %7d\n", ile - 1, wynik);
	return 0;
}
