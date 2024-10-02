#include <iostream>
using namespace std;

const int MAX = 100000;

int main() {
  int n;
  cin >> n;
  int t[MAX];
  for (int i = 0; i < n; i++)
    cin >> t[i];
  for (int i = 0; i < n; i++)
    if (i % 2 == 0)
      cout << t[i] << " ";
  cout << endl;
  for (int i = 0; i < n; i++)
    if (i % 2 == 1)
      cout << t[i] << " ";
  cout << endl;
}
