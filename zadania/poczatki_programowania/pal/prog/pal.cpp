#include <iostream>
#include <string>
using namespace std;

int main() {
  string slowo;
  cin >> slowo;
  int n = slowo.size();
  bool palindrom = true;
  for (int i = 0; i < n; i++)
    if (slowo[i] != slowo[n - 1 - i])
      palindrom = false;
  if (palindrom)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;
}
