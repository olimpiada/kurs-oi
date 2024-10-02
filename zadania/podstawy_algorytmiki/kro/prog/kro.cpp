#include <iostream>
#include <algorithm>

using namespace std;

int pwr(int a, int b, int mod)
{
    if (b==1)
        return a%mod;
    if (b%2==0)
    {
        int s = pwr(a,b/2,mod);
        return s*s%mod;
    } else
    {
        int s = pwr(a,b-1,mod);
        return a*s%mod;
    };
}

int main()
{
    int TT,a,b;
    cin >> TT;
    while(TT--)
    {
        cin >> a >> b;
        cout << pwr(a+1,b,10000) << endl;
    }
}
