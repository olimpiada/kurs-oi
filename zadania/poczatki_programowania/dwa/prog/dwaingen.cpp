/* Generator wejsc
 * Autor: Jakub Radoszewski
 */

#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<numeric>
#include<cassert>
using namespace std;

#include "oi.h"
using namespace oi;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define INFTY 100000000
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define SIZE(x) ((int)(x).size())

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef unsigned int uint;

ll nwd(ll a,ll b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }
template <class T> inline T sqr(const T&a) { return a*a; }

const char *ZAD="dwa";

typedef vector<VI> VVI;

VVI daj(int n,int m)
{
  VVI t(n);
  REP(i,n) t[i].resize(m);
  return t;
}

Random RG;

int test=0;

void wypisz(VVI t)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,++test);
  freopen(nazwa,"w",stdout);
  fprintf(stderr,"%s\n",nazwa);
  printf("%d %d\n",SIZE(t),SIZE(t[0]));
  REP(i,SIZE(t))
  {
    REP(j,SIZE(t[i]))
    {
      printf("%d",t[i][j]);
      if (j<SIZE(t[i])-1) putchar(' '); else puts("");
    }
  }
}

void losowy(int n,int m,int k)
{
  VVI t=daj(n,m);
  REP(i,n) REP(j,m) t[i][j]=RG.rand()%k+1;
  wypisz(t);
}

int main()
{
  RG.setSeed(214565);
  VVI t;

  // 2 x 2
  t=daj(2,2);
  REP(a,2) REP(b,2)
  {
    while (1)
    {
      REP(i,2) REP(j,2) t[i][j]=RG.rand()%10+1;
      if (t[a][0]>=t[1-a][0] || t[b][1] >= t[1-b][1]) continue;
      break;
    }
    wypisz(t);
  }

  // 3 x 3
  t=daj(3,3);
  REP(a,3) REP(b,3) REP(c,3)
  {
    while (1)
    {
      REP(i,3) REP(j,3) t[i][j]=RG.rand()%10+1;
      if (t[a][0] >= t[(a+1)%3][0] || t[a][0] >= t[(a+2)%3][0]) continue;
      if (t[b][1] >= t[(b+1)%3][1] || t[b][1] >= t[(b+2)%3][1]) continue;
      if (t[c][2] >= t[(c+1)%3][2] || t[c][2] >= t[(c+2)%3][2]) continue;
      break;
    }
    wypisz(t);
  }

  losowy(10,10,10);
  losowy(10,10,1000);

  losowy(100,100,2);
  losowy(100,100,20);
  losowy(100,100,1000);

  t=daj(100,100);
  REP(i,100) REP(j,100) t[i][j]=1000;
  wypisz(t);

  return 0;
}
