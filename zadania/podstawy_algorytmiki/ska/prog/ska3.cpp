#include <cstdio>
#include <algorithm>

using namespace std;

int A[2][10002];

int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int n,b;
    scanf("%d %d",&n,&b);
    for(int i=0; i<=b; i++)
      A[0][i] = 0;
    for(int j=0; j<n; j++)
    {
      int s,v;
      scanf("%d %d",&s,&v);
      for(int i=0; i<=b; i++)
	A[(j+1)%2][i] = max(A[j%2][i],i<s ? 0 : A[j%2][i-s]+v);
    }
    int r = 0;
    for(int i=0; i<=b; i++)
      r = max(r,A[n%2][i]);
    printf("%d\n",r);
  }
}
