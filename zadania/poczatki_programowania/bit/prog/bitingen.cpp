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

const char *ZAD="bit";

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

void all_perm(VI t)
{
  sort(ALL(t));
  do
  {
    wypisz(t);
  } while (next_permutation(ALL(t)));
}

void staly(int n,int m)
{
  VI t(n,m);
  wypisz(t);
}

void rosnacy(int n,int m)
{
  VI t;
  REP(i,m) t.PB(i+1);
  while (SIZE(t)>n)
  {
    swap(t[RG.rand()%SIZE(t)],t.back());
    t.pop_back();
  }
  sort(ALL(t));
  wypisz(t);
}

void malejacy(int n,int m)
{
  VI t;
  REP(i,m) t.PB(i+1);
  while (SIZE(t)>n)
  {
    swap(t[RG.rand()%SIZE(t)],t.back());
    t.pop_back();
  }
  sort(ALL(t));
  reverse(ALL(t));
  wypisz(t);
}

void niemalejacy(int n,int m)
{
  VI t;
  REP(i,n) t.PB(RG.rand()%m+1);
  sort(ALL(t));
  wypisz(t);
}

void nierosnacy(int n,int m)
{
  VI t;
  REP(i,n) t.PB(RG.rand()%m+1);
  sort(ALL(t));
  reverse(ALL(t));
  wypisz(t);
}

void losowy(int n)
{
  VI t;
  FOR(i,1,n) t.PB(i);
  RG.randomShuffle(ALL(t));
  wypisz(t);
}

VI rosn(int n,int m)
{
  VI t;
  REP(i,m) t.PB(i+1);
  while (SIZE(t)>n)
  {
    swap(t[RG.rand()%SIZE(t)],t.back());
    t.pop_back();
  }
  sort(ALL(t));
  return t;
}

void bitoniczny(int n,int m,int p,int zaburz=0,int gdzie=-1)
{
  VI t1=rosn(p+1,m), t2=rosn(n-p,m);
  if (t2.back()<t1.back()) t2.pop_back(); else t1.pop_back();
  reverse(ALL(t2));
  REP(i,SIZE(t2)) t1.PB(t2[i]);
  if (zaburz==1)
  {
    int i=RG.rand()%p;
    if (gdzie!=-1) i=gdzie;
    t1[i]=t1[i+1];
  } else if (zaburz==2)
  {
    int i=RG.rand()%p;
    if (gdzie!=-1) i=gdzie;
    t1[i]=t1[i+1]+1;
  } else if (zaburz==3)
  {
    int i=n-1-RG.rand()%(n-p-1);
    if (gdzie!=-1) i=gdzie;
    t1[i]=t1[i-1];
  } else if (zaburz==4)
  {
    int i=n-1-RG.rand()%(n-p-1);
    if (gdzie!=-1) i=gdzie;
    t1[i]=t1[i-1]+1;
  }
  wypisz(t1);
}

void antybitoniczny(int n,int m,int p)
{
  VI t1=rosn(p+1,m), t2=rosn(n-p,m);
  reverse(ALL(t1)); reverse(ALL(t2));
  if (t2.back()<t1.back()) t1.pop_back(); else t2.pop_back();
  reverse(ALL(t2));
  REP(i,SIZE(t2)) t1.PB(t2[i]);
  wypisz(t1);
}

const int MAX_N=500000;
const int MAX_M=1000000;

int main()
{
  RG.setSeed(214565);

  VI t;
  // male
  t.clear(); t.PB(1); all_perm(t);
  t.clear(); t.PB(1); t.PB(2); all_perm(t);
  t.clear(); FOR(i,1,3) t.PB(i); all_perm(t);
  t.clear(); t.PB(1); t.PB(1); t.PB(2); all_perm(t);
  t.clear(); t.PB(1); t.PB(2); t.PB(2); all_perm(t);
  // test 3, 3, 3 jest w ocen

  // tak
  bitoniczny(10,20,2);

  // nie
  antybitoniczny(10,20,2);
  FOR(i,1,4) bitoniczny(10,20,4,i, i<=2 ? 0 : 10-1);

  staly(MAX_N,MAX_M);
  rosnacy(MAX_N,MAX_M);
  malejacy(MAX_N,MAX_M);
  nierosnacy(MAX_N,MAX_M);
  niemalejacy(MAX_N,MAX_M);
  losowy(MAX_N);

  // tak
  bitoniczny(MAX_N,MAX_M,1);
  bitoniczny(MAX_N,MAX_M,2);
  bitoniczny(MAX_N,MAX_M,MAX_N/3);
  bitoniczny(MAX_N,MAX_M,MAX_N/2);
  bitoniczny(MAX_N,MAX_M,2*MAX_N/3);
  bitoniczny(MAX_N,MAX_M,MAX_N-2);

  // nie
  FOR(i,1,4) bitoniczny(MAX_N,MAX_M,MAX_N/2,i);
  antybitoniczny(MAX_N,MAX_M,MAX_N/2);
  antybitoniczny(MAX_N,MAX_M,MAX_N-2);
  return 0;
}
