/**
 * Rozwiazanie alternatywne do zadania CZY
 * Zadanie: Czy sie zatrzyma
 * Autor: Wojciech Tyczynski
 * Data: 26.10.2011
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>
#include <stack>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef long long LL;
typedef long double LD;

#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FOREACH(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)

#define PB push_back
#define PF push_front
#define PI pair<int,int>
#define PD pair<LD,LD>
#define MP make_pair
#define FI first
#define SE second
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((int)(x).size())


// Implementacja struktury BigNum, realizujacej arytmetykê wielkich liczb
		
struct BigNum {
   // Redukowanie wiodacych zera
   #define REDUCE() while (len>1 && !cyf[len-1]) len--;

   // Baza oraz ilosc zer w reprezentacji podstawy
   static const int BASE=1000000000, BD=9;

   // Aktualna d³ugosæ liczby oraz ilosc zaalokowanej pamieci
   int len,al;

   // Wskaznik do tablicy cyfr liczby
   LL* cyf;

   // Konsrtuktor liczby o wartosci v i zaalokowanej pamiêci dla l cyfr
   BigNum(int v=0, int l=2) : len(1), al(l), cyf(new LL[l]) {
      REP(x,al) cyf[x]=0;
      if ((cyf[0]=v)>=BASE) przen(1);
   }

   // Konstruktor przypisujacy wartosæ innej liczby typu BigNum
   BigNum(const BigNum &a) : len(a.len), al(len), cyf(new LL[al]) {
      REP(x,al) cyf[x]=a.cyf[x];
   }

   // Destruktor
   ~BigNum() {
      delete cyf;
   }

   // Funkcja przyjmuje jako parametr zapotrzebowanie na ilo?æ cyfr i
   // je¿eli jest ono wiêksze od aktualnego rozmiar tablicy cyfr to realokuje
   void Res(int l) {
      if (l>al) {
	 LL* n=new LL[l=max(l,2*al)];
	 REP(x,l) n[x]=(x>=al)?0:cyf[x];
	 delete cyf;
	 cyf=n;
	 al=l;
      }
   }

   // Przenoszenie do starczysz cyfr nadmiaru powsta³ego na skutek operacji
   // parametr okre?la liczbê cyfry, do której nale¿y wykonaæ przenoszenie nadmiaru
   void przen(int p) {
      int x;
      for(x=0; x<p || cyf[x]<0 || cyf[x]>=BASE; x++) {
	 Res(x+2);
	 if (cyf[x]<0) {
	    LL i=(-cyf[x]-1)/BASE+1;
	    cyf[x]+=i*BASE; cyf[x+1]-=i;
	 } else if (cyf[x]>=BASE) {
	    LL i=cyf[x]/BASE;
	    cyf[x]-=i*BASE; cyf[x+1]+=i;
	 }
      }
      len=max(len,x+1);
      REDUCE();
   }


   // OPERATORY PORÓWNAWCZE

   // skrot zapisu naglowkow operatorow
   #define OPER1(op) bool operator op (const BigNum &a) const

   OPER1(==) {
      if (len!=a.len) return 0;
      REP(x,len) if (cyf[x]!=a.cyf[x]) return 0;
      return 1;
   }


   OPER1(<) {
      if (len!=a.len) return len<a.len;
      int x=len-1;
      while (x && cyf[x]==a.cyf[x]) x--;
      return cyf[x]<a.cyf[x];
   }

   OPER1(>) {
      return a<*this;
   }

   OPER1(<=) {
      return !(a<*this);
   }

   OPER1(>=) {
      return !(*this<a);
   }

   OPER1(!=) {
      return !(*this==a);
   }


   // OPERATORY DLA LICZB TYPU INT
   

   BigNum &operator=(int a) {
      REP(x,len) cyf[x]=0;
      len=1;
      if ((cyf[0]=a)>=BASE) przen(1);
      return *this;
   }

   void operator+=(int a) {
      cyf[0]+=a;
      przen(1);
   }

   void operator-=(int a) {
      cyf[0]-=a;
      przen(1);
   }

   void operator*=(int a) {
      REP(x,len) cyf[x]*=a;
      przen(len);
   }

   // Poni¿szy operator zwraca jako wynik resztê z dzielenia
   int operator/=(int a) {
      LL w=0;
      FORD(p,len-1,0) {
	 w=w*BASE+cyf[p];
	 cyf[p]=w/a;
	 w%=a;
      }
      REDUCE();
      return w;
   }

   int operator%(int a) {
      LL w=0;
      FORD(p,len-1,0) w=(w*BASE+cyf[p])%a;
      return w;
   }


   // OPERATORY NA BIGNUMACH

   #define OPER2(op) BigNum& operator op (const BigNum &a)

   OPER2(+=) {
      Res(a.len);
      REP(x,a.len) cyf[x]+=a.cyf[x];
      przen(a.len);
      return *this;
   }

   OPER2(-=) {
      REP(x,a.len) cyf[x]-=a.cyf[x];
      przen(a.len);
      return *this;
   }

   OPER2(*=) {
      BigNum c(0,len+a.len);
      REP(x,a.len) {
	 REP(y,len) c.cyf[y+x]+=cyf[y]*a.cyf[x];
	 c.przen(len+x);
      }
      *this=c;
      return *this;
   }

   // operator ten wymaga implementacji operatorow: <(BigNum),
   // +=(BigNum), *=(BigNum), +(Bignum), *(BigNum), <<(int), <<=(int)
   OPER2(/=) {
      int n=max(len-a.len+1,1);
      BigNum d(0,n), prod(0,n);
      FORD(i,n-1,0) {
	 int l=0,r=BASE-1;
	 while (l<r) {
	    int m=(l+r+1)/2;
	    if (*this<prod+(a*m<<i)) r=m-1;
	    else l=m;
	 }
	 prod+=a*l<<i;
	 d.cyf[i]=l;
	 if (l) d.len=max(d.len,i+1);
      }
      *this=d;
      return *this;
   }

   // operator ten wymaga implementacji operatorow: <(BigNum),
   // +=(BigNum), *=(BigNum), +(Bignum), *(BigNum), <<(BigNum), <<=(BigNum)
   OPER2(%=) {
      BigNum v=*this;
      v/=a;
      v*=a;
      *this-=v;
      return *this;
   }


   OPER2(=) {
      Res(a.len);
      FORD(x,len-1,a.len) cyf[x]=0;
      REP(x,a.len) cyf[x]=a.cyf[x];
      len=a.len;
      return *this;
   }


   // WCZYTYWANIE I WYPISYWANIE
   
   // operator wymaga implementacji +=(int), *=(int);
   // przypisuje liczbie BigNum warto?æ liczby z przekazanego wektora
   // zapisanej przy podstawie p
   void read(const VI &v, int p) {
      *this=0;
      FORD(x,SIZE(v),0) {
	 *this*=p;
	 *this+=v[x];
      }
   }

   // operator wymaga implementacji =(int)
   // przypisuje liczbie BigNum warto?æ liczby z napisu zapisanego przy podstawie 10
   BigNum &operator=(string a) {
      int s=a.length();
      *this=0;
      Res(len=s/BD+1);
      REP(x,s) cyf[(s-x-1)/BD]=10*cyf[(s-x-1)/BD]+a[x]-'0';
      REDUCE();
      return *this;
   }

   // wypisuje warto?æ liczby BigNum zapisanej przy podstawie 10
   void write() const {
      printf("%d",int(cyf[len-1]));
      FORD(x,len-2,0) printf("%0*d",BD,int(cyf[x]));
   }

   // wypisuje do bufora warto?æ liczby przy podstawie 10
   void write(char *buf) const {
      int p=sprintf(buf,"%d",int(cyf[len-1]));
      FORD(x,len-2,0) p+=sprintf(buf+p,"%0*d",BD,int(cyf[x]));
   }
   
   // operator wymaga implementacji /=(int), =(BigNum)
   // zwraca wektor cyfr liczby zapisanej przy podstawie pod
   VI write(int pod) const {
      VI w;
      BigNum v;
      v=*this;
      while (v.len>1 || v.cyf[0]) w.PB(v/=pod);
      return w;
   }


   // PRZESUNIECIA

   BigNum &operator>>=(int n) {
      if (n>len) n=len;
      REP(x,len-n) cyf[x]=cyf[x+n];
      FOR(x,len-n,n) cyf[x]=0;
      len-=n;
      if (len==0) len=1;
      return *this;
   }

   BigNum &operator<<=(int n) {
      if (cyf[0]==0 && len==1) return *this;
      Res(len+n);
      FORD(x,len-1,0) cyf[x+n]=cyf[x];
      REP(x,n) cyf[x]=0;
      len+=n;
      return *this;
   }


   // PIERWIASTEK

   // operator wymaga implementacji <(BigNum) +=(BigNum), *=(BigNum), <<=(int),
   // +(BigNum), *(BigNum), <<(int)
   BigNum sqrt() {
      int n=(len+1)/2;
      BigNum a(0,n), sq;
      FORD(i,n-1,0) {
	 int l=0,r=BASE-1;
	 while (l<r) {
	    int m=(l+r+1)/2;
	    if (*this<sq+(a*2*m<<i)+(BigNum(m)*m<<2*i)) r=m-1;
	    else l=m;
	 }
	 sq+=(a*2*l<<i)+(BigNum(l)*l<<2*i);
	 a.cyf[i]=l,a.len=n;
      }
      return a;
   }


   // DZIA£ANIA

   #define OPER3(op) BigNum operator op(const BigNum &a) const {BigNum w=*this; w op ## = a; return w; }
   #define OPER4(op) BigNum operator op(int a) {BigNum w=*this; w op ## = a; return w; }

   // wymaga implementacji +=(BigNum)
   OPER3(+);

   // wymaga implementacji -=(BigNum)
   OPER3(-);

   // wymaga implementacji *=(BigNum)
   OPER3(*);

   // wymaga implementacji <(BigNum), +=(BigNum), *=(BigNum), /=(BigNum),
   // +(BigNum), *(BigNum), <<(int)
   OPER3(/);

   // wymaga implementacji <(BigNum), +=(BigNum), -=(BigNum), *=(BigNum),
   // =(BigNum), %=(BigNum), +(BigNum), *(BigNum)
   OPER3(%);

   // wymaga implementacji <<=(int)
   OPER4(<<);

   // wymaga implementacji >>=(int)
   OPER4(>>);
};


char A[25];
string s;

int main() {
  scanf("%s", A), s = A;
  BigNum n;
  n = s;
  BigNum zero = BigNum(0);
  BigNum one = BigNum(1);
  BigNum two = BigNum(2);
  BigNum three = BigNum(3);

  while (n != one && n != three) {
    if (n % two == zero) {
      n /= 2;
    } else {
      n = n * 3 + 3;
    }
  }

  if (n == one) {
    printf("TAK\n");
  } else {
    printf("NIE\n");
  }
  return 0;
}

