#include <iostream>
#include <algorithm>

using namespace std;

struct obywatel
{
    string name;
    int number;
};


obywatel A[2000*1001];


bool cmp(obywatel a, obywatel b)
{
    return a.number < b.number;
}

int main()
{
    int n, s;
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> A[i].name >> A[i].number;
    sort(A,A+n,cmp);
    int i = 0;
    int j = n-1;
    bool found = false;
    while(!found && i<=j)
    {
//      printf("%d %d\n",A[i].number,A[j].number);
      if (A[i].number+A[j].number==s)
      {
        cout << A[i].name << " " << A[j].name << endl;
        found = true;
      }
      if (A[i].number+A[j].number>s)
        j--;
      else
        i++;
    }
    if (!found)
      cout << "NIE\n";
}