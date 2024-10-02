#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

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
        cout << '0';
        return;
    }
    if (x>=b)
        from10(x/b,b);
    cout << to_char(x%b);
}

void to10(string &S, int b)
{
    int x = 0;
    for(int i=0; i<(int)S.length(); i++)
    {
        x *= b;
        x += from_char(S[i]);
    }
    cout << x;
}


int main()
{
    int TT;
    cin >> TT;
    while(TT--)
    {
        string command;
        cin >> command;
        if (command[0]=='c')
        {
            int x,b;
            cin >> x >> b;
            from10(x,b);
            cout << endl;
        } else
        {
            string s;
            int b;
            cin >> s >> b;
            to10(s,b);
            cout << endl;
        }
    }
}
