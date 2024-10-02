/*
 *  ====================================
 *  Zadanie: WES - Wesola malpka
 *  Autor zadania: Joanna Bujnowska
 *  Autor programu: Jacek Tomasiewicz
 *  Zlozonosc czasowa: O(z*log_n) 
 *  ====================================
 */
#include<cstdio>
#include<algorithm>
using namespace std;
int z,n,d;
int main(){
    scanf("%d",&z);
    while(z--)
    {
        scanf("%d%d",&n,&d);
        printf("%d\n",n/(__gcd(n,d)));
    }
}
