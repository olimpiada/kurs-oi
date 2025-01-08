#include <cstdio>

using namespace std;

const int maxn = 300100;

int A[maxn],B[maxn];

long long mergesort(int p, int q)
{
  if (p>=q) return 0;
  long long inv = 0;
  int s = (p+q)/2;
  inv += mergesort(p,s);
  inv += mergesort(s+1,q);
  int i = p;
  int j = s+1;
  for(int c=p; c<=q; c++)
  {
    if (j>q || (i<=s && A[i]<A[j]))
      B[c] = A[i++];
    else
    {
      B[c] = A[j++];
      inv += s+1-i;
    }
  }
  for(int c=p; c<=q; c++)
    A[c] = B[c];
  return inv;
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d",&A[i]);
  long long inv = mergesort(0,n-1);
  for(int i=0; i<n; i++)
    printf((i==0 ? "%d" : " %d"), A[i]);
  printf("\n%lld\n",inv);
}
