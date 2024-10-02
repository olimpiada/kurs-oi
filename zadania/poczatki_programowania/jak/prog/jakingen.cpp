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

const char *ZAD="jak";

void wypisz(int t,int a,int b,int c)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,t);
  freopen(nazwa,"w",stdout);
  printf("%d %d %d\n",a,b,c);
}

int main()
{
  // proste
  wypisz(1, 3,5,8);
  wypisz(2, 10,3,7);
  wypisz(3, 3,5,15);
  wypisz(4, 5,3,1);
  wypisz(5, 10,3,1);
  wypisz(6, 9,3,3);
  wypisz(7, 9,3,0);

  // z zerami
  wypisz(8, 1,0,1);
  wypisz(9, 1,0,0);
  wypisz(10, 0,1,1);
  wypisz(11, 0,1,0);
  wypisz(12, 1,1,0);
  wypisz(13, 0,0,0);

  // niejednoznaczny wynik
  wypisz(14, 2,2,4);
  wypisz(15, 5,3,2);
  wypisz(16, 4,2,2);
  wypisz(17, 8,3,2);

  // duze i maksymalne
  wypisz(18, 515,212,303);
  wypisz(19, 49,72,121);
  wypisz(21, 10,100,1000);
  wypisz(22, 1000,1,0);
  wypisz(23, 1000,2,0);
  wypisz(24, 1000,3,1);
  wypisz(25, 1000,201,196);
  wypisz(26, 1000-1,2,500-1);
  wypisz(27, 1000-2,2,500-1);
  wypisz(28, 0,1000,0);
  wypisz(29, 1000,0,1000);
  wypisz(30, 1000,1000,0);
  return 0;
}
