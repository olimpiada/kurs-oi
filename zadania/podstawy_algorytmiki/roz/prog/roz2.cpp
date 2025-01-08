#include <cstdio>

int main()
{
   int P[100000];
   P[0] = 2;
   int primes = 1;
   for(int k=3; k<100000; k++)
   {
     bool ok = true;
     for(int i=0; P[i]*P[i]<=k; i++)
       if (k%P[i]==0)
       {
         ok = false;
	 break;
       }
     if (ok)
       P[primes++] = k;
   }
  int TT,n;
  scanf("%d",&TT);
  while(TT--)
  {
    scanf("%d",&n);
    printf("%d = ",n);
    bool empty = false;
    for(int i=0; P[i]*P[i]<=n; i++)
    {
      if (n%P[i]==0)
      {
        if (!empty)
	  empty = true;
	else
	  printf("*");
	int s = 0;
	while(n%P[i]==0)
	{
	  s++;
	  n/=P[i];
	}
	printf("%d",P[i]);
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
