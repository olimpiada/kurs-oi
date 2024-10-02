#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 300100;

int A[maxn],B[maxn];

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d",&A[i]);
  long long inv = 0;
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
      if (A[i] > A[j])
        inv++;
  sort(A,A+n);
  for(int i=0; i<n; i++)
    printf((i==0 ? "%d" : " %d"), A[i]);
  printf("\n%lld\n",inv);
}
