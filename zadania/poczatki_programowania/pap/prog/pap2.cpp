/* Rozwiazania wzorcowe do zadania PAP (Papryczki logarytmiczne)
 * Autor: Jakub Radoszewski
 * Data: 16.03.2008
 * Opis: Suma+1.
 */

#include <cstdio>

int main()
{
  int k;
  scanf("%d", &k);
  int x = 0;
  for (int i = 0; i <= k; i++)
  {
    int p_i;
    scanf("%d", &p_i);
    x += p_i * (1 << i);
  }
  printf("%d\n", x + 1);
  return 0;
}
