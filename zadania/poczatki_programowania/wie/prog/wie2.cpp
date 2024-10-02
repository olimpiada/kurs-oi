// Meeus

#include <iostream>
using namespace std;

int main() {
  int r;
  cin >> r;
  int a = r % 19;
  int b = r / 100;
  int c = r % 100;
  int d = b / 4;
  int e = b % 4;
  int f = (b + 8) / 25;
  int g = (b - f + 1) / 3;
  int h = (19 * a + b - d - g + 15) % 30;
  int i = c / 4;
  int k = c % 4;
  int l = (32 + 2 * e + 2 * i - h - k) % 7;
  int m = (a + 11 * h + 22 * l) / 451;
  int p = (h + l - 7 * m + 114) % 31;
  int q = (h + l - 7 * m + 114) / 31;
  /*
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << "d: " << d << endl;
  cout << "e: " << e << endl;
  cout << "f: " << f << endl;
  cout << "g: " << g << endl;
  cout << "h: " << h << endl;
  cout << "i: " << i << endl;
  cout << "k: " << k << endl;
  cout << "l: " << l << endl;
  cout << "m: " << m << endl;
  cout << "p: " << p << endl;
  */
  cout << p + 1 << " " << q << " " << endl;
}
