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

const char *ZAD="cza";

void wypisz(int t,int n)
{
  char nazwa[20];
  string s;
  while (t>0)
  {
    s+=char('a'+(t-1)%26);
    t=(t-1)/26;
  }
  reverse(ALL(s));
  sprintf(nazwa,"%s1%s.in",ZAD,s.c_str());
  freopen(nazwa,"w",stdout);
  printf("%d\n",n);
}

int main()
{
  wypisz(1,1);
  wypisz(2,40);
  wypisz(3,59);
  wypisz(4,60);
  wypisz(5,101);
  wypisz(6,119);
  wypisz(7,120);
  wypisz(8,60*34+3);
  wypisz(9,60*59);
  wypisz(10,60*59+59);
  wypisz(11,60*60);
  wypisz(12,60*60+59);
  wypisz(13,60*60+60);
  wypisz(14,2*60*60-1);
  wypisz(15,2*60*60);
  wypisz(16,2*60*60+1);
  wypisz(17,60*60*60-5);
  wypisz(18,60*60*60);
  wypisz(19,654321);
  wypisz(20,1000000);
  return 0;
}
