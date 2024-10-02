#include <iostream>
using namespace std;

int n;
int t[500000];

int max_poz() {
  int m = 0;
  for (int i = 1; i < n; ++i)
    if (t[i] > t[m])
      m = i;
  return m;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> t[i];
  int m = max_poz();
  bool bitoniczny = true;
  for (int i = 0; i < m; ++i)
    bitoniczny = bitoniczny && (t[i] < t[i + 1]);
  for (int i = m; i < n - 1; ++i)
    bitoniczny = bitoniczny && (t[i] > t[i + 1]);
  if (bitoniczny)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;
}
