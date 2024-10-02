#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; ++i)
    cin >> t[i];
  int i = 0, j = n - 1;
  while (i < n - 1 && t[i] < t[i + 1])
    ++i;
  while (j > 0 && t[j - 1] > t[j])
    --j;
  if (i == j)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;
}
