// Brakuje przypadku n = 0.

#include <iostream>
#include <vector>

using namespace std;

void one()
{
    int s; 
    cin >> s;

    // Liczba s jest tą, którą chcemy zamienić na system ósemkowy.

    vector<int> L;

    // W wektorze L będziemy zapisywać kolejne cyfry wyniku, od ostatniej do pierwszej.

    while (s > 0) {
        int c = s % 2; // Wyznaczamy ostatnią cyfrę...
        L.push_back(c); 
        s = s / 2; // ... po czym "skreślamy" ją z liczby s.
    }

    // Jeśli chcemy, możemy teraz wypisać wynik.

    int d = (int)L.size(); // Długość wektora L to liczba cyfr wyniku, będziemy ją potrzebować za chwilę.

    for (int i = d - 1; i >= 0; i--) {
        cout << L[i];
    }

    cout << endl;
}


int main()
{
    int Z;
    cin >> Z;
    while(Z--)
        one();
}
