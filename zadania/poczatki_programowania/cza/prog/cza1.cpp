#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  cout << t / 3600 << "g" << (t / 60) % 60 << "m" << t % 60 << "s" << endl;
}
