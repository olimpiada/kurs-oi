#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int lustro = 0;
  while (n > 0) {
    lustro *= 10;
    lustro += n % 10;
    n /= 10;
  }
  cout << lustro << endl;
}
