/* Weryfikator wyjsc do zadania WIE (Wieze)
 * Autor: Jakub Radoszewski
 * Data: 25.04.2011
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


#include "oi.h"
using namespace oi;

const int M = 200000;

int n,s;
string t1[M];
int t2[M];

void endf(const char* msg, int line, int position)
{
  printf("WRONG\nWiersz %d: %s\n", line, msg);
  exit(1);
}

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    printf("Uruchomienie: %s in out wzo\n", argv[0]);
    return 1;
  }
  FILE *fin = fopen(argv[1], "r");
  fscanf(fin, "%d%d", &n,&s);
  REP(i,n)
  {
    char st[100];
    fscanf(fin,"%s",st);
    t1[i]=string(st);
    fscanf(fin,"%d",t2+i);
  }
  fclose(fin);

  FILE *fwzo = fopen(argv[3],"r");
  bool nie=false;
  char st[100],blad[200];
  fscanf(fwzo,"%s",st);
  if (!strcmp(st,"NIE")) nie=true;
  fclose(fwzo);

  Scanner *test = new Scanner(argv[2], endf, PL);
  if (nie)
  {
    int ile=test->readString(st,10);
    if (ile!=3 || strcmp(st,"NIE"))
    {
      sprintf(blad,"Oczekiwano NIE, a wczytano %s",st);
      test->error(blad);
    }
    puts("OK");
  } else
  {
    char a[100],b[100];
    int ile=test->readString(a,20);
    if (ile>10 || !ile) test->error("Zly napis 1");
    test->skipWhitespacesUntilEOLN();
    ile=test->readString(b,20);
    if (ile>10 || !ile) test->error("Zly napis 2");
    test->skipWhitespaces();
    test->readEof();

    string aa(a),bb(b);
    int s1=0,s2=0;
    REP(i,n) if (t1[i]==aa) s1=t2[i]; else if (t1[i]==bb) s2=t2[i];
    if (!s1 || !s2 || s1+s2!=s)
    {
      sprintf(blad,"Liczby %d i %d nie sumuja sie do %d",s1,s2,s);
      test->error(blad);
    }

    delete(test);
    puts("OK");
  }

  return 0;
}
