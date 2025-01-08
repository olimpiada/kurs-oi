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

const char *ZAD="sad";

Random RG;

void wypisz(int tst,vector<PII> t,bool shuffle)
{
  char nazwa[20];
  sprintf(nazwa,"%s%d.in",ZAD,tst);
  freopen(nazwa,"w",stdout);
  fprintf(stderr,"%s\n",nazwa);
  if (shuffle) RG.randomShuffle(ALL(t));
  printf("%d\n",SIZE(t));
  REP(i,SIZE(t))
    printf("%d %d\n",t[i].FI,t[i].SE);
}

void cztery_rogi_i_nic(int nr,int n,int min_x,int max_x,int min_y,int max_y)
{
  RG.setSeed(nr);
  if (n>4)
  {
    assert(max_x>min_x+1);
    assert(max_y>min_y+1);
  }
  assert(n>=4);
  set<PII> zb;
  zb.insert(MP(min_x,min_y));
  zb.insert(MP(min_x,max_y));
  zb.insert(MP(max_x,min_y));
  zb.insert(MP(max_x,max_y));
  while (SIZE(zb)<n)
    zb.insert(MP(min_x+1+RG.rand()%(max_x-min_x-1), min_y+1+RG.rand()%(max_y-min_y-1)));
  vector<PII> t;
  FORE(it,zb) t.PB(*it);
  wypisz(nr,t,true);
}

void dwa_rogi_i_nic_1(int nr,int n,int min_x,int max_x,int min_y,int max_y)
{
  RG.setSeed(nr);
  if (n>2)
  {
    assert(max_x>min_x+1);
    assert(max_y>min_y+1);
  }
  assert(n>=2);
  set<PII> zb;
  zb.insert(MP(min_x,min_y));
  zb.insert(MP(max_x,max_y));
  while (SIZE(zb)<n)
    zb.insert(MP(min_x+1+RG.rand()%(max_x-min_x-1), min_y+1+RG.rand()%(max_y-min_y-1)));
  vector<PII> t;
  FORE(it,zb) t.PB(*it);
  wypisz(nr,t,true);
}

void dwa_rogi_i_nic_2(int nr,int n,int min_x,int max_x,int min_y,int max_y)
{
  RG.setSeed(nr);
  if (n>2)
  {
    assert(max_x>min_x+1);
    assert(max_y>min_y+1);
  }
  assert(n>=2);
  set<PII> zb;
  zb.insert(MP(min_x,max_y));
  zb.insert(MP(max_x,min_y));
  while (SIZE(zb)<n)
    zb.insert(MP(min_x+1+RG.rand()%(max_x-min_x-1), min_y+1+RG.rand()%(max_y-min_y-1)));
  vector<PII> t;
  FORE(it,zb) t.PB(*it);
  wypisz(nr,t,true);
}

void same_brzegi_z_rogami(int nr,int n,int min_x,int max_x,int min_y,int max_y)
{
  RG.setSeed(nr);
  assert(n>=4);

  set<PII> zb;
  zb.insert(MP(min_x,min_y));
  zb.insert(MP(min_x,max_y));
  zb.insert(MP(max_x,min_y));
  zb.insert(MP(max_x,max_y));
  while (SIZE(zb)<n)
  {
    int opcja=RG.rand()%4;
    int x,y;
    if (opcja==0)
    {
      x=min_x;
      y=min_y+1+RG.rand()%(max_y-min_y-1);
    } else if (opcja==1)
    {
      x=max_x;
      y=min_y+1+RG.rand()%(max_y-min_y-1);
    } else if (opcja==2)
    {
      y=min_y;
      x=min_x+1+RG.rand()%(max_x-min_x-1);
    } else
    {
      y=max_y;
      x=min_x+1+RG.rand()%(max_x-min_x-1);
    }
    if (!zb.count(MP(x,y)))
    {
      zb.insert(MP(x,y));
    }
  }
  vector<PII> t;
  FORE(it,zb) t.PB(*it);
  wypisz(nr,t,true);
  return;
}

void same_brzegi_bez_rogow(int nr,int n,int min_x,int max_x,int min_y,int max_y)
{
  RG.setSeed(nr);
  assert(n>=4);
  while (1)
  {
    set<PII> zb;
    int bylo=0;
    while (SIZE(zb)<n)
    {
      int opcja=RG.rand()%4;
      int x,y;
      if (opcja==0)
      {
        x=min_x;
        y=min_y+1+RG.rand()%(max_y-min_y-1);
      } else if (opcja==1)
      {
        x=max_x;
        y=min_y+1+RG.rand()%(max_y-min_y-1);
      } else if (opcja==2)
      {
        y=min_y;
        x=min_x+1+RG.rand()%(max_x-min_x-1);
      } else
      {
        y=max_y;
        x=min_x+1+RG.rand()%(max_x-min_x-1);
      }
      if (!zb.count(MP(x,y)))
      {
        zb.insert(MP(x,y));
        bylo |= (1<<opcja);
      }
    }
    if (bylo==15)
    {
      vector<PII> t;
      FORE(it,zb) t.PB(*it);
      wypisz(nr,t,true);
      return;
    }
  }
}

void cztery_brzegi_i_nic(int nr,int n,int min_x,int max_x,int min_y,int max_y)
{
  RG.setSeed(nr);
  assert(n>=4);

  set<PII> zb;
  REP(opcja,4)
  {
    int x,y;
    if (opcja==0)
    {
      x=min_x;
      y=min_y+1+RG.rand()%(max_y-min_y-1);
    } else if (opcja==1)
    {
      x=max_x;
      y=min_y+1+RG.rand()%(max_y-min_y-1);
    } else if (opcja==2)
    {
      y=min_y;
      x=min_x+1+RG.rand()%(max_x-min_x-1);
    } else
    {
      y=max_y;
      x=min_x+1+RG.rand()%(max_x-min_x-1);
    }
    zb.insert(MP(x,y));
  }
  while (SIZE(zb)<n)
    zb.insert(MP(min_x+1+RG.rand()%(max_x-min_x-1), min_y+1+RG.rand()%(max_y-min_y-1)));
  vector<PII> t;
  FORE(it,zb) t.PB(*it);
  wypisz(nr,t,true);
}

void specyficzny(int nr,int n,bool xy,bool kier)
{
  RG.setSeed(nr);
  vector<PII> t;
  REP(i,n-1) t.PB(MP(i,0));
  t.PB(MP(n,1));
  if (xy) REP(i,n) swap(t[i].FI,t[i].SE);
  if (kier) reverse(ALL(t));
  wypisz(nr,t,false);
}

const int MAX_N=100000;
const int MAX=1000000;

int main()
{
  dwa_rogi_i_nic_1(1,2,3,5,4,7);
  dwa_rogi_i_nic_2(2,2,3,5,4,7);
  cztery_rogi_i_nic(3,4,0,1,0,1);
  same_brzegi_bez_rogow(4,4,1,10,100,110);
  dwa_rogi_i_nic_1(5,10,2,10,1,10);
  cztery_rogi_i_nic(6,20,500,5000,100,1000);
  same_brzegi_bez_rogow(7,100,0,1000,0,1000);
  cztery_brzegi_i_nic(8,1000,100000,200000,300000,400000);
  specyficzny(9,10000,false,false);

  dwa_rogi_i_nic_1(11,MAX_N,0,MAX,0,MAX);
  dwa_rogi_i_nic_2(12,MAX_N,MAX-5000,MAX,MAX-5000,MAX);
  cztery_rogi_i_nic(13,MAX_N,51551,551155,454647,987789);
  same_brzegi_bez_rogow(14,MAX_N,149,10099,8880,888080);
  same_brzegi_z_rogami(15,MAX_N-1,1490,100990,888,88808);
  cztery_brzegi_i_nic(16,MAX_N,100900,200000,300000,480000);
  specyficzny(17,MAX_N,false,false);
  specyficzny(18,MAX_N,false,true);
  specyficzny(19,MAX_N,true,false);
  specyficzny(20,MAX_N,true,true);
  return 0;
}
