#include <iostream>
using namespace std;

int n;
int t[500000];

bool rosnacy() {
  for (int i = 0; i < n - 1; ++i)
    if (t[i] >= t[i + 1])
      return false;
  return true;
}

bool malejacy() {
  for (int i = 0; i < n - 1; ++i)
    if (t[i] <= t[i + 1])
      return false;
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> t[i];
  bool bitoniczny;
  if (rosnacy() || malejacy()) {
    bitoniczny = true;
  } else {
    int top = -1;
    for (int i = 1; i < n - 1; ++i)
      if (t[i - 1] < t[i] && t[i] > t[i + 1])
        top = i;
    if (top == -1) {
      bitoniczny = false;
    } else {
      bitoniczny = true;
      for (int i = 0; i < top; ++i)
        if (t[i] >= t[i + 1])
          bitoniczny = false;
      for (int i = top; i < n - 1; ++i)
        if (t[i] <= t[i + 1])
          bitoniczny = false;
    }
  }
  if (bitoniczny)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;
}
