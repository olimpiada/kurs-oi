#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[1000];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int nwd = 1;
  for (int d = 2; d <= 1000; d++) {
    bool czy_dzielnik = true;
    for (int i = 0; i < n; i++)
      if (a[i] % d != 0)
        czy_dzielnik = false;
    if (czy_dzielnik)
      nwd = d;
  }
  cout << nwd << endl;
}
