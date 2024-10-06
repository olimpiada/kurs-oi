#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include "oi.h"

using namespace std;

oi::Random RG(47182);

void gen(int n, int q, int maxr, string filename)
{
    ofstream out(filename);
//    cout << "Writing " << filename << "...\n";
    out << n << endl;
    for(int i=0; i<n; i++)
        out << (i ? " " : "") << RG(1,maxr);
    out << endl;
    out << q << endl;
    for(int i=0; i<q; i++)
    {
        int u = RG(1,n);
        int v = RG(1,n);
        if (u>v)
            swap(u,v);
        out << u << " " << v << endl;
    }
    out.close();
}


int main()
{
    gen(10,50,20,"naz2.in");
    gen(5000,100000,100000,"naz3.in");
    gen(1000000,1000000,1000000000,"naz4.in");
    return 0;
}
