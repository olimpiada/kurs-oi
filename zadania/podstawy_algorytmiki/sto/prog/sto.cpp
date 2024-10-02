// Lech Duraj
// Złożoność czasowa O(n), pamięciowa O(1).
// Rozwiązanie wzorcowe.

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
    int najwiecej = 1;
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
