#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; ++i)
    cin >> t[i];
  int i = 0;
  while (i < n - 1 && t[i] < t[i + 1])
    ++i;
  while (i < n - 1 && t[i] > t[i + 1])
    ++i;
  if (i >= n - 1)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;
}
