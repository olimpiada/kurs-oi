# Funkcje

# Część programistyczna: Funkcje

## Ctrl-C, Ctrl-V – najgorszy wróg programisty

Zacznijmy od bardzo prostego przykładu: chcemy wczytać od użytkownika pojedynczą liczbę, a następnie wypisać ją obramowaną gwiazdkami: ``*** 5 ***``. Można to zrobić np. w następujący sposób:

```cpp
int x;
cin >> x;
cout << "*** ";
cout << x;
cout << " ***";
cout << endl;
```

To oczywiście było nietrudne. Co jednak zrobimy, jeśli cel będzie trochę inny – wczytać z klawiatury dwie liczby, a potem wypisać, obramowaną gwiazdkami, każdą z nich oddzielnie, a dodatkowo jeszcze ich sumę? Prawdopodobnie spróbujemy czegoś w rodzaju kodu poniżej:


```cpp
int x, y;
cin >> x >> y;

cout << "*** ";
cout << x;
cout << " ***"
cout << endl;

cout << "*** ";
cout << y;
cout << " ***"
cout << endl;

cout << "*** ";
cout << x + y;
cout << " ***"
cout << endl;

```

Nie jest to jednak najszczęśliwszy pomysł: taki kod wydłuża się, jest mało czytelny, trudno się w nim szuka błędów, a na domiar pojawia się jeszcze dodatkowy problem z użyciem metody kopiuj-wklej – powielanie pomyłek. W powyższym kodzie brakuje średnika po ``cout << " ***"``, a ten błąd skopiował się trzy razy. Im więcej w kodzie kopiowania, tym bardziej poprawianie błędów będzie żmudne. Dlatego ważną zasadą jest, żeby **unikać kopiowania i powtarzania kodu**. Na szczęście języki programowania dają wiele możliwości radzenia sobie z tym problemem – czasem można, zamiast powtórzenia użyć odpowiedniej pętli, tym razem jednak wygodniejsza będzie inna podstawowa konstrukcja: **funkcja**. Funkcja to – w dużym uproszczeniu – fragment kodu, który zapisujemy "na boku" i możemy wywoływać wielokrotnie wewnątrz programu.

## Funkcje i ich argumenty

Zaczniemy od kodu, który realizuje zadanie przedstawione powyżej: obramowuje gwiazdkami dwie podane przez użytkownika liczby, a także ich sumę.

```cpp
#include <iostream>

using namespace std;

void obramuj(int a)
{
	cout << "*** ";
	cout << a;
	cout << " ***";
	cout << endl;
}


int main()
{
	int x, y;
	cin >> x >> y;
	obramuj(x);
	obramuj(y);
	obramuj(x+y);
}

```

Przyjrzyjmy się pierwszej części tego programu, którą jest definicja funkcji o nazwie "obramuj". Zapis:

```cpp
void obramuj(int a)
{
	cout << "*** ";
	cout << a;
	cout << " ***";
	cout << endl;
}
```

oznacza następujące polecenie dla programu: *kiedykolwiek napotkasz w programie nazwę obramuj(...), wykonaj powyższy fragment kodu znajdujący się między klamrami, a następnie wróć i kontynuuj dalej program*. Co więcej, w miejsce $a$ wstawiane jest w tym momencie to, co było wtedy w nawiasach – na przykład ``obramuj(10)`` wypisałoby ``*** 10 ***``. Zatem ciąg instrukcji:

```cpp
	obramuj(x);
	obramuj(y);
	obramuj(x+y);
```

wykona ten pierwszy fragment trzykrotnie: za pierwszym razem w miejsce $a$ wstawiona będzie aktualna wartość zmiennej $x$, za drugim aktualna wartość $y$, a za trzecim wartość sumy $x + y$ – czyli tak, jak chcieliśmy. Użycie ``obramuj(...)`` w środku programu nazywane jest **wywołaniem funkcji**.

Zapis ```void obramuj(int a)``` na początku definicji funkcji to jej **nagłówek**. Znajdujące się w nawiasach ``int a`` oznacza, że funkcja oczekuje przy wywołaniu jednej wartości typu ``int``, czyli przyjmuje jedną liczbę całkowitą. Zmienna ``a`` nazywana jest **parametrem funkcji**. Zatem program zrozumie instrukcję ``obramuj(10)``, a także ``obramuj(x+3)``, jeśli zmienna $x$ była typu ``int``. Nieprawidłowa będzie zaś np. konstrukcja ``obramuj("Hello")``. Co znaczy słowo ``void`` przed nazwą funkcji, dowiemy się za chwilę.


## Zwracana wartość

Przyglądnijmy się poniższemu programowi:

```cpp
#include <iostream>

using namespace std;

int szescian(int a)
{
	int b = a*a*a;
	return b;
}


int main()
{
	cin >> x;
	cout << szescian(x);
}
```

Jeśli uruchomimy program i wpiszemy z klawiatury $2$, na ekranie pojawi się $8$. Ale dlaczego? Przyjrzyjmy się najpierw instrukcji ``cout << szescian(x);`` Tak jak poprzednio, w momencie napotkania wywołania ``szescian(x)``, program skacze do definicji funkcji ``szescian`` i wykonuje jej kod, w miejsce $a$ wstawiając to, co było w nawiasach (czyli wartość $x = 2$). Oblicza $b = 2*2*2 = 8$, po czym napotyka instrukcję ``return b``. Oznacza ona, że funkcja **zwraca wynik** (w tym wypadku $8$), a program ma teraz wrócić w miejsce wywołania funkcji, i w miejsce ``szescian()`` wstawić właśnie $8$. Aby zaznaczyć, że funkcja zwraca wynik, w nagłówku przed nazwą piszemy ``int`` -- to oznacza, że wynik ten ma być liczbą całkowitą. Jeśli funkcja nie zwraca żadnego wyniku (tak jak ``obramuj`` w poprzednim przykładzie), piszemy przed nazwą ``void`` (ang. "pustka", "nic").


## Dwa parametry

Poniżej znajduje się funkcja obliczająca minimum (czyli mniejszą z) dwóch liczb całkowitych. Od poprzedniego przykładu różni się tym, że ma dwa parametry:

```cpp
int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}
```

Powyższa funkcja o nazwie _min_ przyjmuje dwa parametry, $a$ i $b$, oba typu `int`. Wynikiem funkcji jest również liczba typu `int`. Zaznaczymy tutaj, że obszar między nawiasami klamrowymi nazywamy **wnętrzem** albo **ciałem** funkcji. Fragment programu występujący we wnętrzu powyższej funkcji widzieliśmy już wielokrotnie, jest to rzeczywiście obliczanie minimum z dwóch liczb. Jak pamiętamy, wynik funkcji opatrzony jest słowem kluczowym `return`. Jeśli $a<b$, to wynikiem funkcji jest $a$, a w przeciwnym razie $b$.

Jeśli zamiast wartości w parametrach funkcji umieścimy jakieś wyrażenia, funkcja również wykona się, ale najpierw obliczy wartości tych wyrażeń. Przykładowo w tym fragmencie programu:

```cpp
int x, y, z;
cin >> x >> y >> z;
cout << min(x + y, y * z);

```

najpierw zostaną obliczone wartości wyrażeń $x+y$ oraz $y-z$, a następnie zostaną one podstawione w miejsce parametrów funkcji `min`.

## Funkcja main

Nie po raz pierwszy okazuje się, że nowość, którą wprowadzamy w lekcji, tak naprawdę już stosowaliśmy wcześniej, tylko o tym nie wiedzieliśmy. Otóż główna funkcja programu, od której zaczyna się jego wykonywanie – funkcja `main` – jest niczym innym jak zwykłą funkcją bez parametrów, której wynikiem jest liczba całkowita typu `int`.

Jest jedna różnica między funkcją `main` a innymi funkcjami. Otóż w funkcji `main` nie trzeba zwracać wyniku za pomocą `return`. Wówczas wynikiem funkcji jest 0, i to umownie oznacza, że program zakończył się poprawnie.



## Zliczanie cyfr liczby, referencje

Kolejny z przykładów to funkcja wyznaczająca liczbę cyfr danej liczby całkowitej. Ten fragment programu również pojawił się już wcześniej – w lekcji 5. Zapisany w postaci funkcji może np. wyglądać tak:

```cpp
#include <iostream>
using namespace std;

int liczba_cyfr(int n) {
	if (n == 0)
		return 1;
	int wyn = 0;
	while (n > 0) {
		wyn++;
		n /= 10;
	}
	return wyn;
}

int main() {
	int n;
	cin >> n;
	cout << liczba_cyfr(n) << endl;
}
```

Pierwsza ciekawa rzecz w tym przykładzie jest taka, że znów mocno korzystamy z faktu, że funkcja kończy się po napotkaniu pierwszego `return`. To oznacza, że w podanej instrukcji warunkowej nie musimy używać części `else`. Jeśli $n=0$, funkcja da w wyniku 1 i natychmiast zakończy się.

Jest też druga, ciekawsza rzecz występująca w tym programie. Otóż w trakcie obliczeń modyfikujemy wartość jej parametru $n$! W funkcji parametr możemy traktować po prostu jako jeszcze jedną zmienną. Co jednak stanie się po wywołaniu tej funkcji? Jaką wartość otrzymamy, gdy na samym końcu programu wypiszemy zmienną $n$?

Okazuje się, że wartość $n$ nie zmieni się w wyniku wywołania funkcji. Gdybyśmy chcieli, aby wartość ta zmieniła się, musielibyśmy przekazać tę zmienną **przez referencję**. Robi się to tak, że przed nazwą danego parametru wpisuje się znak &:

```cpp
int liczba_cyfr(int &n) {
```

Przy takim zapisie funkcji wypisana na końcu zmienna $n$ ma już wartość 0. Jest to może ciekawe, ale w tym przykładzie kompletnie bezużyteczne – dużo lepiej wydaje się zachować w programie początkową wartość zmiennej $n$. Sensowne wykorzystanie referencji pokażemy w kolejnym przykładzie.

Jeśli przekazujemy parametr przez referencję, to musimy pamiętać, aby przy wywołaniu funkcji w miejsce parametru umieścić zmienną (lub np. element tablicy). Nie może to być np. liczba ani wyrażenie arytmetyczne.

## Przykład: Swap

Gdy zacznie się na poważnie programować np. z użyciem tablic, często wykonywaną operacją staje się zamiana wartości dwóch zmiennych. Może to być także zamiana wartości na dwóch pozycjach w tablicy. Gdyby chcieć zamienić wartości zmiennych całkowitych $a$ oraz $b$, moglibyśmy napisać tak:

```cpp
int a, b;
cin >> a >> b;
a = b;
b = a;
cout << a << " " << b << endl;
```

Jednak ten fragment programu **nie działa**! Zauważmy, że po pierwszym przypisaniu wartości obu zmiennych są równe, więc drugie przypisanie nic nie zmieni. W wyniku pierwszego przypisania tracimy wartość zmiennej $a$. Aby jej nie stracić, musimy użyć trzeciej zmiennej, w której zapamiętamy początkową wartość zmiennej $a$.

```cpp
int a, b;
cin >> a >> b;
int c = a;
a = b;
b = c;
cout << a << " " << b << endl;
```

Ze względu na częste występowanie operacji zamiany w programach, dobrze jest także umieścić ją w postaci funkcji. Użyjemy w niej przekazywania parametrów przez referencję.

```cpp
void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}
```

Funkcja ta ewidentnie nie zwraca żadnego wyniku, co oznaczamy, podając jako typ wyniku słówko `void`.

Warto na koniec wspomnieć, że jeśli parametrem funkcji jest tablica, elementy tej tablicy są **automatycznie** podawane przez referencję.

## Przykład: Będzie dalej

Dotychczas omawiane przykłady funkcji dawały w wyniku pojedynczą liczbę lub nawet wartość logiczną, jednak nic bardziej skomplikowanego. Jak moglibyśmy sobie poradzić, gdybyśmy chcieli podać w wyniku nie jedną, lecz np. kilka liczb? Albo np. liczbę i jakiś napis? Można by w tym celu używać przekazywania parametrów przez referencję, jednak jest to dosyć zakręcone. Możemy też wprowadzić typ złożony. Służy do tego celu słówko `struct`.

```cpp
struct osoba {
	string imie;
	int wiek, wzrost;
	bool czy_kobieta;
};
```

W powyższym przykładzie określiliśmy nazwę typu złożonego – _osoba_, oraz elementy, z których składa się typ, tzw. **pola**. Każdy z tych elementów ma swoją nazwę i typ. Tutaj są to: jedno pole typu `string`, dwa pola typu `int` oraz jedno pole typu `bool`.

Odtąd możemy deklarować zmienne typu _osoba_. Do poszczególnych pól takich zmiennych odwołujemy się, podając nazwę pola po kropce. Np.:

```cpp
osoba o;
o.imie = "Ania";
o.czy_kobieta = true;
cout << o.imie << endl;
```

Taką zmienną możemy więc traktować jako kombinat kilku zmiennych różnych typów.

Struktur można używać do przechowywania kilku połączonych informacji w jednym miejscu. Można także się nimi posłużyć w celu przechowywania wyniku funkcji złożonego z wielu elementów. Dobrzy przykład takiego zastosowania znajduje się w komentarzu do lekcji (ułamki).

**Uwaga:** Wielu funkcji nie trzeba za każdym razem pisać w swoich programach, gdyż są one udostępnione w języku C++. Aby użyć funkcji `min` albo `swap`, wystarczy dołożyć na początku programu deklarację:

```cpp
#include <algorithm>
```

Aby użyć funkcji `abs`, obliczającej wartość bezwzględną z liczby, trzeba przy początku programu umieścić:

```cpp
#include <cstdlib>
```

Ważną rzeczą dla programisty jest znajomość podstawowych funkcji dostępnych w języku programowania, którego używa. Nie musi on ich pamiętać dokładnie, ale dobrze, by choć z grubsza pamiętał, że coś takiego było. Wtedy może zawsze znaleźć informacje na temat konkretnej funkcji w Internecie.

## Zasięg zmiennej, zmienne lokalne i globalne

W jednym programie może występować wiele różnych funkcji. Przykład poniżej.

```cpp
#include <iostream>
using namespace std;

int suma(int t[], int n) {
    int wyn = 0;
    for (int i = 0; i < n; i++)
        wyn += t[i];
    return wyn;
}

int min(int t[], int n) {
    int wyn = t[0];
    for (int i = 1; i < n; i++)
        if (t[i] < wyn)
            wyn = t[i];
    return wyn;
}

int main() {
    int n;
    cin >> n;
    int t[n];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    cout << suma(t, n) << endl
         << min(t, n)  << endl;
}
```

Gdzieś na początku kursu mówiliśmy, że zmienną o danej nazwie można zadeklarować w programie co najwyżej raz. Jednak wyjątkiem od tej zasady jest to, gdy zmienne mają różny zasięg. **Zasięgiem** zmiennej nazywamy fragment programu między dwoma nawiasami klamrowymi, w którym ta zmienna jest zadeklarowana. Nie może być dwóch zmiennych o tej samej nazwie, np. $i$, zadeklarowanych w tym samym zasięgu. W skrajnym przypadku druga zmienna może być położona w zasięgu bardziej wewnętrznym od pierwszej, jednak jest to bardzo niewskazane ze względu na możliwość pomyłki (choć program skompiluje się poprawnie).

Możemy jednak zupełnie nieszkodliwie inną zmienną o takiej samej nazwie umieścić w innym miejscu programu. Przykład mamy powyżej: zmienna $wyn$ jest deklarowana dwukrotnie, a zmienna $i$, identyfikator tablicy $t$ oraz zmienna/parametr $n$ są deklarowane aż trzykrotnie, a mimo wszystko program kompiluje się i działa poprawnie! Innymi słowy, wszystkie te zmienne, mimo tych samych nazw, są różne. Nazwy funkcji mogą się powtarzać, ale tylko wtedy, gdy funkcje mają istotnie różne nagłówki (np. _min_ z dwóch liczb i _min_ w tablicy).

Zmienne, które są zadeklarowane w ramach jakiejś funkcji, nazywamy zmiennymi **lokalnymi**. Ich przeciwieństwem są zmienne **globalne**, które są dostępne dla wielu funkcji. Wszystkie dotychczas występujące zmienne w kursie były zmiennymi lokalnymi. Zmienne globalne deklaruje się na zewnątrz wszystkich funkcji. Zmiennej globalnej można używać we wszystkich funkcjach umieszczonych po miejscu jej deklaracji.

Zmienne globalne mają oczywiste zalety i – być może mniej oczywiste, ale jednak poważne – wady. Pierwszą zaletą jest to, że danej zmiennej nie trzeba wielokrotnie deklarować i można jej używać w ramach wielu funkcji. Tak więc jeśli kilka funkcji używa tych samych danych, można je umieścić jako zmienne globalne i wtedy nie trzeba ich ciągle przekazywać jako argumenty funkcji. Drugą zaletą jest to, że zmienne globalne są automatycznie wyzerowane w C++, więc nie trzeba ich inicjować! Podstawową wadą zmiennych globalnych jest to, że czynią program mniej czytelnym i zwiększają ryzyko popełnienia błędu. Łatwo przy pisaniu jednej funkcji zapomnieć, że dana zmienna jest także modyfikowana w innej funkcji. Poza tym cała idea funkcji opiera się na tym, żeby podzielić program na niezależne fragmenty, które w idealnej sytuacji można także wykorzystać w innych programach. Stosowanie zmiennych globalnych istotnie zmniejsza szansę na takie ponowne wykorzystanie kodu.

Czasem jednak można zdecydować się na wykorzystanie zmiennych globalnych. Najczęstszy bodaj przykład to umieszczenie w zmiennych globalnych danych wejściowych i dużych struktur danych (np. tablic) używanych w wielu funkcjach. Pozwala to uniknąć ciągłego przekazywania parametrów między funkcjami. Tablicę będącą zmienną globalną trzeba deklarować ze stałym rozmiarem. Dobrze jest wtedy umieścić ten rozmiar jako stałą (słówko `const`), wtedy w przypadku użycia np. wielu tablic o tym samym rozmiarze zmniejszamy ryzyko błędu wpisania o jedno zero za mało. Zgodnie z powszechną konwencją nazwy stałych pisze się całe wielkimi literami. Przykład tego wszystkiego znajduje się poniżej.

```cpp
#include <iostream>
using namespace std;

const int MAX_N = 1000000;

int t[MAX_N];
int n;

int suma() {
    int wyn = 0;
    for (int i = 0; i < n; i++)
        wyn += t[i];
    return wyn;
}

int min() {
    int wyn = t[0];
    for (int i = 1; i < n; i++)
        if (t[i] < wyn)
            wyn = t[i];
    return wyn;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    cout << suma() << endl
         << min()  << endl;
}
```

# Część techniczna: C++ czy ++C, czyli sztuczki programistyczne

W tej części technicznej opiszemy zagadnienie, którego znajomość nie jest konieczna przy pisaniu programów, jednak poszerza naszą wiedzę o języku C++. W odróżnieniu od poprzedniej części lekcji potraktuj je jako ciekawostkę bardziej niż konieczną wiedzę.

W większości pętli, które dotychczas pisaliśmy, pojawiały się instrukcje `i++` lub `i--`. W języku C++ dostępne są także instrukcje `++i` oraz `--i`. Czym one się różnią od tych wcześniejszych?

Aby to zrozumieć, trzeba wiedzieć, że każde przypisanie ma w języku C++ wartość. Wartością tą jest prawa strona przypisania. A zatem przypisanie możemy traktować jako _funkcję_ zwracającą wynik przypisania. Przykładowo, wskutek wykonania instrukcji:

```cpp
int a, b, c;
a = b = c = 1;
```

wszystkie trzy zmienne uzyskują wartość $1$. Działa to tak, że najpierw zmiennej $c$ przypisujemy wartość 1. Wynikiem przypisania $c=1$ jest prawa strona, czyli $1$, i w przypisaniu $b=(c=1)$ zmienna $b$ uzyskuje wartość $1$ (w powyższym wyrażeniu mogliśmy pominąć nawiasy). Na końcu to samo dzieje się ze zmienną $a$.

Tak samo, jak zwykłe przypisanie, również przypisania skrócone zwracają pewną wartość. Jaka to wartość? Otóż taka sama, jak gdyby zamiast przypisania skróconego wpisać równoważne mu pełne przypisanie. Poniższy program:

```cpp
int a, b;
b = 7;
a = b += 7;
```

działa więc tak samo jak:

```cpp
int a, b;
b = 7;
a = b = b + 7;
```

czyli po jego wykonaniu każda ze zmiennych $a$, $b$ ma wartość 14.

Wyjątkiem od tej reguły są wspomniane na wstępie instrukcje zwiększania i zmniejszania zmiennej o jeden. Instrukcja `++i` działa dokładnie tak jak `i+=1`: zwiększa $i$ o 1 i w wyniku daje rzeczywiście nową wartość. Natomiast instrukcja `i++` również zwiększa $i$ o 1, ale w wyniku daje **starą** (niezwiększoną) wartość zmiennej $i$. Podobnie sprawa ma się z instrukcjami `--i` oraz `i--`.

Których z tych instrukcji warto zatem używać? Jeśli po prostu chcemy zwiększyć (lub zmniejszyć) wartość zmiennej o 1, obie instrukcje działają tak samo, jednak instrukcja `i++` (odpowiednio `i--`) jest trochę mniej efektywna, a to dlatego, że musi przechowywać choć przez chwilę zarówno starą, jak i nową wartość zmiennej. Dlatego w pętlach takich jak dotychczas lepiej jest stosować instrukcje `++i` i `--i`. Natomiast są pewne sytuacje, w których instrukcje `i++` i `i--` mogą być wygodne w użyciu. Przykładowo, poniższy program oblicza dokładnie wartość $2^n$, bez konieczności używania dodatkowej zmiennej sterującej $i$:

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int pot2 = 1;
	while (n--)
		pot2 *= 2;
	cout << pot2 << endl;
}
```

Aby zrozumieć, dlaczego tak jest, trzeba wiedzieć, że warunki występujące w instrukcji `if` czy pętli `while` mogą w C++ być także typu całkowitego. Wartość 0 interpretowana jest jako fałsz, a dowolna **niezerowa** (dodatnia lub ujemna) wartość jako prawda. Jeśli wczytamy $n=10$, to wartości $n$ będą maleć od 10 aż do 0. Gdy $n=1$, pętla wykona się po raz ostatni (dziesiąty), gdyż wartością `n--` będzie wtedy wciąż 1.

Dobrym przykładem na wykorzystanie tej ostatniej sztuczki jest też krótszy zapis warunku, że liczba $a$ nie jest podzielna przez liczbę $b$:

```cpp
if (a % b) // to samo co: if (a % b != 0)
	....
```

Po przeczytaniu tej sekcji możesz mieć poczucie, że wprowadzone tu elementy języka C++ bardziej utrudniają pisanie i rozumienie programów, niż je ułatwiają. To po części prawda – program najeżony różnymi takimi sprytnymi instrukcjami może być kompletnie nieczytelny. Jednak rozsądne używanie instrukcji takich jak powyżej może czasami przyczynić się do krótszego zapisu niektórych elementów programów i tak naprawdę zwiększyć jego czytelność. Wszystko zależy tu od wyczucia.

# Zadania

[Wicemistrz :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#wic){ .md-button .md-button--primary }

[Duże liczby :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#duz){ .md-button .md-button--primary }
