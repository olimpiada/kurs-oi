#include <cstdio>


int main()
{
  int TT,n,k;
  scanf("%d",&TT);
  while(TT--)
  {
    scanf("%d %d",&n,&k);
    int w = 1;
    for(int i=0; i<k; i++)
      w = w*(n+1)%10000;
    printf("%d\n",w);
  }
}
