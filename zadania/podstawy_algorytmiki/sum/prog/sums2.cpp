#include <cstdio>

bool isprime(int p)
{
    for(int i=2; i*i<=p; i++)
        if (p % i == 0)
            return false;
    return true;
}


int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    long long res = 0;
    for(int i=a; i<=b; i++)
        if (isprime(i))
            res += i;
    printf("%Ld\n",res);
  }
  
}
