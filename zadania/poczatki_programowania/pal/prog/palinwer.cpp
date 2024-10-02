// Autor: Jakub Radoszewski

#include "oi.h"
#include <cctype>
using namespace std;

int main() {
	oi::Scanner in(stdin, oi::PL);
  char s[1000010];

  int n = in.readString(s,1000010);
  if (n==0 || n>1000000) in.error("Zla dlugosc slowa");
  for(int i=0;i<n;i++)
    if (!islower(s[i]))
      in.error("Niepoprawna litera");
  in.readEoln();
	in.readEof();
  printf("OK n = %10d\n", n);
	return 0;
}
