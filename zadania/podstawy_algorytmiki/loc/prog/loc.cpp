#include <cstdio>
#include <queue>
#include <cassert>

using namespace std;

const int infty = 9999999;

typedef char str[1003];

str A[1003];
int dist[1003][1003];
int m, n;

queue<int> Q1,Q2;

void try_enter(int x, int y, int d)
{
  if (x>=m || y>=n || x<0 || y<0 || (A[x][y]=='#') || (dist[x][y]<infty))
    return;
  dist[x][y] = d+1;
  Q1.push(x);
  Q2.push(y);
  if (A[x][y]=='%' && dist[x][y] == infty)
  {
    dist[x][y] = d+1;
    Q1.push(x);
    Q2.push(y);
  }
}

int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    scanf("%d %d\n",&m,&n);
    for(int i=0; i<m; i++)
      scanf("%s\n",A[i]);
    int isStart = 0;
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
      {
        dist[i][j] = infty;
	if (A[i][j]=='@')
	{
	  isStart++;
	  dist[i][j] = 0;
	  Q1.push(i);
	  Q2.push(j);
	}
      }
    assert(isStart==1);
    while(!Q1.empty())
    {
      int x = Q1.front();
      int y = Q2.front();
      Q1.pop();
      Q2.pop();
      int d = dist[x][y];
      try_enter(x+1,y,d);
      try_enter(x-1,y,d);
      try_enter(x,y+1,d);
      try_enter(x,y-1,d);
    }
    int isFinish = 0;
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
        if (A[i][j]=='>')
	{
	  isFinish++;
	  if (dist[i][j]==infty)
	    printf("NIE\n");
	  else
	    printf("%d\n",dist[i][j]);
	}
    assert(isFinish==1);
  }
}

