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

const char *ZAD="cwi";

Random RG;

void wypisz(int t,int x,int y)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,t);
  freopen(nazwa,"w",stdout);
  printf("%d %d\n",x,y);
}

int main()
{
  int x,y;
  x=y=1;
  wypisz(1, x,y);
  wypisz(2, x,-y);
  wypisz(3, -y,x);
  wypisz(4, -x,-y);
  wypisz(5, 0,y);
  wypisz(6, 0,-y);
  wypisz(7, x,0);
  wypisz(8, -x,0);

  wypisz(9, 0,0);

  x=999999999; y=898989898;
  wypisz(10, x,y);
  wypisz(11, x,-y);
  wypisz(12, -y,x);
  wypisz(13, -x,-y);
  wypisz(14, 0,y);
  wypisz(15, 0,-y);
  wypisz(16, x,0);
  wypisz(17, -x,0);
  return 0;
}
