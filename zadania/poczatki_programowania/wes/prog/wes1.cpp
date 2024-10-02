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
  int z;
  cin >> z;
  for (int i = 0; i < z; i++) {
    int n, d;
    cin >> n >> d;
    cout << n / nwd(n, d) << endl;
  }
}
