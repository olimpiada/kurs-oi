// Gauss, 1800..2199
// Blad: nie bierze pod uwage wyjatkow.

#include <iostream>
using namespace std;

int main() {
  int r;
  cin >> r;
  int A, B;
  if (r < 1900) {
    A = 23;
    B = 4;
  } else if (r < 2100) {
    A = 24;
    B = 5;
  } else {
    A = 24;
    B = 6;
  }
  int a = r % 19;
  int b = r % 4;
  int c = r % 7;
  int d = (a * 19 + A) % 30;
  int e = (2 * b + 4 * c + 6 * d + B) % 7;
  int dzien = 22 + d + e, miesiac = 3;
  if (dzien > 31) {
    dzien -= 31;
    miesiac++;
  }
  /*
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
  cout << "e: " << e << endl;
  */

  cout << dzien << " " << miesiac << " " << endl;
}
