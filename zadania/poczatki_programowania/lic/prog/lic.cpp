#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool pierwsza = true;
  for (int i = 2; i < n; i++)
    if (n % i == 0)
      pierwsza = false;
  if (pierwsza)
    cout << "pierwsza" << endl;
  else
    cout << "zlozona" << endl;
}
