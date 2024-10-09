# Pętla while

## Część programistyczna: Pętla while

Jak wiadomo, komputery potrafią wykonywać miliony instrukcji w ułamku sekundy, ale jak je do tego zmusić? Gdybyśmy chcieli używać tylko dotychczas poznanych instrukcji, musielibyśmy fizycznie zapisać je milion razy. Jest zatem oczywiste, że potrzebujemy czegoś, co pozwoli nam na wprowadzenie do programu jakiegoś rodzaju powtarzania instrukcji. Takie konstrukcje nazywają się *pętlami* (ang. *loop*), a na tej lekcji poznamy pierwszą z nich – pętlę `while`, zwaną po polsku czasem (*pętlą "dopóki"*).


Pętla `while` w języku C++ wygląda następująco:

```cpp
while (warunek)
	instrukcja;

```

Jest ona z wyglądu dosyć podobna do instrukcji `if`. _Warunek_ jest warunkiem logicznym (czyli przyjmującym wartość `true` lub `false`), natomiast _instrukcja_ jest pojedynczą instrukcją lub (częściej) instrukcją złożoną, czyli grupą kilku instrukcji umieszczonych w nawiasach klamrowych ``{ ... }``. Pętla `while` wykonuje kolejne _obroty_. W każdym obrocie najpierw jest sprawdzany _warunek_. Jeśli jest on prawdziwy, wykonywana jest _instrukcja_, a w przeciwnym razie pętla kończy się. Czyli jeśli _warunek_ jest prawdziwy, wykonujemy _instrukcję_, po czym znów sprawdzamy _warunek_ – jeśli jest spełniony, znów wykonujemy _instrukcję_ i tak dalej – aż do chwili, gdy po wykonaniu _instrukcji_ _warunek_ nie będzie już spełniony. 

Można zatem pętlę `while` odczytać tak: "dopóki jest spełniony _warunek_, wykonuj _instrukcję_". Trzeba jednak zawsze pamiętać o krokowym charakterze tej pętli: sprawdzenie warunku – wykonanie instrukcji – sprawdzenie warunku – wykonanie instrukcji – ...

Za pomocą pętli `while` możemy np. wypisać dowolnie wiele liczb. Na przykład wszystkie liczby od 1 do 10:

```cpp
#include <iostream>
using namespace std;

int main() {
	int i = 1;
	while (i <= 10) {
		cout << i << endl;
		i++;
	}
}
```

Jak działa ta pętla? Zaczynamy od $i=1$. Sprawdzamy warunek pętli – jest spełniony. A zatem wykonujemy instrukcję złożoną: wypisujemy wartość $i$, czyli 1, i zwiększamy $i$ o 1. Teraz $i=2$. Warunek jest wciąż spełniony, więc wypisujemy liczbę 2 i zmienna $i$ otrzymuje wartość 3. I tak dalej. Na końcu, gdy $i=10$, po sprawdzeniu warunku i wykonaniu instrukcji mamy $i=11$. Warunek nie jest już spełniony, pętla kończy się.


Warto zwrócić uwagę na dwa szczególne przypadki. Jeśli warunek od razu na początku jest fałszywy, pętla nie wykona ani jednego obrotu – poniższy kawałek kodu zwyczajnie nie zrobi nic:

```cpp

int i = 999;

while (i <= 10) {
	cout << i << endl;
}
```

Jeśli zaś _warunek_ jest zawsze prawdziwy, pętla obraca się w nieskończoność (o tym drugim przypadku więcej opowiemy w komentarzu).


Na naszą przykładową pętlę można spojrzeć jako na ciąg złożony z wielu przypisań. Zmienna $i$ zmienia się w każdym obrocie pętli – taką zmienną nazywamy **zmienną sterująca** pętli, jako że od niej zależy liczba obrotów pętli. Bez problemu napiszemy teraz program, który wypisze wyłącznie liczby parzyste z zakresu od 0 do 20 włącznie, od największej do najmniejszej:

```cpp
#include <iostream>
using namespace std;

int main() {
	int i = 20;
	while (i >= 0) {
		if (i % 2 == 0)
			cout << i << endl;
		i--;
	}
}
```

Lub nieco sprytniej – tak, aby nie "oglądać" po drodze także liczb nieparzystych:

```cpp
#include <iostream>
using namespace std;

int main() {
	int i = 20;
	while (i >= 0) {
		cout << i << endl;
		i -= 2;
	}
}
```

Jako kolejny przykład użyjemy teraz pętli `while`, aby wczytać z klawiatury wiele liczb, a następnie wszystkie je zsumować. Musimy w tym celu wiedzieć, kiedy wpisywanie liczb z klawiatury się zakończy – załóżmy tutaj, że sumowane liczby będą dodatnie, a liczba 0 oznacza koniec wpisywania. To będzie warunek zakończenia naszej pętli.

Użyjemy jednej, zawsze tej samej zmiennej $a$, aby wczytywać kolejne liczby, zaraz po wczytaniu zaś wartość $a$ będziemy dodawać do sumy:

```cpp
#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	int suma = a;
	while (a != 0) {
		cin >> a;
		suma += a;
	}
	cout << suma << endl;
}
```

Powyższa pętla `while` wykonuje się tak długo, aż wczytamy 0. Aby warunek "a != 0" zawsze miał sens, pierwszą liczbę wczytujemy jeszcze przed rozpoczęciem pętli. Oprócz zmiennej $a$ używamy **zmiennej pomocniczej** $suma$ do przechowywania aktualnej sumy liczb.

Często w podobnych programach (szczególnie na Olimpiadzie Informatycznej) stosuje się wygodniejszy sposób wczytywania wielu liczb: wczytujemy najpierw $n$, czyli liczbę liczb do wczytania, a potem same te liczby. Na przykład wprowadzenie ``4 8 1 5 3`` oznacza, że chcemy zsumować cztery liczby: $8 + 1 + 5 + 3$. Osiągniemy to w następujący sposób:

```cpp
#include <iostream>
using namespace std;

int main() {
	int i = 1, n;
	cin >> n;
	int suma = 0;
	while (i <= n) {
		int a;
		cin >> a;
		suma += a;
		i++;
	}
	cout << suma << endl;
}
```

Prześledźmy dokładnie, co dzieje się w tym programie. Najpierw wczytujemy $n$, czyli liczbę liczb do zsumowania. Tym razem zmienna $i$ jest zmienną sterującą pętli: na początku równa jest $1$, pod koniec każdego okrążenia pętli zwiększa się o $1$, a pętla ma działać, dopóki $i$ nie przekroczy $n$. Innymi słowy, pętla wykonuje się dokładnie $n$ razy, a w zmiennej $i$ zawsze jest numer aktualnego obrotu pętli. Zmiennych $a$ i $suma$ używamy w takiej samej roli, jak wcześniej: kolejna liczba wczytywana jest do $a$, i natychmiast dodawana do wartości $suma$.

## Zliczanie cyfr liczby

Naszym następnym celem jest napisanie programu, który sprawdza, ile cyfr ma dana liczba naturalna. Poniższy program oblicza kolejne potęgi 10 (czyli 1, 10, 100, 1000, ...) i szuka pierwszej takie, która jest większa od wczytanej liczby $n$. Przy każdym przemnożeniu zmiennej _pot10_ przez 10, wartość zmiennej $liczba\_cyfr$ zwiększamy o 1. Zauważmy, że w poniższym programie pojawia się dosyć rozbudowana deklaracja zmiennych.

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int liczba_cyfr = 0, pot10 = 1;
	while (pot10 <= n) {
		pot10 *= 10;
		liczba_cyfr++;
	}
	cout << liczba_cyfr << endl;
}
```

**Pytanie:** czy ten program zadziała poprawnie dla $n = 0$?

Powyższy program ma jednak jedną ukrytą wadę. Zauważmy, że nie podawaliśmy ograniczenia na wielkość danych wejściowych, czyli w tym przypadku $n$ – przyjęliśmy tylko milcząco, że zmieści się ona w typie `int`. Zastanówmy się, co by się stało, gdyby powyższy program wywołać z parametrem $n = 2\,000\,000\,000$ (dwa miliardy). Wówczas pętla wykonywałaby się aż do chwili, kiedy _pot10_ $> n$, ale takie _pot10_ powinno być równe $10\,000\,000\,000$. A ponieważ zakres typu `int` jest od około minus dwóch miliardów do około dwóch miliardów, to szukane _pot10_ nie zmieściłoby się w typie, co spowodowałoby nieprzewidziane zachowanie programu (w tym przypadku program nie kończy się).

Istnieje jednak sprytniejsze rozwiązanie, które nie ma wyżej opisanego mankamentu. Zamiast stosować metodę wstępującą ("od dołu do góry", czyli dla coraz większych wartości _pot10_), zastosujemy metodę zstępującą. Będzie ona polegała na "odcinaniu" kolejnych cyfr liczby $n$ (poczynając od ostatniej), aż osiągnie ona zero. Przy każdym odcięciu zwiększamy zmienną pomocniczą przechowującą aktualną liczbę cyfr. Odcinanie ostatniej cyfry odpowiada podzieleniu liczby przez 10. Przypomnijmy, że dzielenie liczb całkowitych w C++ odrzuca resztę z dzielenia. Przy okazji w poniższym programie zadbamy o poprawny wynik dla przypadku $n = 0$.

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
		while (n > 0) {
			liczba_cyfr++;
			n /= 10;
		}
	cout << liczba_cyfr << endl;
}
```

Dodamy jeszcze, że w niektórych z powyższych przykładów pętla `while` wcale nie była najwygodniejszym rozwiązaniem! W kolejnych lekcjach poznamy inny rodzaj pętli, który pozwala wczytywać i wypisywać zadaną liczbę zmiennych w nieco wygodniejszy sposób (pętlę `for`), a także metodę przechowywania wielu zmiennych naraz (**tablice**). Jednak nie warto robić wszystkiego naraz! Dobre zrozumienie pętli `while` jest już i tak nie lada wyzwaniem.



## Część techniczna: Błędne odpowiedzi cz. 2

W części technicznej kontynuujemy temat radzenia sobie z błędnymi odpowiedziami naszych programów. Tym razem założymy, że wiemy, dla jakich danych wejściowych program nie działa, i musimy zlokalizować usterkę w programie. Warto w tym celu przeczytać uważnie program, wiersz po wierszu – może w ten sposób uda się wykryć błąd. Czasem jednak to nie pomaga. Możemy wtedy próbować znaleźć usterkę, wypisując dodatkowe informacje w trakcie działania programu.

Jako przykład rozważymy nasz wcześniejszy program służący do zliczania cyfr liczby z drobnym błędem:

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int liczba_cyfr;
	if (n == 0)
		liczba_cyfr = 1;
	else
		while (n > 0) {
			liczba_cyfr++;
			n /= 10;
		}
	cout << liczba_cyfr << endl;
}
```

Jeśli uruchomimy ten program i podamy na wejściu liczbę 1234, uzyskamy wynik:

```
1999525998
```

który niewątpliwie nie ma zbyt wiele wspólnego z oczekiwanym wynikiem 3. Ewidentnie coś jest bardzo nie tak.

Aby spróbować znaleźć błąd, spróbujmy wypisać wartości zmiennych $n$ oraz $liczba\_cyfr$ w kolejnych obrotach pętli:

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int liczba_cyfr;
	if (n == 0)
		liczba_cyfr = 1;
	else
		while (n > 0) {
			liczba_cyfr++;
			n /= 10;
			cout << n << " " << liczba_cyfr << endl;
		}
	cout << liczba_cyfr << endl;
}
```

Wyjście tego programu (dla liczby 1234) wskazuje, że z pętlą `while` najwyraźniej wszystko jest w porządku, ale coś nie gra ze zmienną $liczba\_cyfr$.

```
123 1999525995
12 1999525996
1 1999525997
0 1999525998
1999525998
```

Aby rozjaśnić jeszcze sytuację, możemy dodać takie samo wypisanie także przed pętlą `while`:

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int liczba_cyfr;
	if (n == 0)
		liczba_cyfr = 1;
	else {
		cout << n << " " << liczba_cyfr << endl;
		while (n > 0) {
			liczba_cyfr++;
			n /= 10;
			cout << n << " " << liczba_cyfr << endl;
		}
	}
	cout << liczba_cyfr << endl;
}
```

Oto wynik działania tego programu:

```
1234 1999525994
123 1999525995
12 1999525996
1 1999525997
0 1999525998
1999525998
```

Przed pętlą `while` nic się z tą zmienną nie dzieje. Wiemy już, czego nie zrobiliśmy – nie przypisaliśmy zmiennej $liczba\_cyfr$ początkowej wartości 0. Zmienna, której nie przypisaliśmy żadnej wartości i której wartości nie wczytaliśmy od użytkownika, może mieć w programie zupełnie dowolną wartość (w zakresie typu zmiennej). Co więcej, wartość ta może być różna, gdy uruchamiamy program na różnych komputerach, a nawet przy kolejnych uruchomieniach programu na tym samym komputerze! Czasem można mieć nawet takie "szczęście", że program zadziała poprawnie na naszym komputerze (gdyż zmienna będzie miała akurat wartość 0), ale wysłany np. do serwisu **Szkopuł** będzie działał błędnie. Jest to dość często popełniany błąd, nazywany popularnie _niezainicjowaniem_ lub _niewyzerowaniem_ zmiennej.

I jeszcze druga błędna wersja naszego programu:

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
		while (n >= 0) {
			liczba_cyfr++;
			n /= 10;
		}
	cout << liczba_cyfr << endl;
}
```

Gdy uruchomimy nasz program dla liczby 1234, wygląda na to, że działa w nieskończoność. Nie bardzo wiadomo, co jest nie tak. Dodajmy wypisywanie:

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
		while (n >= 0) {
			liczba_cyfr++;
			n /= 10;
			cout << n << " " << liczba_cyfr << endl;
		}
	cout << liczba_cyfr << endl;
}
```

Wynikiem programu jest "ściana" liczb wyglądających mniej więcej tak:

```
......
0 3507
0 3508
0 3509
0 3510
0 3511
0 3512
......
```

Najwyraźniej w programie od pewnego momentu zachodzi $n=0$, a tylko zwiększa się $liczba\_cyfr$. Tym razem wszystkiemu winny jest warunek w pętli `while`:

```cpp
		while (n >= 0) {
```

Dla $n=0$ pętla wykonuje się, ale instrukcja:

```cpp
			n /= 10;
```

nie zmienia wartości $n$, więc pętla działa w nieskończoność. Taki błąd nazywamy **zapętleniem**.

W obu przypadkach proste wypisywanie pozwoliło nam szybko wykryć usterkę. Jest to jedna z najczęściej stosowanych metod usuwania usterek z programów. Oprócz prostoty, jej zaletą jest to, że może być stosowana tam, gdzie z różnych powodów inne metody nie mogą być używane.

## Zadania

Oto trzy kolejne zadania do samodzielnego rozwiązania.

[Potęgi dwójki :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#pot){ .md-button .md-button--primary }

[Pomiary :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#pom){ .md-button .md-button--primary }

[Lustro :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#lus){ .md-button .md-button--primary }

[Czy się zatrzyma? (*)  :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#czy){ .md-button .md-button--primary }
