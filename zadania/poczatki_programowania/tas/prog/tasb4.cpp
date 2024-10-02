/* Rozwiazanie bledne do zadania TAS (Tasma)
 * Autor: Jakub Radoszewski
 * Data: 20.05.2009
 */

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int ile, n;
int t[MAX_N];

inline int policz()
{
  int j = n - 1;
  while (j > 0 && t[j] == t[0])
    j--;
  return j;
}

int main()
{
  scanf("%d", &ile);
  while (ile--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", t + i);
    int w = 0;// = policz();
    reverse(t, t + n);
    w = max(w, policz());
    if (w == 0)
      puts("BRAK");
    else
      printf("%d\n", w);
  }
  return 0;
}
