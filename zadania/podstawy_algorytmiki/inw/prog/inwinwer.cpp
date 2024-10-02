#include <algorithm>
#include "oi.h"

using namespace std;

typedef long long LL;

const int milion = 1000*1000;
const int MAXN = 300000;
const int MAXR = milion;


int main() {
    oi::Scanner in(stdin, oi::PL);
    int n = in.readInt(1, MAXN);
    in.readEoln();
    for(int i=0; i<n; i++) {
        if (i>0)
            in.readSpace();
        in.readInt(1,MAXR);
    }
    in.readEoln();
    in.readEof();
    printf("OK, n = %d.\n",n);
}
