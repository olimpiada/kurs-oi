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

const char *ZAD="duz";

Random RG;

int test;

string oper[6]={"==","!=","<",">","<=",">="};

void wypisz(string a,string b)
{
  REP(i,6)
  {
    char nazwa[20];
    sprintf(nazwa,"%s%d.in",ZAD,test++);
    freopen(nazwa,"w",stdout);
    printf("%s %s %s\n",a.c_str(),oper[i].c_str(),b.c_str());
  }
  if (a==b) return;
  swap(a,b);
  REP(i,6)
  {
    char nazwa[20];
    sprintf(nazwa,"%s%d.in",ZAD,test++);
    freopen(nazwa,"w",stdout);
    printf("%s %s %s\n",a.c_str(),oper[i].c_str(),b.c_str());
  }
}

int main()
{
  RG.setSeed(214565);
  test=1;

  wypisz("1","1");
  wypisz("5","7");
  wypisz("7","44");
  wypisz("19","90");

  string a=string("1")+string(1000,'0');
  wypisz(a,a);
  string b="9";
  wypisz(b,a);

  a="";
  REP(i,1000) a+=char('0'+RG.rand()%10);
  a[0]='6';
  a[999]='4';
  b=a;
  b[999]='3';
  wypisz(a,b);

  a[300]='8';
  b=a;
  b[300]='9';
  wypisz(a,b);

  a="";
  REP(i,1000) a+=char('0'+RG.rand()%10);
  a[0]='2';
  b="";
  REP(i,1000) b+=char('0'+RG.rand()%10);
  b[0]='6';
  wypisz(a,b);


  return 0;
}
