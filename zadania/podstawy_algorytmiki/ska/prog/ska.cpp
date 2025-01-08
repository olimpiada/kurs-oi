#include <cstdio>
#include <algorithm>

using namespace std;

int A[10002];

int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int n,b;
    scanf("%d %d",&n,&b);
    for(int i=0; i<=b; i++)
      A[i] = 0;
    for(int j=0; j<n; j++)
    {
      int s,v;
      scanf("%d %d",&s,&v);
      for(int i=b; i>=s; i--)
	A[i] = max(A[i],A[i-s]+v);
    }
    int r = 0;
    for(int i=0; i<=b; i++)
      r = max(r,A[i]);
    printf("%d\n",r);
  }
}
