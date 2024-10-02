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

const char *ZAD="nwd";

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

void losowy(int n,int m)
{
  VI t;
  REP(i,n) t.PB(RG.rand()%m+1);
  wypisz(t);
}

void rowny(int n,int m,int poz=-1,int war=-1)
{
  VI t(n,m);
  if (poz!=-1) t[poz]=war;
  wypisz(t);
}

void potegi2(int n)
{
  VI t;
  REP(i,n) t.PB(1<<(RG.rand()%8+2));
  wypisz(t);
}

void losowy_nwd(int n,int d)
{
  VI t;
  REP(i,n) t.PB(d*(RG.rand()%(1000/d)+1));
  wypisz(t);
}

const int M=1000;

int main()
{
  RG.setSeed(214565);

  // n==2
  rowny(2,1);
  rowny(2,2);
  rowny(2,2,0,1);
  rowny(2,2,1,1);
  rowny(2,20,0,10);
  rowny(2,20,1,10);

  VI t;
  t.clear(); t.PB(2*3); t.PB(3*5); t.PB(2*5);
  wypisz(t);

  losowy(10,100);
  rowny(10,9);
  potegi2(10);
  losowy_nwd(10,71);

  // max
  losowy(M,10);
  losowy(M,M);
  rowny(M,M);
  rowny(M,M,0,M/10);
  rowny(M,M,700,M/10);
  rowny(M,M,M-1,M/10);
  potegi2(M);
  losowy_nwd(1000,30);
  losowy_nwd(1000,500);
  return 0;
}
