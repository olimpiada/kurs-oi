#include <iostream>
using namespace std;

int main() {
  char k1, k2;
  cin >> k1 >> k2;
  char znak = k1 - '0';
  znak *= 16;
  if ('A' <= k2 && k2 <= 'F')
    znak += 10 + k2 - 'A';
  else
    znak += k2 - '0';
  cout << int(znak) << endl
       << znak      << endl;
}
