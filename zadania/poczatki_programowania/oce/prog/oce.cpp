#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int oceny[6];
  for (int i = 0; i < 6; i++)
    oceny[i] = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    oceny[a - 1]++;
  }
  for (int i = 0; i < 6; i++) {
    cout << oceny[i];
    if (i < 5)
      cout << " ";
    else
      cout << endl;
  }
}
