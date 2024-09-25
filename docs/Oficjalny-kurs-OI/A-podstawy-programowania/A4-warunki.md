# Instrukcja warunkowa (if)

Jak dotychczas programy, które pisaliśmy, wypisywały jedynie proste komunikaty lub działały jak kalkulator: pozwalały obliczać wyniki prostych działań. Wprowadzimy teraz instrukcję warunkową, która pozwoli programowi podejmować decyzję o tym, jakąś czynność wykonać, w zależności od tego, czy dany warunek jest spełniony, czy nie.

Schemat instrukcji `if` jest następujący:

```cpp
if (warunek) {
    instrukcja1;
}
else {
    instrukcja2;
}
```

Jako *warunek* musimy podać coś, co ma wartość logiczną – można to ocenić jako prawdziwe lub fałszywe. Jeśli warunek jest prawdziwy, zostanie wykonana instrukcja _instrukcja1_, a w przeciwnym razie _instrukcja2_. Przykładowy program z warunkiem logicznym może wyglądać tak:

```cpp

#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a > 10) {
        cout << "Liczba jest wieksza niz 10!";
    }
    else {
        cout << "Liczba nie jest wieksza niz 10.".
    }
}
```

Widzimy, że napis ``(a > 10)`` w czasie wykonania programu – kiedy już znana jest wartość ``a`` – zawsze jest albo prawdziwy, albo fałszywy, więc program wie, którą z dwóch instrukcji wykonać. Takie napisy nazywamy **warunkami logicznymi**. Najprostsze warunki to takie, które używają operatorów znanych z podstawowej matematyki:


- $<$ (w C++: <)
- $\le$ (w C++: <=)
- $>$ (w C++: >)
- $\ge$ (w C++: >=)
- $=$ (w C++: ==)
- $\not=$ (w C++: !=).

Ale są jeszcze prostsze: słowo ``true`` w języku C++ oznacza warunek, który jest po prostu prawdziwy -- czyli jeśli napiszemy:

```cpp
if (true) {
    instrukcja1;
}
else {
    instrukcja2;
}
```
to zawsze wykona się ``instrukcja1``. Podobnie ``false`` oznacza warunek, który jest zawsze fałszywy. (Nie jest w tym momencie jasne, do czego mielibyśmy użyć takich trywialnych warunków, ale później zobaczymy, do czego nam się mogą przydać.)

Zobaczmy teraz program, który oblicza wartość bezwzględną z liczby całkowitej, tzn. wypisuje tę liczbę bez znaku.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (x >= 0) {
        cout << x << "\n";
    }
    else {
        cout << -x << "\n";
    }
}
```

Jeśli liczba $x$ jest nieujemna, wypisujemy nią samą, a w przeciwnym razie wypisujemy minus tę liczbę (czyli to samo co $x$ przemnożone przez -1). Gdyby w programie użyć warunku:

```cpp
    if (x > 0)
```

program wciąż działałby poprawnie, gdyż nie ma liczby minus zero (jest to po prostu 0).

Instrukcja warunkowa `if` może także składać się z większej liczby warunków, np.:

```cpp
if (warunek1) {
    instrukcja1;
}
else if (warunek2) {
    instrukcja2;
}
else if (warunek3) {
    instrukcja3;
}
else {
    instrukcja4;
}
```

Oznacza to, że jeśli _warunek1_ jest spełniony, to wykonywana jest _instrukcja1_. W przeciwnym razie, jeśli _warunek2_ jest spełniony, wykonywana jest _instrukcja2_, podobnie z _warunkiem3_ i _instrukcją3_. Jeśli żaden z warunków nie był spełniony, wykonywana jest _instrukcja4_. Można także pominąć końcowy `else` w tej instrukcji. Wówczas jeśli żaden z warunków nie jest spełniony, nie jest wykonywana żadna instrukcja. W szczególności, instrukcja if może mieć następującą, najbardziej uproszczoną postać:

```cpp
if (warunek) {
    instrukcja;
}
```

Wtedy jeśli _warunek_ nie jest spełniony, żadna instrukcja nie jest wykonywana, czyli po prostu nic się nie dzieje.

Jako kolejny przykład napiszmy program, który wczytuje liczbę całkowitą i wypisuje jej znak: "+" jeśli jest dodatnia, "-" jeśli jest ujemna, a "0" jeśli jest zerem.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (x > 0) {
        cout << "+" << "\n";
    }
    else if (x < 0) {
        cout << "-" << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}
```

## Warunki w instrukcji if


W opisie warunku możemy także używać tzw. spójników logicznych: **i**, **lub** oraz **nie**, zapisywanych w C++ jako `&&`, `||` oraz `!`. Za pomocą spójników `&&` oraz `||` możemy łączyć dwa warunki lub więcej. Znak `!` możemy postawić przed jakimś warunkiem, umieszczając ten warunek w nawiasach.

**Uwaga:** Znak **&** (ang. _ampersand_) jest na tym samym klawiszu co siódemka. Natomiast znak I (kreska pionowa _, pałka_) jest na tym samym klawiszu co **\** (i może na klawiaturze zawierać w środku dziurkę).

Napiszmy teraz program, który sprawdzi, czy trójkąt o danych trzech bokach jest równoboczny, równoramienny czy różnoboczny:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        // Jezeli a == b oraz b == c, to tez c == a.
        cout << "rownoboczny" << "\n";
    }
    else if (a == b || b == c || c == a) {
        cout << "rownoramienny" << "\n";
    }
    else {
        // Boki sa parami rozne.
        cout << "roznoboczny" << "\n";
    }
}
```

**Uwaga:** Warto zwrócić szczególną uwagę na to, że w języku C++ do sprawdzania równości w warunkach używa się **dwuznaku `==`**. Pojedynczy znak równości oznacza operację _przypisania_, którą widzieliśmy już wcześniej, a której będzie poświęcona następna lekcja kursu. Jeśli w warunku napiszemy `=` zamiast `==`, program skompiluje się, ale nie będzie działał poprawnie!

W jednym warunku możemy użyć różnych typów spójników logicznych. Jednak trzeba wiedzieć, że operatory `&&` i `||` nie są równoważne pod względem pierwszeństwa - operator `&&` ma wyższe pierwszeństwo niż `||`. Aby nie musieć o tym pamiętać i uniknąć zamieszania, poszczególne fragmenty wyrażenia najlepiej umieszczać w nawiasach.

Aby zilustrować łączenie warunków, napiszmy program, który wczyta rok i wypisze liczbę dni w tym roku. Rok ma 365 dni, no może, że jest przestępny - wówczas ma 366 dni. Rok jest przestępny, jeśli dzieli się przez 4. Jeśli jednak dzieli się przez 100, to nie jest przestępny. Wyjątkiem jest sytuacja, gdy rok dzieli się przez 400 - wówczas mimo wszystko jest przestępny (patrz [Wikipedia](http://pl.wikipedia.org/wiki/Rok_przest%C4%99pny "Wikipedia")). Sprawdzanie podzielności w C++ możemy zrealizować za pomocą operatora reszty z dzielenia "%". Oto program:

```cpp
#include <iostream>
using namespace std;

int main() {
    /*
    2012 - przestepny
    2014 - nieprzestepny
    2100, 2200 - nieprzestepne
    2000, 2400 - przestepne
    */
    int rok;
    cin >> rok;
    if ((rok % 4 == 0 && !(rok % 100 == 0)) || rok % 400 == 0) {
        cout << 366 << "\n";
    }
    else {
        cout << 365 << "\n";
    }
}
```

## Instrukcje złożone

W ramach instrukcji `if` mogą występować także tzw. **instrukcje złożone**, czyli składające się z kilku pojedynczych instrukcji. Wśród tych pojedynczych instrukcji mogą występować np. wczytywania, wypisywania, kolejne instrukcje warunkowe `if`, a także instrukcje, które poznamy w kolejnych lekcjach. Instrukcję złożoną otacza się nawiasami klamrowymi { } i może ona występować w dowolnym bloku `if` czy w bloku `else` (może też być w kilku z nich - nie ma tu ograniczeń). W najprostszej postaci wygląda to tak:

```cpp
if (warunek1) {
    instrukcja1;
    instrukcja2;
    ...
    instrukcja7;
} else {
    instrukcja8;
}
```

**Uwaga:** Niektórzy programiści piszą obie klamry w instrukcji złożonej na tej samej wysokości w kodzie źródłowym, żeby zachować pewną symetrię:

```cpp
if (warunek1)
{
    instrukcja1;
    instrukcja2;
    ...
    instrukcja7;
} else
    instrukcja8;
```

Przypomnijmy jednak ponownie, że dla kompilatora nie ma to zupełnie znaczenia, jak podzielimy nasz kod na wiersze.

Przykłady zastosowania instrukcji złożonych będziemy przedstawiać w kolejnych lekcjach.

## Komentarz: Dziedzina algorytmiczna

W pierwszej lekcji wspomnieliśmy postać Al-Chwarizmiego, od nazwiska którego pochodzi słowo algorytm. Al-Chwarizmi zajmował się między innymi metodami (algorytmami) rozwiązywania równań kwadratowych. Równanie kwadratowe to równanie postaci:

$(\star)\quad ax^2 + bx + c = 0$,

gdzie $a$, $b$, $c$ to liczby rzeczywiste, przy czym liczba $a$ musi być różna od zera. W zależności od wartości $a$, $b$ i $c$ równanie $(\star)$ może mieć różne rozwiązania. Dla przykładu, jeśli $a = 1$, $b = 0$ i $c = 0$, to równanie przyjmuje postać $x^2 = 0$ i posiada dokładnie jedno rozwiązanie $x = 0$. Jeśli teraz weźmiemy $a = 1$, $b = 0$ i $c = 1$, to otrzymamy równanie postaci $x^2 + 1 = 0$, które jest równoważne równaniu $x^2 = -1$. Takie równanie nie ma rozwiązania w liczbach rzeczywistych, ponieważ kwadrat każdej liczby rzeczywistej jest nieujemny. Rozważmy jeszcze przypadek, w którym $a = 1$, $b = 3$ i $c = -4$. W tym przypadku możemy łatwo sprawdzić, że rozwiązaniem równania $(\star)$ są liczby $-4$ i $1$. Naszym celem będzie teraz znalezienie ogólnej metody (algorytmu) wyznaczania rozwiązania równania kwadratowego, która mogłaby być realizowana automatycznie, np. z użyciem komputera.


W zadaniu rozwiązywania równania kwadratowego danymi są trzy liczby rzeczywiste $a$, $b$, $c$, definiujące jednoznacznie to równanie, przy czym liczba $a$ musi być różna od 0. Wynikiem działania algorytmu są liczby rzeczywiste, które są rozwiązaniem tego równania (w matematyce nazywane jego pierwiastkami) lub informacja, że równanie nie ma rozwiązania. Precyzyjnie nasze zadanie można zapisać, opisując dane i oczekiwane wyniki:

**Dane:**
trzy liczby rzeczywiste $a$, $b$ i $c$, które są współczynnikami równania kwadratowego $ax^2 + bx + c = 0$, przy czym $a
e 0$

**Wynik:**
pierwiastki równania $ax^2 + bx + c = 0$ lub informacja o ich braku

Parę warunków opisujących dane i wyniki nazywamy _specyfikacją_ zadania algorytmicznego. Mając specyfikację zadania, przystępujemy do jego analizy i zaprojektowania algorytmu zgodnego z tą specyfikacją.

Na początku spróbujmy rozwiązać to równanie metodami matematycznymi. W tym celu dokonamy szeregu przekształceń, które doprowadzą nas do równania równoważnego w postaci, w której jego pierwiastki będzie można już łatwo wskazać. Oto ciąg przekształceń:

$ax^2 + bx + c = 0 \quad\mid :a$,

$x^2 + \frac{b}{a}x + \frac{c}{a} = 0$.

Chcemy teraz skorzystać z tożsamości $p^2 + 2pq + q^2 = (p+q)^2$, gdzie $p = x$. Wówczas $2pq = \frac{b}{a}x$, i $q = \frac{b}{2a}$:

$x^2 + \frac{b}{a}x + \frac{b^2}{4a^2} - \frac{b^2}{4a^2} + \frac{c}{a} = 0$,

$(x + \frac{b}{2a})^2 + \frac{c}{a} = \frac{b^2}{4a^2} \quad\mid -\frac{c}{a}$, sprowadzamy do wspólnego mianownika

$(x + \frac{b}{2a})^2 = \frac{b^2 - 4ac}{4a^2}$.

Oznaczmy przez $\Delta$ wyrażenie $b^2 - 4ac$:

$(\diamond)\quad \Delta = b^2 - 4ac$.

Wówczas możemy nasze równanie zapisać w postaci:

$(x + \frac{b}{2a})^2 = \frac{\Delta}{4a^2}$.

Teraz łatwo już powiedzieć, kiedy nasze równanie ma rozwiązanie w liczbach rzeczywistych, a jeśli ma takie rozwiązanie, to wskazać jego pierwiastki. Liczba rozwiązań równania zależy od znaku $\Delta$.

1. $\Delta < 0$: Równanie nie ma pierwiastków, ponieważ kwadrat liczby rzeczywistej nie może być ujemny.
2. $\Delta = 0$: $(x + \frac{b}{2a})^2 = 0$, zatem równanie ma dokładnie jedno rozwiązanie $x = -\frac{b}{2a}$.
3. $\Delta > 0$: Teraz mamy:
$x + \frac{b}{2a} = \frac{\sqrt\Delta}{2a}$ lub $x + \frac{b}{2a} = \frac{-\sqrt\Delta}{2a}$
i dalej
$x = \frac{-b + \sqrt\Delta}{2a}$ lub $x = \frac{-b - \sqrt\Delta}{2a}$.

Po dokonanej analizie możemy już zapisać szkolny algorytm rozwiązywania równania kwadratowego:

**Algorytm rozwiązywania równania kwadratowego** $ax^2 + bx + c = 0$:

1. oblicz $\Delta = b^2 - 4ac$
2. jeśli $\Delta < 0$
równanie nie ma rozwiązań w liczbach rzeczywistych
zakończ wykonywanie algorytmu
3. jeśli $\Delta = 0$
równanie ma dokładnie jedno rozwiązanie postaci $-\frac{b}{2a}$
zakończ wykonywanie algorytmu
4. jeśli $\Delta > 0$
równanie ma dokładnie dwa rozwiązania postaci
$\frac{b + \sqrt\Delta}{2a}$ i $\frac{b - \sqrt\Delta}{2a}$

Zastanówmy się teraz, co medium wykonujące ten algorytm (uczeń, komputer) powinno umieć, żeby osiągnąć sukces, czyli rozwiązać równanie. Obiektami, na których operuje algorytm, są liczby rzeczywiste. Żeby wykonać algorytm rozwiązywania równania kwadratowego, musimy potrafić wykonywać operacje arytmetyczne na liczbach rzeczywistych (dodawanie, odejmowanie, mnożenie i dzielenie), musimy umieć porównywać liczby rzeczywiste między sobą (tutaj w zasadzie tylko z zerem) oraz wyciągać pierwiastek kwadratowy z dodatniej liczby rzeczywistej (to komputer nie zawsze dobrze potrafi). W algorytmice zbiór obiektów, na których wykonywany jest algorytm, wraz ze zbiorami operacji i relacji na tych obiektach, nazywamy **dziedziną algorytmiczną**. W przypadku algorytmu rozwiązywania równania kwadratowego dziedzinę algorytmiczną tworzą liczby rzeczywiste z operacjami arytmetycznymi, z relacją porównywania oraz z jedną dodatkową operacją – wyciągania pierwiastka kwadratowego z dodatniej liczby rzeczywistej.

Dwie najbardziej popularne dziedziny algorytmiczne zawierające liczby to:

- Zbiór liczb rzeczywistych z operacjami $+$, $-$, $\cdot$, $/$ oraz relacjami $<$, $=$. Przy rozwiązywaniu równania kwadratowego dziedzina ta jest jeszcze rozszerzona o funkcję $\sqrt{\ }$.
- Zbiór liczb całkowitych z operacjami $+$, $-$, $\cdot$, $/$ oraz relacjami $<$, $=$. Operacja $/$ to w tym przypadku operacja dzielenia całkowitego.

W językach programowania odpowiednikami dziedzin algorytmicznych są **typy danych**. I tak, typy całkowite w C++ zostały już omówione w poprzedniej lekcji. W C++ są trzy typy rzeczywiste: _float_, _double_ i _long double_. Jest też dostępna operacja obliczania pierwiastka kwadratowego z liczby: _sqrt_. Więcej o typach rzeczywistych powiemy w lekcji 8.

## Część techniczna: Błędne odpowiedzi cz. 1

Tym razem zastanowimy się nad tym, co robić, kiedy napisany przez nas program nie działa poprawnie. Chodzi o to, że nasz program kompiluje się, ale gdy uruchamiamy go na jakimś teście, otrzymujemy wynik niezgodny z oczekiwaniami. Najprostszą rzeczą, jaką możemy wtedy zrobić, jest przeczytanie programu dokładnie, wiersz po wierszu. Warto zwrócić szczególną uwagę na instrukcje, których znaczenia nie jesteśmy pewni, potencjalnie jeszcze raz o nich przeczytać lub posłuchać.

Gorszą sytuacją jest, gdy nasz program nie działa i **nie wiemy**, dla jakich danych się to dzieje. Ma to miejsce np. wówczas, gdy wysyłamy program do systemu MAIN 2 i dostajemy informację, że program dał błędną odpowiedź, ale nie widzimy konkretnych danych testowych. Warto na początku upewnić się, czy program wypisuje dane **dokładnie** tak, jak to zostało opisane w treści zadania. Np. jeśli program ma wypisać jakieś liczby w jednym wierszu, nie mogą one być umieszczone w różnych wierszach. Nie są też tolerowane żadne dodatkowe komunikaty na wyjściu. Jedyne dopuszczalne odstępstwo to dodatkowe spacje na samym końcu wiersza lub dodatkowe puste wiersze na końcu wyjścia.

Jeśli upewniliśmy się, że nie popełniliśmy żadnego z tych podstawowych błędów, musimy znaleźć jakieś inne wyjście z sytuacji. Jak opisaliśmy wyżej, warto przeczytać kod źródłowy programu - a nuż uda nam się w tej sposób wychwycić usterkę. Jeśli nie, powinniśmy spróbować znaleźć jakieś dane testowe, dla których program nie działa poprawnie. Możemy spróbować wpisać _jakieś_ dane do programu i mieć nadzieję, że akurat uda się wychwycić usterkę. Dużo pewniejszą drogą jest próba _systematycznego_ przejrzenia różnych typów danych wejściowych (zazwyczaj nie da się sprawdzić wszystkich możliwych danych wejściowych, gdyż jest ich zbyt dużo).

Prześledźmy to na przykładzie.


Poniżej znajduje się program służący do klasyfikacji trójkątów na równoboczne, równoramienne i różnoboczne, który pisaliśmy w trakcie tej lekcji, z jedną drobną usterką.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        // Jezeli a == b oraz b == c, to tez c == a.
        cout << "rownoboczny" << "\n";
    }
    else if (a == b || b == c || c == b)
        cout << "rownoramienny" << "\n";
    else {
        // Boki sa parami rozne.
        cout << "roznoboczny" << "\n";
    }
}
```

**Uwaga:** Zakładamy, że w tym programie nie musimy przejmować się tym, czy istnieje trójkąt o podanych długościach boków. Sprawdzanie tego warunku pozostawiamy Tobie do samodzielnego rozwiązania w jednym z zadań domowych do lekcji.

Spróbujmy podać programowi dane odpowiadające różnym typom trójkątów i sprawdźmy, czy wynik był poprawny. Widać, że konkretne liczby nie mają tu większego znaczenia. Wystarczy zatem sprawdzić wszystkie różne _typy_ trójkątów. Wpisujemy kolejno dane wejściowe:

```
2 2 2
2 2 3
2 3 3
2 3 4
```

i otrzymujemy kolejno wyniki:

```
rownoboczny
rownoramienny
rownoramienny
roznoboczny
```

czyli program działa poprawnie dla wszystkich typów trójkątów! Czy jednak aby na pewno **wszystkich**? Otóż nie: w przypadku trójkąta równoramiennego odgrywa pewną rolę to, które dwa boki są równe. Wpisujemy kolejno dane:

```
3 2 2
2 3 2
```

i otrzymujemy wyniki:

```
rownoramienny
roznoboczny
```

Aha, znaleźliśmy błąd! Teraz musimy "tylko" wykryć, jaka usterka w kodzie źródłowym ją spowodowała. Wiemy już, że problem dotyczy trójkątów równoramiennych. Przyjrzyjmy się więc odpowiednim wierszom kodu:

```cpp
else if (a == b || b == c || c == b) {
    cout << "rownoramienny" << "\n";
}
```

Gdy wczytamy się dokładnie w warunek w instrukcji `if`, zobaczymy, że wbrew naszym intencjom drugi i trzeci fragment warunku są identyczne! Teraz już z łatwością poprawiamy błąd:

```cpp
else if (a == b || b == c || c == a) {
    cout << "rownoramienny" << "\n";
}
```

Ogólnie problem błędnych odpowiedzi jest jednym z najczęstszych zagadnień, z jakimi musi mierzyć się programista. Wykrywanie usterek w programach bywa bardzo czasochłonne i warto znać różne metody radzenia sobie z błędnymi odpowiedziami naszych programów. Dlatego temu zagadnieniu będą poświęcone części techniczne kilku następnych lekcji.

## Zadania

W tej lekcji mamy dla Ciebie do rozwiązania trzy zadania dotyczące instrukcji warunkowej `if`.
Dodatkowo, dla uczestników lubiących wyzwania i zainteresowanych przygotowaniem do olimpiad mamy przygotowane nieco trudniejsze zadanie "z gwiazdką".

[Maksimum :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/ZcwTPgWrwMlbFE_9V-RdZ73I/site/?key=statement){ .md-button .md-button--primary }

[Ćwiartka :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/nbPTy9V8tDSUxU0BtkKSDiYe/site/?key=statement){ .md-button .md-button--primary }

[Trójkąt :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/uH0rh2QP6A45kjcz9a_k-ayC/site/?key=statement){ .md-button .md-button--primary }

[Stół (*) :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/lgSDtYv7H3UbdqLhPxRHTuXz/site/?key=statement){ .md-button .md-button--primary }
