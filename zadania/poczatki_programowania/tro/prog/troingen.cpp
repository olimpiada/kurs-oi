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

const char *ZAD="tro";

void wypisz(int t,int a,int b,int c)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,t);
  freopen(nazwa,"w",stdout);
  printf("%d %d %d\n",a,b,c);
}

const int MAX = 1000 * 1000 * 1000;

int main()
{
  wypisz(1, 1,1,1);
  wypisz(2, 10,10,10);

  int a,b,c;
  a=13; b=7;
  c=a+b-1;

  wypisz(3,a,b,c);
  wypisz(4,a,c,b);
  wypisz(5,b,a,c);
  wypisz(6,b,c,a);
  wypisz(7,c,a,b);
  wypisz(8,c,b,a);

  a=30; b=14;
  c=a+b;

  wypisz(9,a,b,c);
  wypisz(10,a,c,b);
  wypisz(11,b,a,c);
  wypisz(12,b,c,a);
  wypisz(13,c,a,b);
  wypisz(14,c,b,a);

  a=10; b=6;
  c=a+b+1;

  wypisz(15,a,b,c);
  wypisz(16,a,c,b);
  wypisz(17,b,a,c);
  wypisz(18,b,c,a);
  wypisz(19,c,a,b);
  wypisz(20,c,b,a);

  wypisz(21, MAX,1,1);
  wypisz(22, MAX,1,MAX);
  wypisz(23, MAX,MAX/2,MAX/2);
  wypisz(24, MAX,MAX/2+1,MAX/2);
  wypisz(25, MAX,MAX/2-1,MAX/2);
  wypisz(26, MAX-1,MAX-2,MAX);
  wypisz(27, MAX,MAX,MAX);
  return 0;
}
