#include <iostream>
using namespace std;

int main() {
  int pomiar;
  int wynik = 0;
  cin >> pomiar;
  while (pomiar != -1) {
    int nowy;
    cin >> nowy;
    if (nowy > 0 && nowy != pomiar)
      wynik++;
    pomiar = nowy;
  }
  cout << wynik << endl;
}
