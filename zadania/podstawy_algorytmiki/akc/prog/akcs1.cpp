
#include <cstdio>
#include <algorithm>
#include <cassert>

#define BILLION 1000000000LL

using namespace std;

int main()
{
  int A[1000002];
  int n,i,m,key;
    scanf("%d",&n);
    for(i=0; i<n; i++)
      scanf("%d",&A[i]);
    scanf("%d",&m);
    for(i=0; i<m; i++)
    {
      scanf("%d",&key);
      int p,q;
      p = 0;
      q = n-1;
      while(p<q)
      {
        int s = (p+q)/2;
        if (A[s]>=key)
          q = s;
        else
          p = s+1;
      }
      int leftmost = p;
      if (A[leftmost]!=key)
        printf("0\n");
      else
      {
        int c = 1;
        while(leftmost+c<n && A[leftmost+c]==key)
          c++;
        printf("%d\n",c);
      }
    }
}
