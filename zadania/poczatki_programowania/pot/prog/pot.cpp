#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int pot2 = 1;
  while (pot2 <= n) {
    cout << pot2 << endl;
    pot2 *= 2;
  }
}
