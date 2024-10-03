# Pętla for i tablice

# Część programistyczna: Pętla for i tablice

## Prosta pętla for

Wiemy już, że pętle pozwalają nam wielokrotnie wykonywać takie same lub podobne czynności. Jednym z najprostszych przypadków jest sytuacja, gdy chcemy powtórzyć daną czynność i wiemy dokładnie, ile razy chcemy to zrobić. Można do tego celu użyć poznanej już pętli `while`. Jednak lepiej nadaje się do tego pętla `for`. 

W najprostszej postaci pętla `for` w języku C++ wygląda tak:

```cpp
for (int i = początek; i <= koniec; i++)
	instrukcja;
```

W pętli deklarujemy zmienną całkowitą, którą nazwaliśmy $i$. Jest ona **zmienną sterującą** pętli. Zmienna ta przemierza kolejno wszystkie wartości od _początek_ do _koniec_ (gdzie _początek_ i _koniec_ może być liczbą, zmienną lub ogólnie wyrażeniem arytmetycznym). Dla każdej z tych wartości po kolei wykonywana jest _instrukcja_ wewnątrz pętli. Podobnie jak poprzednio, może to być albo pojedyncza instrukcja, albo instrukcja złożona umieszczona w nawiasach klamrowych.

W poprzedniej lekcji napisaliśmy program, który wypisywał kolejno liczby od 1 do 10. Za pomocą pętli `for` możemy go napisać krócej:

```cpp
#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i <= 10; i++)
		cout << i << endl;
}
```

I jeszcze jeden przykład – program wczytujący liczbę całkowitą $n$ i wyznaczający $n$-tą [liczbę trójkątną](http://pl.wikipedia.org/wiki/Liczba_tr%C3%B3jk%C4%85tna "liczbę trójkątną"), czyli sumę liczb od 1 do $n$. Używamy w nim zmiennej pomocniczej $suma$.

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int suma = 0;
	for (int i = 1; i <= n; i++)
		suma += i;
	cout << suma << endl;
}
```

Pętla w powyższym programie zastępuje więc serię instrukcji postaci:

```cpp
suma += 1;
suma += 2;
...
suma += n;
```

Opowiedzmy jeszcze trochę o innych wariantach pętli `for`. Pętla ta składa się z trzech części, rozdzielonych średnikami. Najczęściej, w pierwszej podajemy początkową wartość zmiennej sterującej. W trzeciej znajduje się **krok** pętli, czyli informacja, jak ma się zmieniać wartość zmiennej sterującej. Zazwyczaj ma ona każdorazowo wzrastać lub maleć o 1 lub o jakąś większą wartość. Druga część wreszcie zawiera warunek logiczny, którego **niespełnienie** powoduje zakończenie pętli. Warunek ten sprawdzamy na początku – jeśli od początku nie jest spełniony, pętla nie wykona się ani razu – jak i po każdym wykonaniu kroku pętli. Zmienną sterującą pętli zwyczajowo nazwaliśmy $i$, ale ogólnie dobór nazwy tej zmiennej może być dowolny.

Przykładowo, gdybyśmy chcieli wypisać wszystkie liczby parzyste od 20 do 0, jak w poprzedniej lekcji, za pomocą pętli `for` napisalibyśmy tak:

```cpp
for (int i = 20; i >= 0; i -= 2)
	cout << i << endl;
```

To jednak nie wyczerpuje możliwości pętli `for`, a tylko te najczęściej używane – za chwilę opowiemy o jej bardziej ogólnych wariantach.

## Tablice

Zapewne nie jest tajemnicą, że nasze programy docelowo powinny obsługiwać również duże dane. Na razie jednak nie jest jasne, jak chcemy w ogóle przechowywać w pamięci wiele liczb czy znaków. Dotychczas, jeśli chcieliśmy w programie wczytać 3 liczby, musieliśmy zadeklarować 3 zmienne (``int a, b, c;``). Ten sposób nie prowadzi daleko – już 100 liczb byłoby absurdalnie trudne.

Z pomocą przychodzą **tablice**. Tablica efektywnie odpowiada kilku (-nastu, -dziesięciu, ... a nawet kilku milionom) zmiennych. Deklarujemy ją w języku C++ w następujący sposób:

```cpp
int tablica[dlugosc];
```

W ten sposób zadeklarowaliśmy tablicę o nazwie _tablica_, która składa się z elementów będących liczbami całkowitymi. Liczbę tych elementów określa _długość_ ( _rozmiar_) tablicy.

Na przykład:

```cpp
int A[4];
```

deklaruje tablicę o nazwie ``A``, w której będą przechowywane 4 liczby całkowite. W praktyce jest to zadeklarowanie $4$ zmiennych, które będą nazywać się ``A[0]``, ``A[1]``, ``A[2]`` oraz ``A[3]``. Możemy od tej pory używać każdej z nich oddzielnie, tak jak dotychczas korzystaliśmy ze zmiennych:

```cpp
cin >> A[0];	
cin >> A[1]; // do zmiennych A[0] i A[1] wczytujemy po jednej liczbie całkowitej
A[2] = A[0] + A[1];		// teraz A[2] będzie sumą wczytanych liczb
A[3] = A[0] - A[1];		// zaś A[3] ich różnicą

Nazwy tablic możemy dobierać dowolnie, tak jak nazwy zmiennych. Długość tablicy jest najczęściej jedną liczbą, pojedynczą zmienną (odpowiadającą np. długości ciągu liczb) albo prostym wyrażeniem arytmetycznym. Przykładowo:

```cpp
int t[n];
```

to tablica o nazwie $t$ zawierająca $n$ elementów. Widzimy, że numerujemy je zawsze od zera: $t[0],t[1],\ldots,t[n-1]$.


Przypomnijmy sobie nasz poprzedni program, który sumował liczby podane przez użytkownika, i przepiszmy nasz poprzedni program z użyciem tablicy. Zmienna sterująca pętli będzie, jak poprzednio nazywać się $i$, przy czym w $i$-tym okrążeniu chcemy wpisać wartość do $i$-tej komórki tablicy -- innymi słowy, w $i$-tym okrążeniu użyjemy instrukcji ``cin >> t[i]``. Ponieważ elementy tablicy numerujemy od zera, więc zmienna sterująca $i$ będzie tym razem przyjmować wartości $0,1,\ldots,n-1$:

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int t[n];
	int suma = 0;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		suma += t[i];
	}
	cout << suma << endl;
}
```

Kolejny przykład to wczytanie ciągu liczb o długości $n$ i wypisanie go w odwrotnej kolejności – od ostatniej liczby do pierwszej. W odróżnieniu od poprzedniego, tego zadania nie da się już łatwo rozwiązać bez użycia tablic:

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int t[n];
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = n - 1; i >= 0; i--)
		cout << t[i] << " ";
	cout << endl;
}
```

## Ogólna pętla for

Jak dotychczas używaliśmy tylko konkretnego, dosyć prostego schematu pętli `for`. Teraz opiszemy wygląd pętli `for` w pełnej ogólności. Pozwoli nam to dokładniej zrozumieć, jak działa ta pętla.

```cpp
for (instrukcja_początkowa; warunek_stopu; krok_pętli)
    instrukcja;
```

Mamy tu trzy zasadnicze części:

- **Instrukcja początkowa** to instrukcja, która zostaje wykonana na samym początku pętli, niezależnie od wszystkiego. Zazwyczaj jest to instrukcja przypisania, która może wystąpić wraz z deklaracją zmiennej (zmiennych) albo bez, jeśli zmienna (zmienne) są zadeklarowane przed pętlą.
- **Warunek stopu** to dowolny warunek logiczny (czyli taki jak w instrukcjach `if` oraz `while`). Niespełnienie tego warunku **przed** wykonaniem danego obrotu pętli powoduje zakończenie pętli.
- Wreszcie **krok pętli** to instrukcja, która jest wykonywana **po** każdym obrocie pętli. Często jest ona używana do zmiany wartości zmiennej (zmiennych) sterujących pętli.

A zatem pętla `for` działa w następującym cyklu:

```
instrukcja_początkowa;
sprawdź warunek_stopu - jeśli fałszywy, to koniec
instrukcja;
krok_pętli;
sprawdź warunek_stopu - jeśli fałszywy, to koniec
instrukcja;
krok_pętli;
...
```

Koniec następuje wtedy, gdy warunek stopu przed kolejnym obrotem pętli staje fałszywy. Jeśli to nigdy nie nastąpi, ma miejsce zapętlenie. Dodajmy jeszcze, że każda z części pętli może być pusta (wtedy po prostu nic tam nie piszemy).

**Uwaga:** Używając tylko pętli `while`, można napisać ciąg instrukcji równoważny ogólnej pętli `for`. (Czy potrafisz to zrobić?) Tak więc często taki sam kod można wyrazić albo za pomocą ogólnej pętli `for`, albo za pomocą pętli `while`. Programista ma wtedy zupełną dowolność, której metody użyć. Ot, jak mu będzie wygodniej!

Oto przykład zastosowania ogólnej pętli `for` do zadania o zliczaniu cyfr z poprzedniej lekcji. Według nas wygląda zdecydowanie mniej czytelnie niż z użyciem pętli `while`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int liczba_cyfr = 0;
    if (n == 0)
        liczba_cyfr = 1;
    else
        for (; n > 0; n /= 10)
            liczba_cyfr++;
    cout << liczba_cyfr << endl;
}
```


# Część techniczna: Błędy wykonania i błędne odpowiedzi cz. 3

Część techniczną rozpoczniemy dosyć nietypowo. Wprowadzimy ciąg liczb, który pojawia się nierzadko w matematyce, informatyce, lecz także w biologii, muzyce, a nawet w analizie rynków finansowych. Jest to ciąg **liczb Fibonacciego**. Pierwsze wyrazy tego ciągu wyglądają tak:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...

Pierwsze dwie liczby Fibonacciego to 0 i 1, a każda kolejna liczba jest sumą dwóch poprzednich, np. $8 = 3 + 5$, $34 = 13 + 21$. Zazwyczaj $n$-tą liczbę Fibonacciego oznacza się jako $F_n$ lub $Fib_n$.

Zainteresowanych Czytelników zachęcamy do poszukania w sieci więcej informacji o liczbach Fibonacciego. My tymczasem spróbujemy napisać program, który wyznaczy 50-tą liczbę Fibonacciego (zakładamy, że zerowa liczba Fibonacciego to 0).


Skorzystajmy z tablicy, w której będziemy przechowywać kolejne liczby Fibonacciego. Piszemy i uruchamiamy poniższy program:

```cpp
#include <iostream>

using namespace std;

int main()
{
	int fib[50];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= 50; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	cout << fib[50] << endl;
}
```

Niestety w wyniku działania programu nie otrzymujemy żadnej liczby, a tylko komunikat, że program skończył się z błędem. Jest to tzw. **błąd wykonania**. Pierwszy przykład błędu wykonania mieliśmy już w lekcji drugiej, gdy w programie wykonującym dzielenie wprowadziliśmy dzielnik równy 0. W tym programie jest inna usterka, która powoduje ten błąd. Otóż wychodzimy indeksem poza tablicę. Rzeczywiście, tablica $fib$ składa się z elementów $fib[0],\ldots,fib[49]$, a my zarówno w pętli dla $i=50$, jak i w ostatniej instrukcji korzystamy z pola $fib[50]$.

Wyjście indeksem poza tablicę (czy też w stronę ujemnych indeksów, czy też ponad rozmiar) jest częstą i zarazem kłopotliwą usterką. Może powodować niezdefiniowane działanie programu: błąd wykonania, błędną odpowiedź, a czasem nawet, jeśli nam się poszczęści, wynik programu jest poprawny. Jest to ponadto niedeterministyczne: program może działać inaczej na jednym komputerze, a inaczej na innym. Dlatego wielu programistów, zwłaszcza w programach pisanych na szybko, wpisuje zawsze rozmiar tablicy o kilka elementów większy niż rozmiar ściśle wymagany – właśnie na wypadek własnego przeoczenia. W naszym przypadku wystarczy wpisać rozmiar 51:

```cpp
#include <iostream>

using namespace std;

int main()
{
	int fib[51];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= 50; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	cout << fib[50] << endl;
}
```

Gdy uruchomimy ten poprawiony program, otrzymujemy w wyniku liczbę:

```
-298632863
```

Jest to wynik ewidentnie błędny, gdyż wszystkie liczby Fibonacciego są nieujemne. Co tym razem poszło nie tak? W poprzedniej lekcji, mierząc się z podobnym problemem, wykorzystaliśmy dodatkowe wypisywania. Zróbmy tak samo teraz:

```cpp
#include <iostream>

using namespace std;

int main()
{
	int fib[51];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= 50; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		cout << i << " " << fib[i] << endl;
	}
	cout << fib[50] << endl;
}
```

Wyniki programu do pewnego momentu wyglądają rozsądnie, ale gdzieś między 40-tym a 50-tym elementem zaczynają pojawiać się liczby ujemne:

```
2 1
3 2
4 3
5 5
6 8
7 13
8 21
9 34
...
36 14930352
37 24157817
38 39088169
39 63245986
40 102334155
41 165580141
42 267914296
43 433494437
44 701408733
45 1134903170
46 1836311903
47 -1323752223
48 512559680
49 -811192543
50 -298632863
-298632863
```

Zauważmy, że 46-ta liczba Fibonacciego jest równa prawie $2 \cdot 10^9$, czyli ledwie mieści się w zakresie typu `int`. Kolejne liczby po prostu wychodzą już poza zakres, co objawia się ujemnymi (oraz bezsensownymi dodatnimi) wartościami. W tym przypadku wystarczy zmienić typ elementów tablicy na jakiś 64-bitowy, np. `long long`:

```cpp
#include <iostream>

using namespace std;

int main()
{
	long long fib[51];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= 50; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		cout << i << " " << fib[i] << endl;
	}
	cout << fib[50] << endl;
}
```

Dzięki temu już wiemy, jaka jest 50-ta liczba Fibonacciego:

```
...
40 102334155
41 165580141
42 267914296
43 433494437
44 701408733
45 1134903170
46 1836311903
47 2971215073
48 4807526976
49 7778742049
50 12586269025
12586269025
```

Błąd przekroczenia zakresu zmiennej jest kolejnym typowym błędem popełnianym przez programistów. W tym przypadku wystąpił on dlatego, że liczby Fibonacciego naprawdę szybko rosną. Jeśli nasz program nie działa, dobrze jest sprawdzić kod pod kątem tego typu błędów – zwłaszcza jeśli w programie wykonujemy np. wiele mnożeń.

Na koniec dwa pytania do przemyślenia:

- Czy umiałbyś wyznaczyć pięćdziesiątą liczbę Fibonacciego bez użycia tablicy?
- Jaką największą liczbę Fibonacciego można wyznaczyć, używając typu `long long`? A jaką z użyciem typu `unsigned long long`?

## Zadania

[Silnia :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#sil){ .md-button .md-button--primary }

[Na przemian :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#nap){ .md-button .md-button--primary }

[Pierwszy i ostatni :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#pie){ .md-button .md-button--primary }

[Papryczki logarytmiczne (*) :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#pap){ .md-button .md-button--primary }
