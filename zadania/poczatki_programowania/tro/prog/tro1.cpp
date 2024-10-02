#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c;
  if (b < a) {
    d = b;
    b = a;
    a = d;
  }
  if (c < a) {
    d = c;
    c = b;
    b = a;
    a = d;
  } else if (c < b) {
    d = c;
    c = b;
    b = d;
  }
  if (a + b <= c)
    cout << "NIE" << endl;
  else
    cout << "TAK" << endl;
}
