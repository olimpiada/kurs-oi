#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int min_x = 1000000, max_x = 0;
  int min_y = 1000000, max_y = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x < min_x)
      min_x = x;
    if (x > max_x)
      max_x = x;
    if (y < min_y)
      min_y = y;
    if (y > max_y)
      max_y = y;
  }
  cout << 2 * (max_x - min_x + max_y - min_y) << endl;
}
