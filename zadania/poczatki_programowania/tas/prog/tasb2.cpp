/* Rozwiazanie niepoprawne do zadania TAS (Tasma)
 * (analizuje tylko 1000 pierwszych i 1000 ostatnich liczb)
 * Autor: Bartlomiej Wolowiec
 * Data: 19.01.2009
 */

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 500000
#define L 3000

int ile, n;
int t[MAX_N];

inline int policz()
{
    int j = n - 1;
    if(n - 2*L > 0){
        while (j > n-L && t[j] == t[0])
            j--;
        if(j > n-L)
            return j;
        j=L;
    }
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
        reverse(t, t + n);
        w = max(w, policz());
        if (w == 0)
            puts("BRAK");
        else
            printf("%d\n", w);
    return 0;
}
