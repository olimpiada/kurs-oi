#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; ++i)
    cin >> t[i];
  int wyn = 0;
  for (int j = 1; j < n; ++j)
    if (t[0] != t[j] && j > wyn)
      wyn = j;
  for (int i = 0; i < n; ++i)
    if (t[i] != t[n - 1] && n - 1 - i > wyn)
      wyn = n - 1 - i;
  if (!wyn)
    cout << "BRAK" << endl;
  else
    cout << wyn << endl;
}
