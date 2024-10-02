#include <iostream>
#include <algorithm>
using namespace std;

int max(int t[], int n) {
  int wyn = t[0];
  for (int i = 1; i < n; i++)
    if (t[i] > wyn)
      wyn = t[i];
  return wyn;
}

int main() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++)
    cin >> t[i];
  int mistrz = max(t, n);
  for (int i = 0; i < n; i++)
    if (t[i] == mistrz)
      swap(t[i], t[n - 1]);
  cout << max(t, n - 1) << endl;
}
