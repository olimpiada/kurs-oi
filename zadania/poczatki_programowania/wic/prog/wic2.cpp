#include <iostream>
#include <algorithm>
using namespace std;

void sortowanie(int a[], int n) {
  for (int i = n - 1; i > 0; i--) {
    // wiemy, że elementy a[i+1], a[i+2], ..., a[n-1] są największe w tablicy i są
    // już uporządkowane: a[i+1] <= a[i+1] <= ... <= a[n-1] oraz że dla każdego k = 0, 1, ..., i,
    // a[k] <= a[i+1]
    // wyznaczamy element największy w podtablicy a[0..i]
    int m = 0;
    int maks = a[0];
    for (int j = 1; j <= i; j++)
      // maks == a[m] jest największym elementem spośród a[0], a[1], ..., a[j-1]
      if (a[j] > maks) {
        m = j;
        maks = a[m];
      }
    //zamieniamy element a[i] z elementem największym
    a[m] = a[i];
    a[i] = maks;
  }
}

int main() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++)
    cin >> t[i];
  sortowanie(t, n);
  cout << t[n - 2] << endl;
}
