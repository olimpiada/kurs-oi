# Maksima i podciągi w tablicach

Czas wykorzystać umiejętności programowania do rozwiązywania zadań algorytmicznych! Programy z tej lekcji będą przydawać się wielokrotnie w różnych sytuacjach. Potrzebna będzie nam za to wiedza, którą zdobyliśmy wcześniej, dotycząca pętli i tablic.


## Największy/najmniejszy element

Zaczniemy od zadania o jedną z najbardziej typowych rzeczy możliwych do zrobienia w tablicy:

*Dana jest tablica $n$ liczb naturalnych. Naszym zadaniem jest znaleźć wśród nich największą.*

Jako zadanie w stylu ,,olimpijskim'' wyglądałoby to tak: 

[Sprawdź kod na Szkopule :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#max1){ .md-button .md-button--primary }

Wczytywanie danych znamy już z rozdziału o pętlach i tablicach: kiedy już będziemy wiedzieć, ile jest liczb (czyli wartość $n$), zadeklarujemy tablicę/wektor o długości $n$. Następnie użyjemy pętli, która przebiegnie od
$0$ do $n-1$, a w kroku numer $i$ wczyta wartość do komórki `A[i]`:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // (...tutaj zaraz będzie reszta programu)
}
```

Teraz potrzebujemy głównej pętli, która wykona nasze zadanie i znajdzie największy element. W tym celu zadeklarujemy nową komórkę pamięci (nazwijmy ją `kandydat`), w której będziemy trzymać ,,kandydata'' na największy element. Na początku wpiszemy do tej komórki pierwszy element `A[0]`, a potem będziemy kolejno porównywać ze wszystkimi pozostałymi. W kroku numer `i` sprawdzamy, czy element `A[i]` jest większy niż `kandydat` -- jeśli tak, to zastępuje go w tej roli. Po porównaniu ze wszystkimi elementami w komórce `kandydat` musi już na pewno być największy z elementów.

```cpp
int main() {
    // Znane już wczytywanie danych.
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Teraz następuje główna pętla.
    int kandydat = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > kandydat) {
            kandydat = A[i];
        }
    }
    cout << kandydat << "\n";
}
```

Zauważmy, że nie musimy przechowywać wszystkich elementów w tablicy (wektorze). Kiedy nowy element porównamy już z kandydatem, nigdy później nie potrzebujemy się do niego odwoływać. Zamiast całej tablicy `A` wystarczy więc jedna zmienna `aktualny`, a wczytywanie i porównywanie z kandydatem możemy zrobić naraz:

```cpp
int main() {
    int n;
    cin >> n;

    int kandydat = 0;
    for(int i = 0; i < n; i++) {
        int aktualny;
        cin >> aktualny;
        if (aktualny > kandydat) {
            kandydat = aktualny;
        }
    }
    cout << kandydat << "\n";
}
```



## Ciąg identycznych/rosnących/malejących elementów

W kolejnym zadaniu znowu dana jest tablica, ale tym razem naszym celem jest znalezienie najdłuższego fragmentu, w którym wszystkie elementy są takie same. Jako odpowiedź musimy podać długość tego fragmentu – na przykład dla ciągu $(4, 4, 9, 2, 2, 6, 10, 7, 7, 7, 7, 1, 2, 2, 2, 5)$ odpowiedzią jest $4$, jako że element $7$ występuje właśnie $4$ razy z rzędu.

Użyjemy bardzo podobnego pomysłu, co w poprzednim zadaniu, z przejściem pętlą przez wszystkie elementy. Zamiast jednej dodatkowej zmiennej potrzebujemy tym razem jednak co najmniej dwóch. Pierwsza (`najwiecej`) będzie przechowywać (jak poprzednio) informację o najlepszym napotkanym dotychczas kandydacie. Druga (`ostatnie`) musi na bieżąco pamiętać, ile razy widzieliśmy ostatni napotkany element:

```cpp
int main() {
    // Znane już wczytywanie danych.
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Teraz następuje główna pętla.
    int najwiecej = 0;
    int biezace = 1;  // Zaczniemy od drugiego elementu, z informacją, że pierwszy element widzieliśmy już raz.
    for(int i = 1; i < n; i++) {
        if (A[i] == A[i-1]) {     // Jeśli element jest taki sam, jak poprzedni...
            biezace++;            // To zwiększamy liczbę wystąpień ostatniego elementu o 1.
        }
        else {
            biezace = 1;        // Ale jeśli zmienił się na inny, to liczba wystąpień ustawia się z powrotem na 1.
        }

        if (biezace > najwiecej) {
            najwiecej = biezace;
        }
    }
    cout << najwiecej << "\n";
}
```

A co, gdybyśmy musieli dodatkowo podać, który element wystąpił najwięcej razy? Po prostu dodajemy drugą zmienną `kandydat`, która pamięta ten element. Jej wartość zmienia się zawsze razem z wartością zmiennej `najwiecej`:

```cpp
int main() {
    // Znane już wczytywanie danych.
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Teraz następuje główna pętla.
    int najwiecej = 1;
    int biezace = 1;  // zaczniemy od drugiego elementu, z informacją, że pierwszy element widzieliśmy już raz.
    int kandydat = A[0];
    for(int i = 1; i < n; i++) {
        if (A[i] == A[i-1]) {     // jeśli element jest taki sam, jak poprzedni...
            biezace++;            // to zwiększamy liczbę wystąpień ostatniego elementu o 1.
        }
        else {
            biezace = 1            // Ale jeśli zmienił się na inny, to liczba wystąpień ustawia się z powrotem na 1.
        }

        if (biezace > najwiecej) {
            biezace = najwiecej;
            kandydat = A[i];
        }
    }
    cout << najwiecej << "\n";
}
```

Bardzo podobnie wygląda program, który szuka najdłuższego fragmentu tablicy, który jest rosnący. Zachęcamy do samodzielnego rozwiązania takiego zadania: 


[Sprawdź kod na Szkopule :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#sto1){ .md-button .md-button--primary }


## Zliczanie elementów

W kolejnym zadaniu znowu będziemy rozważali ciąg elementów, ale tym razem wszystkie są liczbami całkowitymi między $1$ a $100$. Chcemy policzyć, który element występuje najczęściej. W tym celu zadeklarujemy tablicę `L`, która będzie przechowywała liczbę wystąpień każdego elementu (np. zawartość komórki `L[5]` będzie określała, ile razy pojawiła się liczba $5$). Na początku wszystkie wartości w `L` muszą być równe $0$. W miarę, jak czytamy każdy kolejny element, zwiększamy jego liczbę wystąpień:

```cpp
int main() {
    // Znane już wczytywanie danych.
    int n;
    cin >> n;

    int maksymalna_wartosc = 100;
    vector<int> L(maksymalna_wartosc + 1);
    // Musimy mieć komórki L[1],.., L[100], stąd rozmiar 101.
    // Wektor liczb automatycznie ustawia wszystkie wartości na 0, tak jak chcieliśmy.
    int aktualny;
    for (int i = 0; i < n; i++) {
        cin >> aktualny;
        L[aktualny]++;
    }

    // (...tutaj zaraz będzie reszta programu)
}
```

Teraz musimy znaleźć największą wartość w tablicy `L`, a dokładniej: takie $j$, że `L[j]` jest największą wartością w tablicy `L`. To już potrafimy zrobić:

```cpp
int main() {
    // Znane już wczytywanie danych.
    int n;
    cin >> n;

    int maksymalna_wartosc = 100;
    vector<int> L(maksymalna_wartosc + 1);

    int aktualny;
    for (int i = 0; i < n; i++) {
        cin >> aktualny;
        L[aktualny]++;
    }

    int kandydat = 1;    // Kandydat na najczęstszy element.
    int najwiecej = 0;    // Ile wystąpień miał kandydat.

    for (int j = 1; j <= maksymalna_wartosc ; j++) {
        if (L[j] > najwiecej) {
            najwiecej = L[j];
            kandydat = j;
        }
    }
    cout << kandydat << "\n";
}
```
