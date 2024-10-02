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
  int r = 0;
  switch (n % 4) {
    case 0:
      r = 6;
      break;
    case 1:
      r = 2;
      break;
    case 2:
      r = 4;
      break;
    case 3:
      r = 8;
      break;
  }
  cout << r << endl;
}
