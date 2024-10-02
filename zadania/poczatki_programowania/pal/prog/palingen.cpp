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

const char *ZAD="pal";

Random RG;

void wypisz(int t,string s)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,t);
  freopen(nazwa,"w",stdout);
  printf("%s\n",s.c_str());
}

const int M=1000000;

string losowy(int n,int r)
{
  RG.setSeed(r);
  string s;
  REP(i,n) s+=char('a'+RG.rand()%26);
  return s;
}

string palindrom(int n,int r)
{
  int m=CEIL(n,2);
  string s=losowy(m,r);
  int j=n/2-1;
  while (j>=0)
  {
    s+=s[j];
    j--;
  }
  return s;
}

void zmien(char &ch)
{
  char ch1=ch;
  while (ch1==ch) ch=char('a'+RG.rand()%26);
}

int main()
{
  RG.setSeed(214565);
  wypisz(1,"t");
  wypisz(2,"ab");
  wypisz(3,"zz");
  wypisz(4,"ala");
  wypisz(5,"alx");
  wypisz(6,palindrom(1000,6));
  wypisz(7,palindrom(1000-1,7));
  wypisz(8,losowy(1000,8));
  wypisz(9,losowy(1000-1,9));
  wypisz(10,palindrom(M,10));
  wypisz(11,palindrom(M-1,11));
  wypisz(12,losowy(M,12));
  wypisz(13,losowy(M-1,13));
  string s=palindrom(M,14);
  string s1;

  s1=s;
  zmien(s1[0]);
  wypisz(14,s1);

  s1=s;
  zmien(s1[M/4]);
  wypisz(15,s1);

  s1=s;
  zmien(s1[M/2]);
  wypisz(16,s1);

  s=palindrom(M-1,17);

  s1=s;
  zmien(s1[0]);
  wypisz(17,s1);

  s1=s;
  zmien(s1[M/4]);
  wypisz(18,s1);

  s1=s;
  zmien(s1[M/2-3]);
  wypisz(19,s1);

  s1=s;
  zmien(s1[M/2-2]);
  wypisz(20,s1);

  return 0;
}
