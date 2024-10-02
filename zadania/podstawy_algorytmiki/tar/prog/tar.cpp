// Zagadka Nicolo Tartaglii - rozwiązanie wzorcowe
// Lech Duraj

#include <cstdio>
#include <algorithm>

int main()
{
    int TT;
    scanf("%d",&TT);
    while(TT--)
    {
        long long a, b;
        scanf("%Ld %Ld",&a,&b);
        long long p = 1;
        long long q = 1000*1000;
        while(p < q)
        {
            long long s = (p + q) / 2;
            if (s*s*s + a*s >= b)
                q = s;
            else
                p = s + 1;
        }
        if (p*p*p + a*p == b)
            printf("%Ld\n",p);
        else
            printf("NIE\n");
    }
}
