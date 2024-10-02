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

const char *ZAD="nap";

Random RG;

void wypisz(int tst,int n,int mx)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,tst);
  freopen(nazwa,"w",stdout);
  printf("%d\n",n);
  REP(i,n)
  {
    printf("%d",RG.rand()%mx+1);
    if (i<n-1) putchar(' '); else puts("");
  }
}

int main()
{
  RG.setSeed(214565);
  wypisz(1,2,10);
  wypisz(2,3,10);
  wypisz(3,4,1000);
  wypisz(4,5,1000);
  wypisz(5,1000-1,1000);
  wypisz(6,1000,1000);
  wypisz(7,100000-1,1000);
  wypisz(8,100000,1000);
  return 0;
}
