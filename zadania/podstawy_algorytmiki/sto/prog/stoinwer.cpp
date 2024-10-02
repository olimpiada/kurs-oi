#include <bits/stdc++.h>
#include "oi.h"
using namespace std;

const int maxn = 1'000'000;
const int maxw = 1'000'000'000;

void inwer(oi::Scanner in) {

    int n;
    // `oi::nl` in `oi::Scanner::Mode::TestInput` mode allows only a single `\n`.
    in >> oi::Num{n, 1, maxn} >> oi::nl;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        in >> oi::Num{v[i], 1, maxw};
        if (i < n - 1) {
            in >> ' ';
        } else {
            in >> oi::nl;
        }
    }
    in >> oi::eof; // `oi::eof` in `oi::Scanner::Mode::TestInput` mode allows only EOF.


    oi::inwer_verdict.exit_ok()
        << "n = " << setw(6) << n << ".";
}

int main() {
    inwer(oi::Scanner{stdin, oi::Scanner::Mode::TestInput, oi::Lang::PL});
    return 0;
}
