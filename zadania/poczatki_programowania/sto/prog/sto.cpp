#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    if (k > a || k > b)
        cout << 0 << endl;
    else if (2 * k > a || 2 * k > b) {
        if (a > b)
            cout << a / k << endl;
        else
            cout << b / k << endl;
    } else
        cout << 2 * (a / k + b / k) - 4 << endl;
}
