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

const char *ZAD="wic";

Random RG;

int test=0;

void wypisz(VI t)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,++test);
  freopen(nazwa,"w",stdout);
  printf("%d\n",SIZE(t));
  REP(i,SIZE(t))
  {
    printf("%d",t[i]);
    if (i<SIZE(t)-1) putchar(' '); else puts("");
  }
}

const int MAX_N=1000;
const int M=1000000;

void przeskaluj(VI t,int m)
{
  int n=SIZE(t);
  assert(n<=m);
  set<int> zb;
  while (SIZE(zb)<n) zb.insert(RG.rand()%m+1);
  VI pom;
  FORE(it,zb) pom.PB(*it);

  vector<PII> tab;
  REP(i,n) tab.PB(MP(t[i],i));
  sort(ALL(tab));
  REP(i,n) t[tab[i].SE]=pom[i];
  wypisz(t);
}

VI rosnacy(int n)
{
  VI t;
  FOR(i,1,n) t.PB(i);
  return t;
}

VI malejacy(int n)
{
  VI t;
  FORD(i,n,1) t.PB(i);
  return t;
}

VI losowy(int n)
{
  VI t;
  FOR(i,1,n) t.PB(i);
  RG.randomShuffle(ALL(t));
  return t;
}

VI losowy_duze(int n,int m)
{
  VI t;
  FOR(i,1,n) t.PB(m+1-i);
  RG.randomShuffle(ALL(t));
  return t;
}

VI specyficzny(int n)
{
  VI t;
  int i=n/2,j=i+1;
  while (i>0 || j<=n)
  {
    if (i>0) t.PB(i);
    i--;
    if (j<=n) t.PB(j);
    j++;
  }
  return t;
}

int main()
{
  RG.setSeed(214565);

  przeskaluj(rosnacy(2),5);
  przeskaluj(malejacy(2),10);
  przeskaluj(rosnacy(3),1000);
  przeskaluj(malejacy(3),1000);

  przeskaluj(losowy(10),1000);
  
  VI t=rosnacy(10);
  swap(t[0],t[8]);
  przeskaluj(t,10);

  przeskaluj(specyficzny(10),10);
  t=specyficzny(10);
  reverse(ALL(t));
  przeskaluj(t,10);

  przeskaluj(rosnacy(MAX_N),M);
  przeskaluj(malejacy(MAX_N),M);
  przeskaluj(losowy(MAX_N),M);
  wypisz(losowy_duze(MAX_N,M));

  t=rosnacy(MAX_N);
  swap(t[0],t[MAX_N-2]);
  przeskaluj(t,M/5);

  przeskaluj(specyficzny(MAX_N),100000);
  t=specyficzny(MAX_N);
  reverse(ALL(t));
  przeskaluj(t,100000);
  return 0;
}
