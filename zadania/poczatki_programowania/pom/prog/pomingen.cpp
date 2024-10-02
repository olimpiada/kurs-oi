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

const char *ZAD="pom";

Random RG;

void wypisz(int tst,VI t)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,tst);
  freopen(nazwa,"w",stdout);
  sort(ALL(t));
  FOR(i,1,SIZE(t)-1) t[i]-=t[0];
  t[0]=0;
  REP(i,SIZE(t)) printf("%d\n",t[i]);
  puts("-1");
}

void losowy(int tst,int n,int zakres,int wynik,bool max_tylko_jeden=false)
{
  assert(zakres+1>=wynik && n>=wynik);
  RG.setSeed(tst);
  set<int> zb;
  while (SIZE(zb)<wynik) zb.insert(RG.rand()%(zakres+1));
  VI t;
  FORE(it,zb) t.PB(*it);
  int k=SIZE(zb);
  k-=max_tylko_jeden;
  n-=max_tylko_jeden;
  FOR(i,k+1,n) t.PB(t[RG.rand()%k]);
  wypisz(tst,t);
}

const int MAX_N = 100000-1;
const int MAX_M = 1000000000;

int main()
{
  RG.setSeed(214565);

  losowy(1,1,0,1);
  losowy(2,2,0,1);
  losowy(3,2,10,2);

  losowy(4,30,20,8);
  losowy(5,101,MAX_M,95,true);
  losowy(6,2549,MAX_M,52);

  losowy(7,MAX_N-7,MAX_M,1);
  losowy(8,MAX_N-8,MAX_M,2);
  losowy(9,MAX_N,MAX_M,MAX_N/2,true);
  losowy(10,MAX_N,MAX_N-1,MAX_N);
  return 0;
}
