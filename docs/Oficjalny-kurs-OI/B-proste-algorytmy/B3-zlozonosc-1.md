# Wstęp do złożoności obliczeniowej

## Testujemy szybkość algorytmów

Spróbujmy rozwiązać następujące zadanie:

*"Dany jest ciąg złożony z $n$ liczb całkowitych dodatnich. Rozstrzygnąć, ile jest jego fragmentów o sumie równej dokładnie $K$."*

Pierwszy i oczywisty sposób: sprawdźmy wszystkie fragmenty. Przechowajmy ciąg w tablicy `A[0..n - 1]`, dla każdej pary liczb $(i, j)$ takiej, że $i < j$, obliczmy sumę `A[i] + A[i + 1] + ... + A[j]` i sprawdźmy, czy jest równa $K$:

```cpp
int licznik = 0; // Tu będziemy zliczać fragmenty o sumie K.

for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        // Podwójna pętla - wykona się dla każdej pary (i, j) przy i < j.
        int suma = 0;
        for (int s = i; s <= j; s++) {
            suma += A[s];
            // Teraz suma == A[i] + ... + A[j].
        }
        if (suma == K) {
            licznik++;
        }
    }
}

cout << licznik << "\n";
```

Jeśli zastanowimy się trochę bardziej, zauważymy że wykonujemy tu bardzo dużo niepotrzebnych obliczeń. Na przykład liczymy sumę `A[1] + A[2] + A[3]`, a chwilę później `A[1] + A[2] + A[3] + A[4]`, sumując ją od nowa. Zróbmy zatem inaczej: ustalmy sobie na chwilę wartość $i$, dla której policzymy sumy `A[i]`, `A[i] + A[i + 1]`, `A[i] + A[i + 1] + A[i + 2]`, każdą następną licząc na podstawie poprzedniej:

```cpp
int licznik = 0; // Tu będziemy zliczać fragmenty o sumie K.

for (int i = 0; i < n; i++) { // Dla ustalonego i:
    int suma = 0; // Zacznij od zera.
    for (int j = i; j < n; j++) {
        suma += A[j];
        // W tej chwili suma równa jest A[i] + A[i + 1] + ... + A[j].
        if (suma == K) {
            // Więc można sprawdzić, czy jest równa K.
            licznik++;
        }
    }
}

cout << licznik << "\n";
```

Jaka jest w praktyce różnica między tymi dwoma algorytmami? Na potrzeby kursu użyjemy do ich przetestowania poleceń systemu Linux -- powiemy o nich więcej w jednym z kolejnych rozdziałów. Na razie wystarczy wiedzieć tylko, że pliki `100.in`, `1000.in` i `5000.in` zawierają odpowiednio 100, 1000 i 5000 liczb całkowitych, zaś poniższe polecenia uruchamiają nasze algorytmy (pod nazwami `program1` i `program2`) na danych z tych plików, oraz mierzą czas potrzebny na działanie programów.

Sprawdźmy zatem ich działanie najpierw dla tablicy 100 liczb:

```sh
$ time ./program1 < 100.in
1

real    0m0.006s
user    0m0.006s
sys     0m0.000s

$ time ./program2 < 100.in
1

real    0m0.003s
user    0m0.003s
sys     0m0.000s
```

Pierwszy program (czyli kod podany wyżej) wypisał wynik `1` i działał 0.006s, a drugi (kod niżej) 0.003s. Nie są to oczywiście duże różnice – wygląda na to, że dla takiej tablicy oba algorytmy są mniej więcej równie dobre. Sprawdźmy dla tablicy 1000 liczb:

```sh
$ time ./program1 < 1000.in
14

real    0m0.629s
user    0m0.629s
sys     0m0.000s
$ time ./program2 < 1000.in
14

real    0m0.003s
user    0m0.003s
sys     0m0.000s
$
```

Pierwszy program – 0.6s, drugi – 0.003s. Różnica około dwudziestokrotna, ale wciąż są to niewielkie czasy. Zobaczmy teraz wynik dla 5000 liczb:

```sh
$ time ./program1 < 5000.in
81

real    1m18.866s
user    1m18.809s
sys     0m0.000s
$ time ./program2 < 5000.in
81

real    0m0.057s
user    0m0.052s
sys     0m0.004s
```

Szybszy program działa w 0.05s, wolniejszy – minutę i 18 sekund. Dla 20000 liczb nie doczekalibyśmy się wyniku w żadnym rozsądnym czasie.

## Złożoność obliczeniowa

Widzimy, że pierwszy program działa nie tylko wolniej, ale też różnica ta pogłębia się coraz bardziej w miarę, jak rosną dane wejściowe do algorytmu. Aby sformalizować tę obserwację, należałoby policzyć, ile instrukcji wykonają oba programy i porównać wyniki. To jednak okazuje się bardziej skomplikowane, niż wydaje się na pierwszy rzut oka. Po pierwsze – których instrukcji? Czy chcemy liczyć linijki kodu, czy pojedyncze operacje arytmetyczne? Nawet tutaj są różnice, bo np. dodawanie wykonuje się na ogół znacznie szybciej niż dzielenie. A może chcemy zejść na bardziej podstawowy poziom i analizować, co jest pojedynczą instrukcją dla mechanizmów wewnątrz komputera (tzw. instrukcje procesora)? Wydaje się to ,,sprawiedliwe'', ale niestety zależy od języka programowania, architektury samego komputera i innych rzeczy, którymi w kontekście algorytmu zwykle nie chcemy się zajmować.

Typowe ,,kompromisowe'' rozwiązanie to wybranie jednego rodzaju operacji, najważniejszej dla programu i skupieniu się tylko na niej -- można wybrać na przykład operacje arytmetyczne (dodawanie, odejmowanie, mnożenie, dzielenie) albo tylko iteracje pętli. Oczywiście aby ten wynik miał sens, trzeba wybrać taką instrukcję, która w programie występuje najczęściej. W naszych przykładach dobrym wyborem jest na przykład instrukcja dodawania (`suma += A[j]`).

Druga ważna kwestia przy liczeniu instrukcji to dane wejściowe. W zasadzie każdy algorytm dla jednych danych będzie działał bardziej efektywnie niż dla innych -- z reguły dla mniejszych działa szybciej, dla większych wolniej. Dobrym wyjściem jest skupienie się na konkretnym *rozmiarze* danych, czyli w naszym wypadku na wielkości wejściowej tablicy, którą oznaczamy przez $n$. Policzmy zatem dla przykładu liczbę instrukcji dodawania (ignorując wszystkie pozostałe) w drugim z naszych programów, na początek dla tablicy mającej $5$ elementów, czyli $n = 5$:

  * Dla `i = 0` będzie `5` instrukcji dodawania (po jednej dla `j = 0, 1, 2, 3, 4`),
  * Dla `i = 1` będą `4` instrukcje (zmienna `j` przybiera wartości `1, 2, 3, 4`, każda iteracja to znowu jedno dodawanie),
  * Dla `i = 2` będą `3` instrukcje,
  * Dla `i = 3` będą `2` instrukcje,
  * Dla `i = 4` będzie `1` instrukcja.
  
Łącznie zatem algorytm wykona $5 + 4 + 3 + 2 + 1 = 15$ instrukcji dodawania. A jaki będzie ,,ogólny'' wynik, dla pewnego $n$? Bardzo podobne rozumowanie prowadzi nas do wyniku 

\[
  n + n-1 + n-2 + \ldots + 1 = \frac{n(n+1)}{2} = \frac{1}{2}n^2 + \frac{1}{2}n.
\]

Liczba instrukcji wykonanych przez algorytm nazywa się **złożonością obliczeniową** tego właśnie algorytmu. Liczba instrukcji zależy oczywiście od danych wejściowych i typowo jest tym większa, im większe są dane. W naszym przykładzie mieliśmy ,,szczęście'' w tym sensie, że dla każdej tablicy o długości $n$ instrukcji byłoby tyle samo. Tak nie musi być dla każdego algorytmu, ale jeśli nie jest, ze wszystkich możliwych danych o rozmiarze $n$ wybieramy te, które byłyby dla nas *najgorsze* i zmusiłyby algorytm do wykonania największej liczby instrukcji. Taką złożoność nazywa się czasem **pesymistyczną** złożonością.

Oszacujmy jeszcze pierwszy (wolniejszy) z naszych algorytmów. Jest to odrobinę bardziej skomplikowane, ale po chwili obliczeń otrzymujemy wynik:

\[
  \frac{(n-1)n(n+1)}{6} = \frac{n^3}{6} - \frac{n}{6}.
\]

Teraz można powiedzieć, skąd bierze się różnica w działaniu, wstawiając do tych wzorów wartości $n$. Dla $n \approx 1000$ wartości tych wyrażeń to około pół miliona w pierwszym wypadku, i około 160 milionów w drugim. Im większe $n$, tym te różnice stają się bardziej znaczące.
Przy odpowiednio dużych (a wciąż ,,życiowych'') danych wolniejszy algorytm przestaje mieć praktyczny sens: nawet zatrudnienie do obliczeń bardzo mocnego komputera nie sprawiłoby, że mógłby rywalizować z szybszym algorytmem. Kluczowy tutaj jest wyraz $n^3$ w pierwszym algorytmie i $n^2$ w drugim. Dlatego pierwszy algorytm (i inne, które wykonują około $n^3$ operacji dla danych wielkości $n$) nazywa się **sześciennymi**, a algorytmy wykonujące $n^2$ operacji -- **kwadratowymi**; dlatego też różnica między algorytmem sześciennym i kwadratowym będzie dla nas kluczowa. Z kolei algorytmy takie jak szukanie maksimum/minimum w tablicy (rozdział "Poruszanie się po tablicach"), dla tablicy wielkości $n$ wykonują około $n$ operacji i nazywamy je **liniowymi**.


