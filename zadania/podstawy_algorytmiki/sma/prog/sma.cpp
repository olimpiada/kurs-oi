#include <iostream>
#include <cstdio>
using namespace std;

long long int ans;
int n, m;
int t[1000010];
bool used[1000010];

int main()
{
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++)
    scanf("%d", &t[i]);
  int pocz=-1, kon=-1;
  while(kon<n-1) 
  {
    while(used[t[kon+1]])
      used[t[++pocz]]=0;
    used[t[++kon]]=1;
    ans+=kon-pocz;
  }
  printf("%lld", ans);
  return 0;
}