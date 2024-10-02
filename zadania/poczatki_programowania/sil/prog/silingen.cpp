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

const char *ZAD="sil";

Random RG;

void wypisz(int t,int n)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,t);
  freopen(nazwa,"w",stdout);
  printf("%d\n",n);
}

int main()
{
  wypisz(1,0);
  wypisz(2,1);
  wypisz(3,2);
  wypisz(4,4);
  wypisz(5,5);
  wypisz(6,6);
  wypisz(7,7);
  wypisz(8,8);
  wypisz(9,9);
  wypisz(10,10);
  wypisz(11,11);
  wypisz(12,12);
  return 0;
}
