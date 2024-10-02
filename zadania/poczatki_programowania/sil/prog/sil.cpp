#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int silnia = 1;
  for (int i = 1; i <= n; ++i)
    silnia *= i;
  cout << silnia << endl;
}
