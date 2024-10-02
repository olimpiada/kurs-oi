#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 3002;


int main()
{
    string R,S;
    int A[maxn][maxn];
    cin >> R;
    cin >> S;
    int m = R.length();
    int n = S.length();
    for(int i=0; i<=m; i++)
        A[i][0] = 0;
    for(int j=0; j<=n; j++)
        A[0][j] = 0;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            A[i][j] = max(A[i-1][j],A[i][j-1]);
            if (R[i-1]==S[j-1] && A[i-1][j-1]+1>A[i][j])
            A[i][j] = A[i-1][j-1]+1;
        }
    cout << A[m][n] << endl;
}
