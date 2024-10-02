#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  int s = t % 60;
  t /= 60;
  int m = t % 60;
  t /= 60;
  cout << t << "g" << m << "m" << s << "s" << endl;
}
