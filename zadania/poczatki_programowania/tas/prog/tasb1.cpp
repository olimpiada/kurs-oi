/* Rozwiazanie niepoprawne do zadania TAS
 * Autor: Bartlomiej Wolowiec
 * Data: 20.01.2009
 */

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 500000

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
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", t + i);
    int w = policz();
    if (w == 0)
      puts("BRAK");
    else{
        printf("%d\n", max(w, n-1-w));
    }
  return 0;
}
