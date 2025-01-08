#include<iostream>
using namespace std;
long long n,wynik,wschod,kierunek;
int main() {
    cin>>n;
    wynik=0;
    wschod=0;
    for (int k=1; k<=n; k++) {
       cin>>kierunek;
       if (kierunek==0) wschod++;
       else wynik+=wschod;
    }
    cout<<wynik<<endl;
    return 0;
}
