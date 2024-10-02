#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int t[n][m];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> t[i][j];

  int best = 100 * 1000;
  for (int i1 = 0; i1 < n; ++i1)
    for (int i2 = 0; i2 < n; ++i2) {
      int akt = 0;
      for (int j = 0; j < m; ++j)
        akt += min(t[i1][j], t[i2][j]);
      best = min(best, akt);
    }

  cout << best << endl;
}
