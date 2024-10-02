#include <iostream>
#include <cstring>
using namespace std;

int nwd(int a, int b) {
  int r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main() {
  int n;
  cin >> n;
  int a;
  cin >> a;
  for (int i = 1; i < n; i++) {
    int b;
    cin >> b;
    a = nwd(a, b);
  }
  cout << a << endl;
}
