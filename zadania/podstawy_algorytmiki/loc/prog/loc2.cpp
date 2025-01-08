// Wzorcówka do trudniejszej wersji zadania, nie użytej na MAIN2

#include <cstdio>
#include <queue>
#include <cassert>

using namespace std;

const int infty = 9999999;

typedef char str[1003];

str A[1003];
int dist[1003][1003][2];
int m, n;

queue<int> Q1,Q2,Q3;

void try_enter(int x, int y, int p, int d)
{
  if (x>=m || y>=n || x<0 || y<0 || (A[x][y]=='#') || (dist[x][y][p]<infty))
    return;
  if (A[x][y]=='+' && p==1)
    return;
  if (A[x][y]=='o' && p==0)
    return;
//  printf("%d %d %d %d %c\n",x,y,p,d+1,A[x][y]);
  dist[x][y][p] = d+1;
  Q1.push(x);
  Q2.push(y);
  Q3.push(p);
}

void try_change(int x, int y, int p, int d)
{
  if (x>=m || y>=n || x<0 || y<0 || A[x][y]!='%' || dist[x][y][!p]<infty)
    return;
//  printf("%d %d %d %d\n",x,y,!p,d+1);
  dist[x][y][!p] = d+1;
  Q1.push(x);
  Q2.push(y);
  Q3.push(!p);
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
        dist[i][j][0] = dist[i][j][1] = infty;
	if (A[i][j]=='@')
	{
	  isStart++;
	  dist[i][j][0] = 0;
	  Q1.push(i);
	  Q2.push(j);
	  Q3.push(0);
	}
      }
    assert(isStart==1);
    while(!Q1.empty())
    {
      int x = Q1.front();
      int y = Q2.front();
      int p = Q3.front();
      Q1.pop();
      Q2.pop();
      Q3.pop();
      int d = dist[x][y][p];
      try_enter(x+1,y,p,d);
      try_enter(x-1,y,p,d);
      try_enter(x,y+1,p,d);
      try_enter(x,y-1,p,d);
      try_change(x+1,y,p,d);
      try_change(x-1,y,p,d);
      try_change(x,y+1,p,d);
      try_change(x,y-1,p,d);
    }
    int isFinish = 0;
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
        if (A[i][j]=='>')
	{
	  isFinish++;
	  if (dist[i][j][0]==infty)
	    printf("NIE\n");
	  else
	    printf("%d\n",dist[i][j][0]);
	}
    assert(isFinish==1);
/*    for(int i=0; i<m; i++)
    {
      for(int j=0; j<n; j++)
        printf("%4d",dist[i][j][0]);
      printf("\n");
    } */
  }
}

