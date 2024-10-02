#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  if ((x == 0) && (y == 0))
    cout << "0";
  else if (x == 0)
    cout << "OY";
  else if (y == 0)
    cout << "OX";
  else if ((x > 0) && (y > 0))
    cout << "I";
  else if ((x < 0) && (y > 0))
    cout << "II";
  else if ((x < 0) && (y < 0))
    cout << "III";
  else
    cout << "IV";
  cout << endl;
}
