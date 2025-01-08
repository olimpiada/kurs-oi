#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n;
    vector<int> A(n);
    vector<long long> S(n+1,0);
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
        S[i+1] = S[i]+A[i];
    }
    cin >> q;
    for(int i=0; i<q; i++)
    {
        int b,e;
        cin >> b >> e;
        cout << S[e] - S[b-1] << endl;
    }
}
