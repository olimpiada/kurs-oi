/* Rozwiazanie brutalne O(n^2) do zadania TAS (Tasma)
 * Autor: Bartłomiej Wołowiec
 * Data: 20.01.2009
 */

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 500000

int ile, n;
int t[MAX_N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", t + i);
    int w = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(t[i]!=t[j])
                w = max(w, i-j);
        }
    }
    if (w == 0)
      puts("BRAK");
    else
      printf("%d\n", w);
  return 0;
}
