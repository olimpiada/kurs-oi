/* Rozwiazanie weryfikujace do zadania STO (Stol)
   Autor: Jakub Radoszewski
 */

#include <cstdio>

int A, B, C, K;

int main() {
  scanf("%d%d%d", &A, &B, &K);
  if (A > B) { C = A; A = B; B = C; }
  if (K > A) puts("0");
  else if (2 * K > A) printf("%d\n", B / K);
  else printf("%d\n", 2 * (A / K + B / K) - 4);
  return 0;
}
