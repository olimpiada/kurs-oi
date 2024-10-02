#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n,p;
  string S;
  int A[1000*1001];
  cin >> n >> p;
  cin >> S;
  A[1] = 1;
  for(int i=2; i<=n; i++)
  {
    A[i] = 0;
    if (S[i-1]=='1')
      for(int j=1; j<=6 && i-j>=1; j++)
    A[i] += A[i-j];
    A[i]%=p;
  }
   cout << A[n] << endl;
}
