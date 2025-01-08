#include <cstdio>

const int N = 2000000;

bool isprime(int p)
{
    for(int i=2; i*i<=p; i++)
        if (p % i == 0)
            return false;
    return true;
}


int main()
{

  bool tablica[N+1];           // tablica[j] == false, jeśli liczba jest wykreślona, true jeśli nie jest
  long long prefix[N+1];

  for(int i = 2; i <= N; i++)
     tablica[i] = isprime(i);


  prefix[1] = 0;
  for(int i = 2; i <= N; i++)
    prefix[i] = prefix[i-1]+(tablica[i] ? i : 0);

  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%Ld\n",prefix[b] - prefix[a-1]);
  }

}
