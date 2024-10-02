#include <algorithm>
#include "oi.h"

using namespace std;

typedef long long LL;

const int milion = 1000*1000;
const int MAXN = 100000;
const int MAXQ = milion;
const int MAXM = milion*1000;


int main() {
    oi::Scanner in(stdin, oi::PL);
    int n = in.readInt(1,MAXN);
    in.readEoln();
    int a, b = 0;
    for(int j=0; j<n; j++)
    {
        if (j)
            in.readSpace();
        a = in.readInt(-MAXM,MAXM);
        if (j>0 && a<b)
           in.error("Tablica nie posortowana!");
        b = a;
    }
    in.readEoln();
    int q = in.readInt(1, MAXQ);
    in.readEoln();
    for(int j=0; j<q; j++)
    {
        in.readInt(-MAXM,MAXM);
        in.readEoln();
    }
    in.readEof();
    printf("OK, n = %d, q = %d.\n",n,q);
}
