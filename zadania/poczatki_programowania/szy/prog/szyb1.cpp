#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 10000;
const int SZYFRUJ = 1;

int main() {
  int polecenie, k;
  cin >> polecenie >> k;
  char tekst[LEN + 1];
  cin >> tekst;
  int n = strlen(tekst);
  for (int i = 0; i < n; i++) {
    if ('A' <= tekst[i] && tekst[i] <= 'Z') {
      if (polecenie == SZYFRUJ) {
        tekst[i] += k;
        if (tekst[i] > 'Z')
          tekst[i] -= 'Z' - 'A' + 1;
      } else {
        tekst[i] -= k;
        if (tekst[i] < 'A')
          tekst[i] += 'Z' - 'A' + 1;
      }
    } else if ('a' <= tekst[i] && tekst[i] <= 'z') {
      if (polecenie == SZYFRUJ) {
        tekst[i] += k;
        if (tekst[i] > 'z')
          tekst[i] -= 'z' - 'a' + 1;
      } else {
        tekst[i] -= k;
        if (tekst[i] < 'a')
          tekst[i] += 'z' - 'a' + 1;
      }
    }
  }
  cout << tekst << endl;
}
