#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    if(k > min(a,b))
        printf("0\n");
    else if(2*k  > min(a,b))
        printf("%d\n", max(a,b) / k);
    else
        printf("%d\n", 2*(a / k + b / k) - 4 + 1); // ZLE!
    return 0;
}
