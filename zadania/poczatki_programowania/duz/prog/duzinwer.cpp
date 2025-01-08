// Autor: Jakub Radoszewski

#include "oi.h"
#include <cctype>
#include <cstring>
using namespace std;

void sprawdz(oi::Scanner &in, char *liczba) {
  int n = strlen(liczba);
  if (n < 1 || n > 1001)
    in.error("Zla dlugosc liczby");
  if (n == 1001) {
    bool ok = (liczba[0] == '1');
    for (int i = 1; i < n; ++i)
      ok &= (liczba[i] == '0');
    if (!ok)
      in.error("Liczba dlugosci 1001 niepoprawna");
  } else {
    bool ok = (isdigit(liczba[0]) && liczba[0] > '0');
    for (int i = 0; i < n; ++i)
      ok &= isdigit(liczba[i]);
    if (!ok)
      in.error("Niepoprawna liczba");
  }
}

char liczba[1010];
char oper[3];

int main() {
	oi::Scanner in(stdin, oi::PL);

  in.readString(liczba, 1005);
  sprawdz(in, liczba);
  in.readSpace();

  in.readString(oper, 3);
  if (strcmp(oper, "<") && strcmp(oper, ">") && strcmp(oper, "!=") && strcmp(oper, "==") && strcmp(oper, "<=") && strcmp(oper, ">="))
    in.error("Niepoprawny operator");
  in.readSpace();

  in.readString(liczba, 1005);
  sprawdz(in, liczba);

  in.readEoln();
	in.readEof();
  printf("OK  %s\n", oper);
	return 0;
}
