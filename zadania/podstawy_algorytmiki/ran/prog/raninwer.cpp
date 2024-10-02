#include <algorithm>
#include "oi.h"

using namespace std;

typedef long long LL;

const int milion = 1000*1000;
const int bilion = 1000*milion;
const int MAXN = 300000;
const int MAXR = bilion;


int main() {
    oi::Scanner in(stdin, oi::PL);
    int n = in.readInt(2, MAXN);
    in.readSpace();
    int s = in.readInt(1,2*MAXR);
    if (s%2==0)
        in.error("Zadana suma parzysta!\n");
    in.readEoln();
    for(int i=0; i<n; i++) {
        char S[20];
        in.readString(S,11);
        in.readSpace();
        in.readInt(1,MAXR);
        in.readEoln();
    }
    in.readEof();
    printf("OK, n = %d.\n",n);
}
