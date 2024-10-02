#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1002;

bool mniejsze(string a, string b) {
  int n = a.size(), m = b.size();
  if (n != m)
    return n < m;
  else {
    int i = 0;
    while (i < n && a[i] == b[i])
      i++;
    return a[i] < b[i];
  }
}

int main() {
  string a, znak, b;
  cin >> a >> znak >> b;
  bool wynik;
  if (znak[0] == '<' && znak.size() == 1)
    wynik = mniejsze(a, b);
  else if (znak[0] == '>' && znak.size() == 1)
    wynik = mniejsze(b, a);
  else if (znak[0] == '<')
    wynik = !mniejsze(b, a);
  else if (znak[0] == '>')
    wynik = !mniejsze(a, b);
  else if (znak[0] == '!')
    wynik = (mniejsze(a, b) || mniejsze(b, a));
  else
    wynik = (!mniejsze(a, b) && !mniejsze(b, a));
  if (wynik)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;
}
