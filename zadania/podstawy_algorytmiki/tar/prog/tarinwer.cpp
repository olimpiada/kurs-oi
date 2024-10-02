#include <algorithm>
#include "oi.h"

using namespace std;

typedef long long LL;

const LL milion = 1000*1000;
const LL MAXA=milion*milion;
const LL MAXB=milion*milion*milion;


int main() {
    oi::Scanner in(stdin, oi::PL);
    int TT = in.readInt(1, 10000);
    in.readEoln();
    for(int i=0; i<TT; i++) {
        in.readLL(1, MAXA);
        in.readSpace();
        in.readLL(1, MAXB);
        in.readEoln();
    }
    in.readEof();
    printf("OK, %d testow.\n",TT);
}
