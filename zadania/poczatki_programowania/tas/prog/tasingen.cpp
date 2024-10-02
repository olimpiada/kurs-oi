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

const char *ZAD="tas";

Random RG;

int test=0;

void wypisz(VI t)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,++test);
  freopen(nazwa,"w",stdout);
  fprintf(stderr,"%s\n",nazwa);
  printf("%d\n",SIZE(t));
  REP(i,SIZE(t))
  {
    printf("%d",t[i]);
    if (i<SIZE(t)-1) putchar(' '); else puts("");
  }
}

const int MAX_N=500000;
const int M=1000000000;

void przeskaluj(VI t,int m)
{
  int n=SIZE(t);
  VI x=t;
  sort(ALL(x));
  x.erase(unique(ALL(x)),x.end());
  set<int> zb;
  while (SIZE(zb)<SIZE(x)) zb.insert(RG.rand()%m+1);
  VI pom;
  FORE(it,zb) pom.PB(*it);

  vector<PII> tab;
  REP(i,n) tab.PB(MP(t[i],i));
  sort(ALL(tab));
  int start=0;
  int i=0;
  while (i<n)
  {
    int i0=i;
    while (i0<n && tab[i0].FI==tab[i].FI) t[tab[i0++].SE]=pom[start];
    ++start;
    i=i0;
  }
  wypisz(t);
}

VI staly_poza_1(int n,int j)
{
  VI t;
  t.resize(n,1);
  t[j]=2;
  return t;
}

VI w_srodku_losowo(int n,int lewo,int prawo,int m)
{
  assert(lewo>0 && prawo>0);
  VI t(n,0);
  FOR(i,lewo,n-prawo-1) t[i]=RG.rand()%m;
  while (t[lewo]==t[lewo-1]) t[lewo]=RG.rand()%m;
  while (t[n-prawo-1]==t[n-prawo]) t[n-prawo-1]=RG.rand()%m;
  return t;
}

int main()
{
  RG.setSeed(214565);
  VI t;

  // 1
  wypisz(VI(1,9));
  wypisz(VI(1,M));

  // 2
  t.clear(); t.PB(1); t.PB(2); wypisz(t);
  reverse(ALL(t)); wypisz(t);
  wypisz(VI(2,1));

  // 10
  przeskaluj(staly_poza_1(10,0),10);
  przeskaluj(staly_poza_1(10,1),10);
  przeskaluj(staly_poza_1(10,4),10);
  przeskaluj(staly_poza_1(10,8),10);
  przeskaluj(staly_poza_1(10,9),10);
  przeskaluj(w_srodku_losowo(10,2,3,10),10);
  przeskaluj(w_srodku_losowo(11,4,2,10),10);
  przeskaluj(w_srodku_losowo(11,1,2,2),10);
  przeskaluj(w_srodku_losowo(10,3,1,2),10);

  // MAX_N
  wypisz(VI(MAX_N,M));
  t.clear(); REP(i,MAX_N) t.PB(RG.rand()%M); wypisz(t);
  przeskaluj(staly_poza_1(MAX_N,0),M);
  przeskaluj(staly_poza_1(MAX_N,1),M);
  przeskaluj(staly_poza_1(MAX_N,MAX_N/3),M);
  przeskaluj(staly_poza_1(MAX_N-1,MAX_N/2),M);
  przeskaluj(staly_poza_1(MAX_N,2*MAX_N/3),M);
  przeskaluj(staly_poza_1(MAX_N,MAX_N-1),M);
  przeskaluj(w_srodku_losowo(MAX_N,MAX_N/5,MAX_N/4,M),M);
  przeskaluj(w_srodku_losowo(MAX_N,MAX_N/5,MAX_N/10,M),M);
  przeskaluj(w_srodku_losowo(MAX_N,MAX_N/2-1000,MAX_N/2-999,M),M);
  przeskaluj(w_srodku_losowo(MAX_N,MAX_N/2-998,MAX_N/2-999,2),M);
  przeskaluj(w_srodku_losowo(MAX_N,MAX_N/2-2000,MAX_N/2-1999,2),M);
  return 0;
}
