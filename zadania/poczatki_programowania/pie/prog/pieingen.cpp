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

const char *ZAD="pie";

Random RG;
int tst;

void wypisz(VI t,int x)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,tst);
  freopen(nazwa,"w",stdout);
  int n=SIZE(t);
  printf("%d %d\n",n,x);
  REP(i,n)
  {
    printf("%d",t[i]);
    if (i<n-1) putchar(' '); else puts("");
  }
  ++tst;
}

VI losowy(int n,int m)
{
  VI t;
  REP(i,n) t.PB(RG.rand()%m+1);
  return t;
}

const int N=100000;
const int MAX=1000000000;

int main()
{
  tst=1;
  RG.setSeed(214565);
  VI t;

  // bardzo male
  wypisz(VI(1,1),1);
  wypisz(VI(1,3),1);
  wypisz(VI(2,1),1);
  wypisz(VI(2,1),2);
  t.clear(); t.PB(1); t.PB(2);
  wypisz(t,1);
  wypisz(t,2);
  t.clear(); t.PB(1); t.PB(1); t.PB(1);
  wypisz(t,1);
  wypisz(t,2);

  // srednie
  wypisz(losowy(10,3),2);
  wypisz(losowy(100,10),10);

  // duze losowe
  wypisz(VI(N,MAX),MAX);
  wypisz(losowy(N,MAX),222333444);
  wypisz(losowy(N,1000),312);
  wypisz(losowy(N,10),1);

  // tylko na krancach
  t.clear();
  int a=RG.rand()%MAX+1,b=RG.rand()%MAX+1;
  t.PB(a); REP(i,N-2) t.PB(b); t.PB(a);
  wypisz(t,a);
  t[0]=b;
  wypisz(t,a);
  t[0]=a; t[N-1]=b;
  wypisz(t,a);
  t[0]=t[N-1]=b;
  wypisz(t,a);
  // jeden w srodku
  t[3*N/4]=a;
  wypisz(t,a);

  return 0;
}
