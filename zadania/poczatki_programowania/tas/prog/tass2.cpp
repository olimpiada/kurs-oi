/* Rozwiazanie O(n lg n) do zadania TAS (Tasma)
 * Autor: Bartłomiej Wołowiec
 * Data: 19.01.2009
 */

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 500000
#define LG 20

int ile, n, k;
int t[LG][MAX_N+1];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", t[0] + i);

    int w = 0;

    for(int i=1; i<LG; i++)
        for(int j=0; j<n; j++)
            t[i][j] = t[0][0];

    for(int i=1; i<n; i++){
        k=0;
        int j;
        for(j=LG-1; j>0 && k<n/2; j--){
             k = (t[j-1][k*2]==t[0][i]) ? k*2 + 1 : k*2;
        }

        if(k<i && !j){
            w=max(w, i-k);
        }

        k=i>>1;
        for(int j=1; j<LG; j++){
            t[j][k] = (t[j-1][k*2] == t[j-1][k*2 + 1]) ? t[j-1][k*2] : -1;
            k/=2;
        }
    }
    if (w == 0)
      puts("BRAK");
    else
      printf("%d\n", w);
  return 0;
}
