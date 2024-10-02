#include <iostream>
#include <algorithm>
using namespace std;

int second_max(int t[], int n) {
  int max = -1, secondmax = -1;
  for (int i = 0; i < n; i++)
    if (t[i] > max) {
      secondmax = max;
      max = t[i];
    } else if (t[i] > secondmax) {
      secondmax = t[i];
    }
  return secondmax;
}

int main() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++)
    cin >> t[i];
  cout << second_max(t, n) << endl;
}
