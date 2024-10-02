#include <algorithm>
#include "oi.h"

using namespace std;

typedef long long LL;

const int milion = 1000*1000;
const int MAXA = 10000;
const int MAXB = milion*1000;


int main() {
    oi::Scanner in(stdin, oi::PL);
    int TT = in.readInt(1, 10000);
    in.readEoln();
    for(int i=0; i<TT; i++) {
        in.readInt(1,MAXA);
	in.readSpace();
        in.readInt(1,MAXB);
	in.readEoln();
    }
    in.readEof();
    printf("OK, %d testow.\n",TT);
}
