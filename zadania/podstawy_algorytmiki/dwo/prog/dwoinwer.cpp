#include <bits/stdc++.h>
#include "oi.h"
using namespace std;

const int maxn = 1'000'000'000;
const int maxz = 10'000;

void inwer(oi::Scanner in) {

    int n, Z;
    int M = 0;
    in >> oi::Num{Z, 1, maxz} >> oi::nl;
    for(int zz=1; zz<=Z; zz++)
    {
        in >> oi::Num{n, 0, maxn} >> oi::nl;
        M = max(M,n);
    }
    in >> oi::eof; // `oi::eof` in `oi::Scanner::Mode::TestInput` mode allows only EOF.
    oi::inwer_verdict.exit_ok()
        << "Z = " << setw(4) << Z << ", max.liczba = " << setw(10) << n << ".";
}

int main() {
    inwer(oi::Scanner{stdin, oi::Scanner::Mode::TestInput, oi::Lang::PL});
    return 0;
}
