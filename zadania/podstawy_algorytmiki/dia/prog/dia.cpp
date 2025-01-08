#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1003;

int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int w,h;
	int A[maxn][maxn],D[maxn][maxn];
    scanf("%d %d",&w,&h);
	for(int i=1; i<=h; i++)
	  for(int j=1; j<=w; j++)
	    scanf("%d",&D[i][j]);
	for(int i=0; i<=h; i++)
	  for(int j=0; j<=w; j++)
	    A[i][j] = 0;
	for(int i=1; i<=h; i++)
	  for(int j=1; j<=w; j++)
	    A[i][j] = max(A[i-1][j],A[i][j-1])+D[i][j];
	printf("%d\n",A[h][w]);
  }
}