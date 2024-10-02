#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++)
      cout << ' ';
    for (int j = 0; j < 2 * i + 1; j++)
      cout << '*';
    cout << endl;
  }
  for (int powt = 0; powt < 2; powt++) {
    for (int i = 0; i < n - 1; ++i)
      cout << ' ';
    cout << '*' << endl;
  }
}
