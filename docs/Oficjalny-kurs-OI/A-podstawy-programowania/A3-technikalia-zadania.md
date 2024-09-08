# Błędy w programach, pierwsze zadania

## Błędy kompilacji

Wiemy już, że kompilator języka C++ jest pod wieloma względami dosyć restrykcyjny: instrukcje muszą być napisane zawsze tak samo. Nie możemy użyć np. wielkiej litery zamiast małej, zapomnieć o średniku na końcu instrukcji, ani też napisać ``cot`` zamiast ``cout``. Na większość takich błędów kompilator reaguje zgłaszając błąd i zatrzymując próbę kompilowania programu. Taką sytuację określamy mianem **błędu kompilacji**.
Radzenie sobie z takimi błędami często jest całkiem proste – trzeba przeczytać treść błędu zgłoszonego przez
kompilator i poprawić odpowiedni fragment kodu. [TODO: uaktualnić]Jeśli kompilacja nie udała się, Code Blocks zaznacza wiersz, który spowodował błąd kompilacji, a na dole ekranu wyświetla opis błędu.

Dla przykładu, przepiszemy nasz wcześniejszy program obliczający pole i obwód prostokąta, umieszczając w nim pewne usterki, które najczęściej przydarzają się początkującym programistom, i przyjrzymy się występującym błędom kompilacji. Oto pierwsza błędna wersja:

```C++
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin << a << b;
    cout << "Pole: " << a * b
         << " obwod: " << 2 * (a + b) << endl;
}
```

Treść błędu kompilacji pozwala nam zauważyć, że przy wczytywaniu pomyliliśmy znaki >> z <<.

```
In function 'int main()':
Wiersz 6: error: no match for 'operator<<' in 'std::cin << a'
```

Druga błędna wersja:

```C++
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b
    cout << "Pole: " << a * b
         << " obwod: " << 2 * (a + b) << endl;
}
```

Z treści błędu kompilacji możemy wywnioskować, że na końcu wiersza z wczytywaniem zapomnieliśmy dać średnika:

```
In function 'int main()':
Wiersz 7: error: expected ';' before 'cout'
```

Trzeci błąd:

```C++
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a >> b;
    cout << "Pole: " << a * b
         << " obwod: " << 2 * (a + b) << endl;
}
```

Ewidentnie nie zadeklarowaliśmy jednej z używanych zmiennych:

```
In function 'int main()':
Wiersz 6: error: 'b' was not declared in this scope
```

A oto jeszcze jedna wersja programu, w której zupełnie zapomnieliśmy o dwóch początkowych wierszach:

```C++
int main() {
    int a, b;
    cin >> a >> b;
    cout << "Pole: " << a * b
         << " obwod: " << 2 * (a + b) << endl;
}
```

Błąd kompilacji, tym razem dość obszerny, wskazuje, że kompilator nie rozpoznał żadnego ze słówek ```cin, cout, endl```, służących do wczytywania i wypisywania danych.

```
prog.cpp: In function 'int main()':
Wiersz 3: error: 'cin' was not declared in this scope
Wiersz 4: error: 'cout' was not declared in this scope
Wiersz 5: error: 'endl' was not declared in this scope
```

Możliwych jest wiele innych typów drobnych usterek. Bywa też tak, że trzeba wczytać się dokładnie w komunikat kompilatora, gdyż czasem kompilator może nam sugerować inne źródło problemu niż to, co było nim w istocie (np. musimy spojrzeć na jeden z wcześniejszych wierszy).

## Inne rodzaje błędów

Rozważmy program, który wystąpił w poprzedniej lekcji, a który dzieli dwie liczby przez siebie z resztą:

```C++
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a << " / " << b << " = " << a / b << " r. " << a % b << endl;
}
```

Co się stanie, jeśli "złośliwy" użytkownik wpisze z klawiatury liczby ``10`` i  ``0``? Jak program zareaguje na dzielenie przez zero? Można to łatwo sprawdzić – okazuje się, że program natychmiast kończy działanie i wyświetla na ekranie komunikat podobny do poniższego:

``Floating point exception (core dumped)``

Jest to tak zwany **błąd wykonania** programu – program wykonał operację, po której nie może już działać dalej. Dzielenie przez zero to tylko jeden z przykładów, znacznie częściej spotkasz się z błędem wykonania, kiedy zaczniesz działać na tablicach, wskaźnikach, lub innych bardziej skomplikowanych zmiennych.

Oczywiście nawet jeśli nasz program poprawnie się skompiluje, są inne powody, dla których może nie działać tak, jak chcemy. Może dawać w wyniku niewłaściwe (błędne) odpowiedzi, może też działać w nieskończoność i się nie kończyć (co nazywamy *zapętleniem* lub *zawieszeniem*). Sposoby radzenia sobie z poszczególnymi typami błędów będziemy przedstawiać w częściach technicznych kolejnych lekcji.

## Zadania

W tej lekcji mamy dla Ciebie trzy zadania. W każdym zadaniu, w sekcji "Wejście" znajduje się opis danych, które program ma wczytać, natomiast w sekcji "Wyjście" podano wymagany sposób wypisania wyniku. Twoje rozwiązanie zostanie sprawdzone automatycznie z użyciem pewnej liczby **testów**, czyli różnych zestawów danych wejściowych (możesz to sobie wyobrazić tak, że nasz automat uruchamia Twój program, "wpisuje" odpowiednie dane i sprawdza wynik jego działania). W każdym teście dane wejściowe są idealnie zgodne z opisem podanym w sekcji "Wejście", a wynik Twojego programu musi dokładnie odpowiadać temu, co jest opisane w sekcji "Wyjście". Jak wspominaliśmy poprzednio, dopuszczalne są nadmiarowe spacje na końcach wierszy i puste wiersze na końcu wyjścia. Program nie może wypisywać **żadnych** dodatkowych komunikatów, o które nie jest proszony w treści zadania. Twój program zostanie uznany za poprawny, jeśli zadziała poprawnie na **wszystkich** naszych testach.

Zalacamy, żeby wszystkie zadania rozwiązywać samodzielnie. Jeśli chcesz, możesz przy rozwiązywaniu wyszukiwać dodatkowe informacje w Internecie lub zasięgnąć pomocy u nauczyciela czy kolegów. Ważne jednak, aby cały kod był napisany przez Ciebie – tylko tak będziesz w stanie zdobyć umiejętności, dzięki którym będziesz się mógł zabrać za bardziej skomplikowane problemy.

A oto obiecane zadania – powodzenia!


### Zadanie 1. Na odwrót

Zadaniem Twojego programu będzie wczytanie trzech liczb całkowitych i wypisanie ich w takiej samej kolejności
oraz w kolejności odwrotnej.

#### Wejście

W jedynym wierszu wejścia znajdują się trzy liczby całkowite oddzielone spacjami: $a, b, c$ ($−1000 \leq a, b, c \leq
1000$).

#### Wyjście

W pierwszym wierszu należy wypisać podane liczby w kolejności wczytania: $a, b, c$. W drugim wierszu należy
wypisać podane liczby w kolejności odwrotnej do kolejności wczytania: $c, b, a$. W obu wierszach liczby powinny
być rozdzielane pojedynczymi spacjami.

#### Przykład

| Wejście     | Wyjście                              |
| :---------- | :----------------------------------- |
| 7 3 5       | 7 3 5 <br> 5 3 7                     |

[Sprawdź kod na Szkopule :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/T8qdFmNcJIl5o3yJedQJk1Bh/site/?key=statement){ .md-button .md-button--primary }

### Zadanie 2. Prostopadłościan

Zadaniem Twojego programu będzie obliczenie objętości i pola powierzchni prostopadłościanu o zadanych
wymiarach.

#### Wejście

Jedyny wiersz wejścia zawiera trzy liczby całkowite dodatnie $a, b, c$ ($1 \leq a, b, c < 500 000 000$) oddzielone
spacjami. Oznaczają one trzy wymiary prostopadłościanu, czyli długości trzech prostopadłych krawędzi.

#### Wyjście

W pierwszym wierszu należy wypisać objętość prostopadłościanu o krawędziach długości $a, b, c$. W drugim
wierszu należy wypisać pole powierzchni tego prostopadłościanu. Możesz założyć, że zarówno pole powierzchni
jak i objętość nie przekroczy $2 000 000 000$.

#### Przykład

| Wejście     | Wyjście                              |
| :---------- | :----------------------------------- |
| 1 1 2       | 2 <br> 10                            |

[Sprawdź kod na Szkopule :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/VK8v3juXpnadGvD7J6TiXQC_/site/?key=statement){ .md-button .md-button--primary }

### Zadanie 3. Czas

Napisz program, który przelicza czas podany w sekundach na zapis uwzględniający godziny, minuty oraz
sekundy.

#### Wejście

Jedyny wiersz wejścia zawiera jedną liczbę całkowitą $t$ ($1 \leq t \leq 1 000 000$), oznaczającą czas wyrażony w sekundach.

#### Wyjście

Twój program powinien wypisać czas $t$ w postaci $g$ g $m$ m $s$ s, gdzie $g$, $m$ i $s$ oznaczają odpowiednio liczbę godzin,
minut i sekund. Innymi słowy, $g$ godzin, $m$ minut i $s$ sekund powinno łącznie dawać $t$ sekund.
Liczby $g$, $m$ i $s$ powinny być całkowite i nieujemne, a liczby $m$ i $s$ nie powinny przekraczać $59$. W liczbach
nie należy wypisywać dodatkowych zer wiodących.

#### Przykład

| Wejście     | Wyjście                              |
| :---------- | :----------------------------------- |
| 4000        | 1g6m40s                              |

[Sprawdź kod na Szkopule :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/cqNJjBtNa5xD63nnsPiH2igk/site/?key=statement){ .md-button .md-button--primary }
