#include <cstdio>
#include <algorithm>


const int MAXN = 1048576;
const int INFTY = 1000*1000*1000;
using namespace std;

int A[2*MAXN+1];

void update(int x)
{
  x/=2;
  if (x==0)
    return;
  A[x] = max(A[2*x],A[2*x+1]);
  update(x);
}

int query(int p, int q)
{
  if (p==q)
    return A[p];
  if (p>q)
    return -INFTY;
  int res = -INFTY;
  if (p%2==1)
  {
    res = max(res,A[p]);
    p++;
  }
  if (q%2==0)
  {
    res = max(res,A[q]);
    q--;
  }
  res = max(res,query(p/2,q/2));  
  return res;
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int M = 1;
    while(M<n)
      M *= 2;
    for(int i=1; i<=2*M; i++)
      A[i] = -INFTY;
    for(int i=1; i<=n; i++)
    {
      int x;
      scanf("%d",&x);
      A[M+i] = x;
      update(M+i);
    }
    for(int i=1; i<=q; i++)
    {
      char command[20];
      scanf("%s",command);
//      printf("%s\n",command);
      if (command[0]=='U')
      {
        int k,x;
        scanf("%d %d",&k,&x);
	A[M+k] = x;
	update(M+k);
      }
      if (command[0]=='M')
      {
        int k,l;
        scanf("%d %d",&k,&l);
	printf("%d\n",query(M+k,M+l));
      }
    }
}
