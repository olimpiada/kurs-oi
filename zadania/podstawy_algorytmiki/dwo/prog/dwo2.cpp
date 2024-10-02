// Michal Wozny

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int zamien(int T[], int n){
      int i=0;
      while(n>0){
              if(n%2==0)
                      T[i]=0;
              else
                      T[i]=1;
              i++;
              n = n/2;
      }
      return i;
}

int main()
{
      int n, len, z;
      int A[50]={0};

      scanf("%d", &z);

      for(int j=0; j<z; j++){
              for(int i=0; i<50; i++) A[i]=0;
              scanf("%d", &n);
              if(n == 0) printf("0");
              else {
                      len = zamien(A, n);
                      for(int i=0; i<len/2; i++)
                              swap(A[i], A[len-i-1]);
                      for(int i=0; i<len; i++) printf("%d", A[i]);
              }
              if(j+1<z) printf("\n");
      }
}
