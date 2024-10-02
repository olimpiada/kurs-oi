#include <bits/stdc++.h>
#include "oi.h"
using namespace std;

const int maxn = 1'000'000'000;
const int maxz = 10'000;

void inwer(oi::Scanner in) {

    int Z;
    in >> oi::Num{Z, 1, maxz} >> oi::nl;
    for(int zz=1; zz<=Z; zz++)
    {
        string S,A;
        int b;
        int n;
        in >> oi::Str{S, 6} >> ' ';
        if (S=="code")
        {
            in >> oi::Num{n,0,maxn} >> ' ' >> oi::Num{b,2,16} >> oi::nl;
        } else
        if (S=="decode")
        {
            in >> oi::Str{A, 40} >> ' ' >> oi::Num{b,2,16} >> oi::nl;
            long long t = 0;
            for(int i=0; i<(int)A.length(); i++)
            {
                int cyfra;
                if (A[i]>='0' && A[i]<='9')
                {
                    cyfra = A[i]-'0';
                } else
                if (A[i]>='A' && A[i]<='F')
                {
                    cyfra = A[i]-'A'+10;
                } else
                    in.error("Nieznany znak!");
                if (cyfra>=b)
                    in.error("Niewlasciwa cyfra!");
                t = t*b + cyfra;
                if (t>maxn)
                    in.error("Za duza liczba!");
            }
        } else
            in.error("Nieznane polecenie!");
    }
    in >> oi::eof; // `oi::eof` in `oi::Scanner::Mode::TestInput` mode allows only EOF.
    oi::inwer_verdict.exit_ok()
        << "Z = " << setw(6) << Z << ".";
}

int main() {
    inwer(oi::Scanner{stdin, oi::Scanner::Mode::TestInput, oi::Lang::PL});
    return 0;
}
