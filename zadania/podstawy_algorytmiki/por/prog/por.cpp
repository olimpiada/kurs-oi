#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 200200;
const int infty = 1000*1001;

vector<int> G[maxn];
int dist[maxn];

void BFS(int u)
{
  queue<int> Q;
  dist[u] = 0;
  Q.push(u);
  while(!Q.empty())
  {
    int x = Q.front();
    Q.pop();
    for(int i=0; i<(int)G[x].size(); i++)
    {
      int v = G[x][i];
      if (dist[v]==infty)
      {
        dist[v] = dist[x]+1;
	Q.push(v);
      }
    }
  }
}


int main()
{
  int TT,n,m;
  scanf("%d",&TT);
  while(TT--)
  {
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
      int a,b;
      scanf("%d %d",&a,&b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    int p;
    scanf("%d",&p);
    for(int i=1; i<=n; i++)
      dist[i] = infty;
    BFS(p);
    printf("Znajomi numeru %d:\n",p);
    for(int i=1; i<=n; i++)
      if (dist[i]<infty && i!=p)
        printf("%d: %d\n",i,dist[i]);
    int r = 1;
    for(int i=1; i<=n; i++)
      if (dist[i]==infty)
      {
        r++;
	BFS(i);
      }
    printf("Grup znajomych jest %d.\n",r);
    for(int i=1; i<=n; i++)
      G[i].clear();
  }
}
