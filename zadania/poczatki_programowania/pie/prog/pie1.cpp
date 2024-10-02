#include <iostream>
using namespace std;

const int MAX = 100000;

int main() {
  int n, x;
  cin >> n >> x;
  int pierwszy = -1, ostatni = -1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == x) {
      ostatni = i + 1;
      if (pierwszy == -1)
        pierwszy = i + 1;
    }
  }
  cout << pierwszy << " " << ostatni << endl;
}
