#include<cstdio>
#include<algorithm>
using namespace std;

int idiv(int n, int k)
{
    int ret = 0;
    while(n >= k)
    {
        n -= k;
        ret ++;
    }
    return ret;
}

int main()
{
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    if(k > min(a,b))
        printf("0\n");
    else if(2*k  > min(a,b))
        printf("%d\n", idiv(max(a,b),k));
    else
        printf("%d\n", 2*(idiv(a, k) + idiv(b, k)) - 4);
    return 0;
}
