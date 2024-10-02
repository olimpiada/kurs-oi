#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (!n) {
    cout << 1 << endl;
    return 0;
  }
  int r = 6;
  for (int i = 0; i < n % 4; ++i)
    r = (r * 2) % 10;
  cout << r << endl;
}
