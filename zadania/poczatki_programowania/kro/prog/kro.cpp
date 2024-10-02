#include <iostream>
using namespace std;

int main() {
  char k;
  int w;
  cin >> k >> w;
  if ((k == 'a' && w == 1) || (k == 'a' && w == 8) || (k == 'h' && w == 1) || (k == 'h' && w == 8))
    cout << 3 << endl;
  else if (k == 'a' || k == 'h' || w == 1 || w == 8)
    cout << 5 << endl;
  else
    cout << 8 << endl;
}
