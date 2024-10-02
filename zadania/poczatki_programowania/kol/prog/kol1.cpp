#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double pi = 3.1415926535;

int main() {
  double r;
  cin >> r;
  cout << setprecision(3) << fixed;
  cout << pi * r * r << endl
       << 2 * pi * r << endl;
}
