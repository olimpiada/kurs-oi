// Lech Duraj
// Złożoność czasowa O(n), pamięciowa O(1).
// Wywala się na n = 1.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int najwiecej = 0;
    int biezace = 1;
    for(int i = 1; i < n; i++) {
        if (A[i] > A[i-1]) {
            biezace++;
        }
        else {
            biezace = 1;
        }

        if (biezace > najwiecej) {
            najwiecej = biezace;
        }
    }
    cout << najwiecej << '\n';
}
