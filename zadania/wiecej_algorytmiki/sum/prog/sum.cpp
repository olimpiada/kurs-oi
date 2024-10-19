#include <cstdio>

const int N = 2000000;

int main()
{

  bool tablica[N+1];           // tablica[j] == false, jeśli liczba jest wykreślona, true jeśli nie jest
  long long prefix[N+1];
  
  for(int i = 2; i <= N; i++)
     tablica[i] = true;

  for(int i = 2; i <= N; i++)  // bierzemy kolejną liczbę i
    if (tablica[i])          // jeśli nie jest wykreślona
      for(int j = 2 * i; j <= N; j = j+i)   // iterujemy się po wszystkich wielokrotnościach i
        tablica[j] = false;
  

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
