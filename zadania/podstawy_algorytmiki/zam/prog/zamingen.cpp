#include <fstream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "oi.h"

using namespace std;

const int TT = 1000;
const int seed = 1827;
const int maxn = 1000*1000*1000;
ofstream out2("zam2.in");
ofstream out3("zam3.in");

oi::Random RG(seed);


int from_char(char c)
{
    if (c>='A' && c<='Z')
        return c-'A'+10;
    return c-'0';
}

char to_char(int x)
{
    if (x<10)
        return (char)('0'+x);
    return (char)('A'+(x-10));
}

void from10(int x, int b)
{
    if (x==0)
    {
        out3 << '0';
        return;
    }
    if (x>=b)
        from10(x/b,b);
    out3 << to_char(x%b);
}

/*void to10(string &S, int b)
{
    int x = 0;
    for(int i=0; i<S.length(); i++)
    {
        x *= b;
        x += from_char(S[i]);
    }
    out << x;
} */


int main()
{
    out2 << TT << endl;
    out3 << TT << endl;
    for(int tt=0; tt<TT; tt++)
    {
        int x = RG(1,maxn);
        int b = RG(2,16);
        out2 << "code " << x << " " << b << endl;
        out3 << "decode ";
        from10(x,b);
        out3 << " " << b << endl;
    }
    return 0;
}
