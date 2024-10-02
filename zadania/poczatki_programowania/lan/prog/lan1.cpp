// Zagadka rozwiklana

#include <iostream>
using namespace std;

int main() {
  int kom, rok;
  cin >> kom >> rok;
  cout << 100 * (kom % 10) + (2014 - rok) << endl;
}
