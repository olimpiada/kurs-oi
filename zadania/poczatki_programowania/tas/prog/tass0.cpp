#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; ++i)
    cin >> t[i];
  int wyn = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (t[i] != t[j] && j - i > wyn)
        wyn = j - i;
  if (!wyn)
    cout << "BRAK" << endl;
  else
    cout << wyn << endl;
}
