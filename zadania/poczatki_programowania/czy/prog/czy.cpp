#include <iostream>
using namespace std;

int main() {
  long long i;
  cin >> i;
  while (i > 1 && i % 2 == 0)
    i /= 2;
  if (i == 1)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;
}
