/* Rozwiazanie bledne absurdalne do zadania STO (Stol)
   Autor: Jakub Radoszewski
 */

#include <cstdio>

int A, B, C, K;

int main() {
  scanf("%d%d%d", &A, &B, &K);
  printf("%lld\n", (long long)(A) * B / K / K);
  return 0;
}
