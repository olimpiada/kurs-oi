// Lech Duraj
// Złożoność czasowa O(n), pamięciowa O(1).
// Rozwiązanie wzorcowe.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // znane już wczytywanie danych
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // teraz następuje główna pętla
    int kandydat = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > kandydat) {
            kandydat = A[i];
        }
    }
    cout << kandydat << '\n';
}
