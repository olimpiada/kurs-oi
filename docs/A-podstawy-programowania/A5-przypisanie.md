# Instrukcja przypisania i typ znakowy char

# Część programistyczna: Instrukcja przypisania

W tej lekcji opowiemy o podstawowej metodzie nadawania wartości zmiennym – instrukcji **przypisania**. W najprostszej wersji już ją widzieliśmy: aby nadać zmiennej $a$ typu `int` wartość (na przykład) 5, możemy użyć następującej instrukcji:

```cpp
a = 5;
```

Przypisania tego typu stosuje się w szczególności do ustawienia początkowej wartości zmiennej. Jeśli przypisanie następuje bezpośrednio po deklaracji zmiennej, możemy je połączyć z deklaracją:

```cpp
int a = 5;
```

Zamiast pojedynczej liczby w przypisaniu może także wystąpić dowolne wyrażenie matematyczne. Na przykład:

```cpp
int a, x, y;
cin >> x >> y;
a = 2 * x * y + 1;
```

Zmiennym możemy (oczywiście) wielokrotnie przypisywać różne wartości. To uzasadnia, dlaczego nazywamy je właśnie _zmiennymi_. Co ciekawe, zmienna, której przypisujemy nową wartość, może wystąpić także w wyrażeniu po prawej stronie instrukcji przypisania! Oto (bardzo typowa) przykładowa instrukcja:

```cpp
a = a + 3;
```

Jesteśmy przyzwyczajeni do tego, że znak ``=`` oznacza równość dwóch wartości, więc na pierwszy rzut oka taki zapis wydaje się nie mieć sensu – żadna liczba nie może być równa sobie samej zwiększonej o $3$! Ale w C++, jak również w wielu innych językach programowania znak ``=`` **nie jest równością, a poleceniem wstawienia wartości do odpowiedniej komórki**. Instrukcja ``a = a + 3`` jest interpretowana następująco: weź aktualną wartość zmiennej ``a``, dodaj do niej 3, a potem otrzymany wynik wpisz z powrotem do komórki oznaczonej ``a``. Innymi słowy, będzie to zwiększenie wartości zmiennej $a$ o 3.

Załóżmy na przykład, że chcemy wczytać pewną liczbę, dodać do niej 3, pomnożyć przez 2, a następnie dodać jeszcze 1, po każdej operacji wypisując aktualną wartość. Prosty program realizujący te zadania wyglądać może tak:

```cpp
int a;
cin >> a;
a = a + 3;
cout << a;
a = a * 2;
cout << a;
a = a + 1;
cout << a;
```

Wśród początkujących programistów zdarza się dość często taka konstrukcja:

```cpp
int a, b, c, d;
cin >> a;
b = a + 3;
cout << b;
c = b * 2;
cout << c;
d = c + 1;
cout << d;
```

Na ogół jest to spowodowane "nieufnością" do instrukcji postaci ``a = a+3``. Postaraj się jak najszybciej pozbyć wątpliwości – wkrótce przekonasz się, że deklarowanie wielu dodatkowych, niepotrzebnych zmiennych na dłuższą metę przeszkadza znacznie bardziej.


## Skrócone instrukcje przypisania

W języku C++ są też dostępne skrócone instrukcje przypisania. Otóż zamiast:

```cpp
a = a + b;
a = a - b;
a = a * b;
a = a / b;
a = a % b;
```

możemy napisać odpowiednio:

```cpp
a += b;
a -= b;
a *= b;
a /= b;
a %= b;
```

Zatem ostatni przykład można napisać jeszcze krócej:

```cpp
int a;
cin >> a;
a += 3;
cout << a;
a *= 2;
cout << a;
a += 1;
cout << a;
```

Jak okaże się w kolejnych lekcjach, najczęściej do wartości zmiennej dodaje się 1, lub też odejmuje 1. Dlatego dla tych przypadków są jeszcze bardziej skrócone konstrukcje, zwane _inkrementacją_ i _dekrementacją_:

```cpp
a++; // to samo co: a += 1;
a--; // to samo co: a -= 1;
```

Do pierwszej z tych instrukcji nawiązuje sama nazwa języka [C++](http://pl.wikipedia.org/wiki/C%2B%2B "C++"), który został zaprojektowany jako rozszerzenie starszego języka programowania [C](http://pl.wikipedia.org/wiki/C_%28j%C4%99zyk_programowania%29 "C"). Co ciekawe, poprzednikiem języka C był język [B](http://pl.wikipedia.org/wiki/B_%28j%C4%99zyk_programowania%29 "B").

A oto inny przykład. Zobaczymy, jak zastosowanie instrukcji przypisania może uprościć rozwiązanie zadania _Czas_ z lekcji "Błędy w programach, pierwsze zadania". Przypomnijmy, że należało w nim przeliczyć czas $t$ sekund na zapis w godzinach, minutach i sekundach.

To zadanie można oczywiście rozwiązać bez użycia instrukcji przypisania, jednak z jej pomocą rozwiązanie staje się bardziej przejrzyste. Klucz do rozwiązania stanowi wprowadzenie trzech zmiennych: $g$, $m$ i $s$, które oznaczają odpowiednie fragmenty wyniku: liczbę pełnych godzin w czasie $t$, liczbę pełnych minut w tym czasie z wyłączeniem pełnych godzin i pozostałą liczbę sekund. Wartości tych zmiennych możemy obliczać w kolejności $g$, $m$, $s$ lub odwrotnie. W poniższym programie obraliśmy właśnie kolejność odwrotną, natomiast rozwiązanie wybierające kolejność zgodną z podaną pozostawiamy już uczestnikom kursu.

```cpp
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int g, m, s;
	s = t % 60;
	t /= 60;
	m = t % 60;
	t /= 60;
	g = t;
	cout << g << "g" << m << "m" << s << "s" << endl;
}
```


# Część techniczna: Typ znakowy char

W części technicznej lekcji wprowadzimy nowy typ zmiennych – typ znakowy `char`. Pozwala on przechowywać pojedyncze znaki (małe i wielkie litery, cyfry, znaki przestankowe itp.). Wartości typu `char` są w języku C++ otoczone apostrofami, np.  `'a'`,  `'8'`, `'+'`, `'.'`.

Jako pierwszy przykład napiszmy program, który wczytuje dany znak, o którym wiemy, że jest małą literą, i sprawdza, czy jest to samogłoska, czy spółgłoska.

```cpp
#include <iostream>
using namespace std;

int main() {
  char c;
  cin >> c;
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    cout << "samogloska" << endl;
  else
    cout << "spolgloska" << endl;
}

```

Każdy ze znaków typu `char` ma przypisany numer będący liczbą całkowitą. To przyporządkowanie, używane powszechnie w komputerach do reprezentowania znaków, nazywa się [kodem ASCII](http://pl.wikipedia.org/wiki/ASCII "kodem ASCII"). Wygląda ono tak:

| kod  | znak            | kod  | znak | kod  | znak | kod  | znak | kod  | znak           |
| :--- | :---            | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :---           |
| 0-31 | znaki specjalne | 51   | 3    | 71   | G    | 91   | [    | 111  | o              |
| 32   | spacja          | 52   | 4    | 72   | H    | 92   | \    | 112  | p              |
| 33   | !               | 53   | 5    | 73   | I    | 93   | ]    | 113  | q              |
| 34   | "               | 54   | 6    | 74   | J    | 94   | ^    | 114  | r              |
| 35   | #               | 55   | 7    | 75   | K    | 95   | \_   | 115  | s              |
| 36   | $               | 56   | 8    | 76   | L    | 96   | \`   | 116  | t              |
| 37   | %               | 57   | 9    | 77   | M    | 97   | a    | 117  | u              |
| 38   | &               | 58   | :    | 78   | N    | 98   | b    | 118  | v              |
| 39   | '               | 59   | ;    | 79   | O    | 99   | c    | 119  | w              |
| 40   | (               | 60   | <    | 80   | P    | 100  | d    | 120  | x              |
| 41   | )               | 61   | =    | 81   | Q    | 101  | e    | 121  | y              |
| 42   | \*              | 62   | >    | 82   | R    | 102  | f    | 122  | z              |
| 43   | +               | 63   | ?    | 83   | S    | 103  | g    | 123  | {              |
| 44   | ,               | 64   | @    | 84   | T    | 104  | h    | 124  |                |
| 45   | -               | 65   | A    | 85   | U    | 105  | i    | 125  | }              |
| 46   | .               | 66   | B    | 86   | V    | 106  | j    | 126  | ~              |
| 47   | /               | 67   | C    | 87   | W    | 107  | k    | 127  | znak specjalny |
| 48   | 0               | 68   | D    | 88   | X    | 108  | l    |      |                |
| 49   | 1               | 69   | E    | 89   | Y    | 109  | m    |      |                |
| 50   | 2               | 70   | F    | 90   | Z    | 110  | n    |      |                |


Oczywiście nie trzeba pamiętać kodów ASCII poszczególnych znaków. Warto jedynie wiedzieć, że małe litery oraz wielkie litery alfabetu angielskiego (łacińskiego) są ustawione w kodzie kolejno w porządku alfabetycznym, a cyfry – od najmniejszej do największej. Porównywanie znaków typu `char` za pomocą operatorów `<`, `<=`, `>`, `>=` odbywa się według kodów ASCII, tak więc małe litery oraz wielkie litery są porównywane alfabetycznie, a cyfry od najmniejszej do największej. Znaki o kodach od 0 do 31 oraz znak o kodzie 127 to tzw. kody sterujące. Znajdują się wśród nich m.in. znaki końca wiersza i tabulacji; wiele z tych znaków wyszło już z użycia.

Wartości zmiennych typu `char` możemy więc traktować jako niewielkie liczby całkowite. Dokładniej, zmienna typu `char` przyjmuje wartości od -128 do 127, przy czym wartości nieujemne odpowiadają znakom kodu ASCII, a pozostałe mogą służyć do reprezentowania innych symboli (np. polskich znaków ą, ę, ź, ć itp. w niektórych _kodowaniach_). Typ `char` jest więc typem całkowitym jednobajtowym, którego brakowało w komentarzu do lekcji 2. Odpowiadającym mu typem całkowitym nieujemnym (o wartościach od 0 do 255) jest typ `unsigned char`.

Przyjrzyjmy się, jakie konsekwencje ma ta dwoista natura typu `char`.

Przypisując wartość zmiennej typu `char`, możemy to zrobić, albo wstawiając żądany znak w apostrofy, albo podając numer tego znaku w kodzie ASCII. Czyli np. oba poniższe przypisania są równoważne:

```cpp
char znak = 'a';
char znak = 97;
```

Z przyczyn technicznych przy wczytywaniu i wypisywaniu to już tak łatwo nie zadziała. Chodzi o to, że typ `char` wczytuje i wypisuje znak, a nie liczbę. Jeśli więc przy takim fragmencie programu:

```cpp
char znak;
cin >> znak;
```

wpiszemy na wejściu liczbę 97, to zamiast znaku 'a' o kodzie ASCII 97 zostanie wczytany po prostu znak '9', jako pierwszy znak na wejściu!

Aby wczytać znak o danym kodzie ASCII, należy wczytać ten kod jako liczbę całkowitą innego typu niż `char` (np. typu `int`) i przypisać zmiennej _znak_ wczytaną wartość:

```cpp
int kod;
char znak;
cin >> kod;
znak = kod;
```

Oczywiście zadziała to tylko wtedy, gdy _kod_ będzie faktycznie liczbą z zakresu typu `char` – w przeciwnym razie wystąpi znany nam już błąd przekroczenia zakresu typu.

Podobnie z wypisywaniem kodu ASCII znaku:

```cpp
char znak;
int kod;
kod = znak;
cout << kod << endl;
```

Jest to szczególny przykład tzw. **konwersji typów** (inaczej: **rzutowania typów**), czyli zmiany jednego typu na inny. W przypadku typów całkowitych w C++ dokonuje się ona automatycznie, w momencie przypisania zmiennej jednego typu wartości zmiennej (bądź wyrażenia) innego typu. Można też jawnie "poprosić" kompilator C++, aby dokonał konwersji. Robi się to, umieszczając nazwę typu przed zmienną:

```cpp
char znak;
cout << (int)znak << endl;
```

Trochę więcej o konwersjach opowiemy w następnych lekcjach. Tymczasem jeszcze jeden, "złośliwy" przykład. Powiedzmy, że chcielibyśmy napisać program, który wczyta liczbę $i$ i wypisze $i$-tą małą literę alfabetu angielskiego (a zatem $i \in \{1,\ldots,26\}$, alfabet angielski ma bowiem 26 liter). Moglibyśmy to próbować zrobić tak:

```cpp
int numer;
cin >> numer;
cout << 'a' + numer - 1;
```

Gdy na wejściu wprowadzimy np. liczbę 3, na wyjściu otrzymamy... liczbę 99, czyli kod ASCII litery `c`! Jest tak dlatego, że wyniki działań arytmetycznych są w C++ domyślnie interpretowane jako liczby (w tym przypadku typu `int`). Aby otrzymać na wyjściu rzeczywiście literę `c`, musimy użyć konwersji na typ `char`:

```cpp
int numer;
cin >> numer;
cout << (char)('a' + numer - 1);
```

# Zadania

W tej lekcji, oprócz trzech "standardowych" zadań mamy również przygotowane jedno "z gwiazdką", nieco trudniejsze. Jeśli nie potrafisz go jeszcze rozwiązać, nie przejmuj się!

[Łańcuszek :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#lan){ .md-button .md-button--primary }

[Kody szesnastkowe :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#kod){ .md-button .md-button--primary }

[Podzielne :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#pod){ .md-button .md-button--primary }

[Wielkanoc (*) :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#wie){ .md-button .md-button--primary }
