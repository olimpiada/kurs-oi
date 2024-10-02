/* Rozwiazania bledne do zadania PAP (Papryczki logarytmiczne)
 * Autor: Jakub Radoszewski
 * Data: 16.03.2008
 * Opis: Bierze od najmniejszych papryczek.
 */

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_K = 10;

int k;
int p[MAX_K + 1];

int main()
{
  scanf("%d", &k);
  for (int i = 0; i <= k; i++)
    scanf("%d", p + i);
  for (int x = 1; x <= 1000000000; x++)
  {
    int x0 = x;
    for (int i = 0; i <= k; i++)
    {
      int ile = min(x0 / (1 << i), p[i]);
      x0 -= ile * (1 << i);
    }
    if (x0)
    {
      printf("%d\n", x);
      break;
    }
  }
  return 0;
}
