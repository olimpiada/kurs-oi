/* Oszukiwanie binarne - program z użyciem STL ;-) */

#include <cstdio>
#include <algorithm>
#include <cassert>

#define BILLION 1000000000LL

using namespace std;

int main()
{
  int A[1000002];
  int n,i,m,key;
    scanf("%d",&n);
    for(i=0; i<n; i++)
      scanf("%d",&A[i]);
    scanf("%d",&m);
    for(i=0; i<m; i++)
    {
      scanf("%d",&key);
      int* leftmost = lower_bound(A,A+n,key);
      int* rightmost = upper_bound(A,A+n,key);
      if (leftmost==A+n || *leftmost!=key)
        printf("0\n");
      else
        printf("%d\n",(int)(rightmost-leftmost));
    }
}
