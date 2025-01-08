#include <cstdio>

int main()
{
  int TT,n;
  scanf("%d",&TT);
  while(TT--)
  {
    scanf("%d",&n);
    int k = n;
    printf("%d = ",n);
    bool empty = false;
    for(int p=2; p*p<=k; p++)
    {
      if (n%p==0)
      {
        if (!empty)
	  empty = true;
	else
	  printf("*");
	int s = 0;
	while(n%p==0)
	{
	  s++;
	  n/=p;
	}
	printf("%d",p);
	if (s>1)
	  printf("^%d",s);
      }
    }
    if (n>1)
    {
      if (empty)
        printf("*");
      printf("%d",n);
    }
    printf("\n");
  }
}