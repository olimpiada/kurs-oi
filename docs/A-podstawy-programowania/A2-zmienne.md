# Wczytywanie, wypisywanie, zmienne

## Zmienne i wczytywanie

W poprzedniej lekcji nauczyliśmy się wypisywać proste komunikaty oraz, w ostatnim przykładzie, liczby całkowite. Aby jednak robić cokolwiek bardziej skomplikowanego – choćby przyjmować dane od użytkownika albo prowadzić obliczenia – potrzebujemy sposobu, aby przechowywać dane w pamięci komputera. Do takich celów służą **zmienne**. Pojedyncza zmienna to komórka pamięci komputera, której na jakiś czas nadajemy nazwę, i która może przechowywać jeden obiekt – na przykład liczbę całkowitą, albo napis złożony z liter.

Najprostszym typem zmiennych są zmienne całkowite, czyli takie, które przechowują jedną liczbę całkowitą. Aby móc korzystać z takiej zmiennej, musimy ją w programie **zadeklarować**, czyli poinformować kompilator o chęci jej użycia oraz nadać nazwę. Deklaracja zmiennej całkowitej wygląda tak:

```C++
int nazwa_zmiennej;
```

Słowo ```int``` informuje kompilator, że zmienna jest właśnie typu całkowitego (ang. **integer**), wybór nazwy zaś należy do nas. Na przykład ```int moja_liczba;``` oznacza, że od tej pory w komórce o nazwie ```moja_liczba``` będzie przechowywana liczba całkowita. Możemy od momentu deklaracji użyć nazwy ```moja_liczba``` wszędzie tam, gdzie w programie mogłaby stać liczba. Na przykład:

```C++
cout << moja_liczba << "\n";
```

to polecenie wypisania na ekran tego, co aktualnie jest w tej komórce, po czym przechodzi do nowego wiersza konsoli. Z kolei:

```C++
moja_liczba = 7;
```
oznacza "do komórki o nazwie ```moja_liczba``` wpisz liczbę ``7``". Zatem:

```C++
moja_liczba = 7;
cout << moja_liczba << "\n";
```
po prostu wypisze na ekran liczbę ``7`` (czyli zadziała dokładnie tak, jak ```cout << 7```).

Spróbujmy teraz sprawić, aby do zmiennej trafiła liczba, którą użytkownik wpisze z klawiatury. Wczytywanie wykonujemy instrukcją:

```C++
cin >> nazwa_zmiennej;
```

czyli bardzo podobnie do wypisywania. W poniższym programie wczytujemy jedną liczbę całkowitą i po prostu ją wypisujemy:

```C++
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    cout << "Wczytana liczba to: " << a << "\n";
}
```

Jeżeli skompilujesz i uruchomisz ten program, to "zatrzyma się" on, oczekując, aż podasz mu (wpiszesz na klawiaturze)
jakąś liczbę całkowitą, np. 123. Kiedy wpiszesz liczbę i naciśniesz ```Enter```, program wypisze liczbę wraz z
komunikatem i zakończy działanie.
Zauważ, że w przeciwieństwie do napisów-komunikatów, nazwy zmiennej nie umieszczamy w cudzysłowie: gdybyśmy napisali instrukcję ```cout << "moja_liczba"```, kompilator wypisałby na ekran po prostu napis ```moja_liczba``` (sprawdź!). Z kolei ```cin >> "moja_liczba"``` zakończyłoby się błędem kompilacji: kompilator nie rozumie, czemu wczytujemy dane do czegoś, co jego zdaniem nie jest zmienną.

W kolejnym programie wczytujemy i wypisujemy dwie liczby. Zauważ, że przy wypisywaniu musimy je jakoś rozdzielić, np. poprzez spację lub ```"\n"```. Natomiast program da sobie radę z ich wczytaniem niezależnie od tego, czy zostaną podane w tym samym wierszu, czy w różnych wierszach, a także niezależnie od dodatkowych spacji wprowadzonych przez użytkownika.

```C++
#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    cin >> a >> b;
    cout << "Wczytane liczby to: " << a << " " << b << "\n";
}
```

Jak już wspomnieliśmy, po wczytaniu zmiennych całkowitych możemy traktować je w programie dokładnie tak, jak same liczby, w szczególności wykonywać na nich działania. Poniższy program wczytuje długości boków prostokąta i oblicza pole i obwód tego prostokąta.

```C++
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << "Pole: " << a * b
         << " obwod: " << 2 * (a + b) << "\n";
}
```


Zauważ, że mogliśmy napisać ```int a, b;``` zamiast dwóch osobnych deklaracji ```int a;```, ```int b;```. Zauważ też, że instrukcja:

```C++
cout << "Pole: " << a * b
         << " obwod: " << 2 * (a + b) << "\n";
```

właściwie "powinna" być w jednym wierszu – na szczęście w C++ możemy dość dowolnie łamać wiersze, jako że dla kompilatora koniec instrukcji wyznacza znak średnika, nie koniec wiersza. Dzięki temu możemy w takich sytuacjach pisać czytelniej.

Jeżeli uruchomimy nasz program i wpiszemy z klawiatury ``2 3`` – czyli ustalimy ```a=2, b=3``` – otrzymamy, zgodnie z oczekiwaniami, wynik:

```
Pole: 6 obwod: 10
```

Spośród standardowych działań dostępne jest dodawanie ```+```, odejmowanie ```-``` i mnożenie ```*```. W przypadku liczb całkowitych możemy też korzystać z dzielenia z resztą, przy czym ```/``` oznacza iloraz, a ```%``` resztę z dzielenia:

```C++
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a << " / " << b << " = " << a / b << " r. " << a % b << "\n";
}
```

Wynikiem tego programu dla ```a=14, b=5``` jest:

```
14 / 5 = 2 r. 4
```

*Uwaga*: podobnie jak w życiu, w C++ nie można dzielić przez 0. Próba wykonania takiego dzielenia (czy to za pomocą /, czy %) zakończy się tzw.
błędem wykonania. Więcej o takich błędach dowiesz się w kolejnych lekcjach. Kolejność wykonywania działań w C++ jest taka sama jak w matematyce.
Dodawanie i odejmowanie mają taką samą ważność, tak więc działania te są wykonywane od lewej do prawej.
Mnożenie i oba typy dzielenia również mają taką samą ważność, więc także są wykonywane od lewej do prawej.
Natomiast mnożenie i oba typy dzielenia są wykonywane przed dodawaniem i odejmowaniem.
Jeśli chcemy uzyskać inną kolejność wykonywania działań, możemy stosować nawiasy ``(`` i ``)``.
Przykładowo, program:

```C++
#include <iostream>
using namespace std;

int main() {
    cout << 1 + 2 * 3 << "\n";
    cout << (1 + 2) * 3 << "\n";
}
```

wypisuje liczby ```7``` i ```9```.

## Styl programów

Należy wiedzieć o kilku ograniczeniach dotyczących nazw zmiennych. Nazwa zmiennej może składać się z małych i wielkich liter, cyfr oraz znaku podkreślenia _, przy czym nie może zaczynać się od cyfry. W przeciwieństwie do niektórych języków programowania, w C++ zawsze rozróżniane są małe i wielkie litery, czyli zmienna ``liczba`` to co innego niż zmienna ``Liczba``. (Nie możemy też np. pisać ``Cout`` zamiast ``cout``, kompilator nie rozpozna nazwy z wielką literą).

Deklaracja zmiennej może zostać umieszczona w programie w dowolnym miejscu przed miejscem, w którym chcemy ze zmiennej skorzystać (czyli np. wczytać lub wypisać jej wartość). Nazwy zmiennych nie mogą się powtarzać (wyjątki od tego ostatniego stwierdzenia przedstawimy później).

Poniższy program oblicza pole i obwód prostokąta dokładnie tak samo, jak poprzedni. Jest on jednak istotnie mniej czytelny.

```C++
#include <iostream>
using namespace std;

int main() {
    int pierwszy_bok,Boknr2;
cin >> pierwszy_bok >> Boknr2;
  cout << "Pole: " << pierwszy_bok*Boknr2
<< " obwod: " << 2*(pierwszy_bok+Boknr2) << "\n";
}
```

Dobrze jednak dbać o to, by Twoje programy wyglądały jednolicie – wtedy za kilka dni łatwiej będzie Ci do nich powrócić. W tym kursie przyjęliśmy kilka powszechnie używanych konwencji, które pomagają zwiększyć czytelność kodu źródłowego, m.in.:

* każdy operator matematyczny (dodawanie, odejmowanie itp.) jest otoczony z obu stron pojedynczymi spacjami,
* po każdym przecinku jest spacja,
* na końcach wierszy nie ma dodatkowych spacji,
* każdy wiersz funkcji `main()` jest wcięty w prawo na taki sam odstęp (to pozwala wyróżnić w kodzie zawartość tej głównej funkcji).

Więcej tego typu konwencji pojawi się przy poznawaniu kolejnych elementów języka C++, jednak zazwyczaj nie będziemy o nich mówić wprost – po prostu będziemy je konsekwentnie stosować.

Teraz powiemy jeszcze tylko o jednym ważnym drobiazgu – o **komentarzach**. Komentarze są to fragmenty kodu źródłowego, które kompilator zupełnie pomija. Ich celem jest zazwyczaj objaśnianie pewnych fragmentów kodu (dla siebie lub dla innych czytelników kodu) albo tymczasowe usuwanie (*wykomentowywanie*) pewnych fragmentów kodu, których w danym momencie nie chcemy jeszcze na trwałe usuwać, ale chcemy, żeby nie były one aktywne. W C++ są dwa typy komentarzy, które wyglądają tak:

```C++
#include <iostream>
using namespace std;

int main() {
    int a, b; // kompilator zignoruje wszystko do konca wiersza
    cin >> a >> b; /* a taki komentarz ...
    moze zajmowac wiele wierszy, pod warunkiem, ze
    zamknie sie znakami: */
    cout << "Iloraz: " << a / b << " reszta: " << a % b << "\n";
}
```

Im dłuższe programy, tym częściej będziemy stosować komentarze.

## Zakres typu

Typ ``int`` pozwala przechowywać tylko liczby całkowite z ograniczonego zakresu: od ```−2147483648``` do ```2147483647```, czyli
mniej więcej od minus dwóch miliardów do plus dwóch miliardów.
Jest to tzw. **zakres** typu. Próba umieszczenia w zmiennej tego typu liczby spoza zakresu
(np. poprzez wczytanie czy w wyniku obliczeń) spowoduje, że wynik obliczeń będzie niepoprawny. Ma to szczególne znaczenie, gdy w programie dodajemy dosyć duże liczby lub wykonujemy mnożenia – najczęściej zamiast "zbyt dużej" liczby pojawia się niespodziewanie dziwna liczba ujemna. Przykładowo, jeśli uruchomimy program obliczający pole prostokąta i jako długości boków podamy ``a = b = 50000``, otrzymamy kompletnie błędne pole prostokąta:

```
Pole: -1794967296 obwod: 200000
```

Dla wygody programisty, w języku C++ wprowadzono kilka typów całkowitych, różniących się zakresami. Poniżej umieszczamy listę tych typów. Na tym etapie nie musisz ich próbować zapamiętać – w początkowych lekcjach typ int będzie dla nas w zupełności wystarczający.

| typ                                                          | zakres                            |
| ----                                                         | -----                             |
| short (pełna nazwa: short int)                               | $[−32768,32767]$                  |
| int                                                          | $[−2147483648,2147483647]$        |
| long long (pełna nazwa: long long int)                       | mniej więcej $[−10^{19},10^{19}]$ |
| unsigned short (pełna nazwa: unsigned short int)             | $[0,65536]$                       |
| unsigned int                                                 | $[0,4294967296]$                  |
| unsigned long long (pełna nazwa: unsigned long long int)     | mniej więcej $[0,2\cdot10^{19}]$  |




