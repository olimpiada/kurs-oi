#include <cstdio>
#include <algorithm>

using namespace std;

struct obywatel
{
   char name[11];
   int number;
};


obywatel A[2000*1001];

void quicksort(int p, int q)
{
  int pivot = A[(4*p+5*q)/9].number;
  int i = p;
  int j = q;
  while(i<=j)
  {
    while (A[i].number<pivot)
      i++;
    while (A[j].number>pivot)
      j--;
    if (i<=j)
    {
      swap(A[i],A[j]);
      i++;
      j--;
    }
  }
  if (p<j)
    quicksort(p,j);
  if (i<q)
    quicksort(i,q);
}

int main()
{
  int n,s;
//  printf("%d",sizeof(A));
    scanf("%d %d",&n,&s);
    for(int i=0; i<n; i++)
      scanf("%s %d",A[i].name,&A[i].number);
    quicksort(0,n-1);
    int i = 0;
    int j = n-1;
    bool found = false;
    while(!found && i<=j)
    {
//      printf("%d %d\n",A[i].number,A[j].number);
      if (A[i].number+A[j].number==s)
      {
        printf("%s %s\n",A[j].name,A[i].name);
	found = true;
      }
      if (A[i].number+A[j].number>s)
        j--;
      else
        i++;
    }
    if (!found)
      printf("NIE\n");
}