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
        while(p*p*p + a*p < b)
          p++;
        if (p*p*p + a*p == b)
            printf("%Ld\n",p);
        else
            printf("NIE\n");
    }
}
