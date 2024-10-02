#include <iostream>
using namespace std;

int main() {
  int kom, rok;
  cin >> kom >> rok;
  int wynik = kom % 10;
  wynik *= 2;
  wynik += 5;
  wynik *= 50;
  wynik += 1764;
  wynik -= rok;
  cout << wynik << endl;
}
