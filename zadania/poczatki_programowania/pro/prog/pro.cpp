#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << a * b * c << endl;
  cout << 2 * (a * b + b * c + c * a) << endl;
}
