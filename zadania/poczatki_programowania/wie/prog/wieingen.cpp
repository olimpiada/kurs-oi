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

const char *ZAD="wie";

void wypisz(int t,int r)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,t);
  freopen(nazwa,"w",stdout);
  printf("%d\n",r);
}

int main()
{
  const int SZ=42;
  // wszystkie mozliwe odpowiedzi i wyjatki dla Gaussa
  int t[SZ]={
1812,
1814,
1818,
1822,
1860,
1863,
1880,
1886,
1916,
1926,
1929,
1933,
1935,
1940,
1943,
1952,
1954,
1981,
1984,
1998,
2035,
2038,
2049,
2051,
2064,
2073,
2076,
2077,
2092,
2095,
2106,
2112,
2120,
2133,
2140,
2153,
2160,
2166,
2168,
2175,
2181,
2190
  };
  REP(i,SZ) wypisz(i+1,t[i]);
  return 0;
}
