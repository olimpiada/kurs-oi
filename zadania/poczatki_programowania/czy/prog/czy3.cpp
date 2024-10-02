/**
 * Rozwiazanie alternatywne zadania CZY
 * Zadanie: Czy sie zatrzyma
 * Autor: Wojciech Tyczynski
 * Data: 26.10.2011
 */

#include <cstdio>
#include <algorithm>

using namespace std;

long long n;

int main() {
  scanf("%lld", &n);
  printf("%s\n", ((n & (n - 1)) == 0) ? "TAK" : "NIE");
  return 0;
}
