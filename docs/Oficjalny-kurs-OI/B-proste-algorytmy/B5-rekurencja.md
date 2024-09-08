# Rekurencja, potęgowanie i algorytm Euklidesa

## Rekurencja

Znając konstrukcję pętli, łatwo jest napisać funkcję w C++,
która mając dane liczby naturalne $a$ oraz $n$ obliczy $a^n$:

```cpp
int potega(int a, int n)
{
    int wynik = 1;
    for (int i = 0; i < n; i++)
        wynik = wynik * a;
    return wynik;
}
```

Zobaczmy jednak, co by się stało, gdyby napisać ją w zupełnie inny sposób:

```cpp
int potega(int a, int n)
{
    if (n == 1)
        return a;
    int s = potega(a, n - 1);
    return a * s;
}
```

Na pierwszy rzut oka zapis ten wydawać się może dziwny: definiujemy funkcję  `potega()`,
która odwołuje się sama do siebie!
Kompilator C++ (a także innych języków programowania) zareaguje jednak na to polecenie tak,
jak na każde "normalne" wywołanie funkcji

- dokładnie zapamięta, w którym miejscu funkcji `potega()` się znajdował i jaki był stan wszystkich zmiennych,
- skoczy do nowo wywołanej funkcji (nie zwracając uwagi, czy to ta sama, czy inna funkcja),
- obliczy jej wartość wykonując ją wiersz po wierszu,
- mając obliczoną wartość wstawi ją w miejsce zapisu `potega()`, wróci do stanu pierwotnego i będzie dalej wykonywał program.

Prześledźmy to na dwóch prostych przykładach. Jak zadziała wywołanie `potega(5,2)`? Najpierw sprawdzi, czy  `n ` jest równe  `1` – nie jest. Potem trzeba obliczyć wartość zmiennej  `s` przez wywołanie  `potega(5,1)`. Zapamiętujemy zatem, że byliśmy w wierszu 5 wywołania funkcji  `potega(5,2)`, aby za chwilę tam powrócić, i rozpoczynamy wykonywanie  `potega(5,1)`. To wywołanie skończy się bardzo szybko: dla niego  `a = 5`, oraz  `n = 1`, więc już po pierwszych dwóch wierszach wiemy, że trzeba zwrócić wartość 5.

Skoro wiemy już, że  `potega(5,1) = 5,` wracamy z powrotem tam, gdzie byliśmy – do wiersza 5 wywołania  `potega(5,1)`. Obliczoną wartość  `s = 5` należy teraz domnożyć przez  `a` i zwrócić iloczyn `25` – widzimy, że jest to właściwy rezultat działania $5^2$.

Rozważmy teraz wywołanie  `potega(4,3)`. Potrzeba do niego obliczyć wartość  `potega(4,2)`(a potem domnożyć ją przez 4). Wykonujemy zatem  `potega(4,2)`, w którym napotykamy na konieczność obliczenia  `potega(4,1)`. To ostatnie potrafimy obliczyć od razu: jest równe  `4`. Teraz w funkcji  `potega(4,2)` wstawiamy obliczoną wartość jako  `s` i otrzymujemy wynik funkcji  `16`. Wreszcie, wracamy do wiersza 5 w funkcji  `potega(4,3)` domnażamy otrzymaną liczbę `16` przez  `4 ` i dostajemy ostateczny wynik  `64`.

Wywołanie funkcji wewnątrz siebie samej nazywane jest **wywołaniem rekurencyjnym**, a sama technka rozwiązywania problemu przez sprowadzenie go do mniejszej, prostszej wersji tego samego problemu nazywa się  **rekurencją** lub **rekursją**. Aby rekurencja mogła działać, konieczne są trzy warunki:

- Musimy mieć pewność, że rekursja się zakończy – najczęściej sprowadza się to do faktu, że nowe wywołanie dostaje w pewien sposób "prostsze" dane. Na przykład nasze wywołanie  `potega(a,n)` odwołuje się do  `potega(a,n-1)`, zatem zawsze zmniejsza wykładnik.
- Musimy wiedzieć, jak z częściowego wyniku – rezultatu wywołania rekurencyjnego – otrzymać wynik, o który chodziło. W tym wypadku wiemy, jak z wartości `potega(a,n-1)` otrzymać  `potega(a,n)` – wystarczy domnożyć pierwszą wartość przez  `a`.
- Musimy wiedzieć, jak bezpośrednio otrzymać wynik dla najprostszego przypadku, do którego prędzej czy później "dojdzie" rekurencja. Dla powyższej funkcji jest to przepis, jak postąpić dla  `n = 1`.

Spróbujmy rozwiązać za pomocą rekursji jakiś inny problem – na przykład obliczyć funkcję silnia. Przypomnimy, że oznacza się ją symbolem wykrzyknika, a definuje nastąpująco: 

$n! = 1 \cdot 2 \cdot \ldots \cdot n$. 

Na przykład $3! = 1 \cdot 2 \cdot 3 = 6$. Silnię można oczywiście obliczyć prostą pętlą, można jednak też zauważyć, że zawsze zachodzi $n! = 1 \cdot 2 \cdot \ldots \cdot (n-1) \cdot n = (n-1)! \cdot n$. To pozwala napisać taką funkcję:

```cpp
int silnia(int n)
{
   if (n == 1)
       return 1;
   return silnia(n - 1) * n;
}
```

## Szybkie potęgowanie

Wróćmy na chwilę do potęgowania. W rekurencyjnej wersji skorzystaliśmy z faktu, że aby obliczyć $a^n$, wystarczy mieć $a^{n-1}$, a następnie domnożyć je przez $a$. Można w tej obserwacji pójść dalej – dla parzystych $n$, liczba $a^n$ jest kwadratem $a^{n/2}$, na przykład liczbę $2^{12}$ można otrzymać, podnosząc do kwadratu liczbę $2^6$. Zmieńmy zatem trochę zachowanie programu programu w przypadku parzystego wykładnika:

```cpp
int potega(int a, int n)
{
    if (n == 1)
        return a;
    if (n % 2 == 0)
    {
        int s = potega(a, n / 2);
        return s * s;
    } else
    {
        int s = potega(a, n - 1);
        return a * s;
    }
}
```

Ta wersja ma wprawdzie dłuższy kod, ale znacznie przewyższa poprzednią pod względem efektywności działania. Aby na przykład obliczyć  `potega(2,20)`, wywoła  `potega(2,10)`, potem  `potega(2,5), potega(2,4), potega(2,2) ` i wreszcie  `potega(2,1)`. Z każdym wywołaniem (poza ostatnim) związana jest jedna operacja mnożenia, zatem osiągniemy wynik wykonując tylko 5 (zamiast 20) mnożeń. Różnica ta staje się jeszcze bardziej widoczna dla dużych wykładników: dla  `n = 1000` wykonamy zaledwie kilkanaście mnożeń, zamiast tysiąca.

Można pokusić się o dokładniejsze oszacowanie czasu działania algorytmu. Dla uproszczenia pozostańmy przy liczeniu wyłącznie tego, ile wykonaliśmy mnożeń, jako że innych operacji jest mniej–więcej tyle samo w programie. To z kolei zależy od tego, ile było wywołań rekurencyjnych – na każde wywołanie przypada jedna operacja mnożenia. Każde następne wywołanie ma wykładnik albo dwa razy mniejszy (jeśli $n$ było parzyste), albo o jeden mniejszy (dla $n$ nieparzystych) od poprzedniego, jednak ten drugi przypadek - przejście od  $n$ do  $n-1$ nie może zdarzyć się dwa razy z rzędu. Jeśli bowiem  $n$ było nieparzyste, to  $n-1$ będzie parzyste, i następne wywołanie podzieli wykładnik przez 2.

Widać więc, że każde jedno lub dwa kolejne wywołania zmniejszają wykładnik  $n$ dwukrotnie.
Wiemy z poprzedniej lekcji, że liczbę $n$ można dzielić przez 2 dokładnie $\lceil \log_2 n \rceil$ razy,
zanim osiągniemy 1. A zatem w tym wypadku wywołań będzie co najmniej $\lceil \log_2 n \rceil$,
a co najwyżej $2 \cdot \lceil \log_2 n \rceil$.
Jako że logarytm jest bardzo wolno rosnącą funkcją – co omawialiśmy na poprzedniej lekcji –
różnica w szybkości działania naszego nowego programu w porównaniu ze starą wersją dla dużych wykładników $n$ będzie ogromna.
Dlatego ten algorytm nazywa się najczęściej **szybkim potęgowaniem** (funkcjonuje też nazwa **potęgowanie binarne**).

## Największy wspólny dzielnik

Bardzo znanym problemem algorytmicznym jest obliczenie największego wspólnego dzielnika dwóch podanych liczb. Formalnie: mając dane dwie liczby naturalne $a$ i $b$, znaleźć największą liczbę $d$ dzielącą obie. Jednym z możliwych podejść do tego zagadnienia, czasem spotykanym w szkołach, jest rozkład obu liczb na czynniki pierwsze, a następnie wzięcie wspólnych elementów tych rozkładów. Z punktu widzenia algorytmiki jednak sposób ten jest wyjątkowo niefortunny, rozkład na czynniki jest (jak przekonamy się za parę lekcji) dość trudnym obliczeniowo zadaniem. Praktycznie niemożliwe – przy obecnym stanie wiedzy ludzkości – jest rozłożenie w rozsądnym czasie dużej liczby na czynniki pierwsze, za to największy wspólny dzielnik można obliczyć bardzo szybko, dzięki algorytmowi znanemu jako **algorytm Euklidesa**.

Algorytm Euklidesa opiera się na bardzo prostej obserwacji: jeśli jakaś liczba $d$ dzieli dwie liczby  $a$ i $b$, dzieli też ich różnicę $a - b$. Jest też w pewnym sensie odwrotnie – jeśli wspólny dzielnik mają $b$ oraz $a - b$, posiada go z całą pewnością także $a$. To oznacza, że zamiast liczb $a$ i $b$ możemy równie dobrze wziąć $a - b$ oraz $b$. Na przykład, jeśli szukamy wspólnego dzielnika dla pary (39,65) możemy zamiast tych dwóch liczb wziąć 65-39 = 26 oraz mniejszą z dwóch liczb 39. Parę (39,26) w ten sam sposób sprowadzamy do (26,13), potem do (13,13) i ewentualnie do (13,0). Największy wspólny dzielnik liczby i zera to zawsze ta sama liczba – wiemy zatem, że wynik wynosi 13. Ten sposób postępowania można oczywiście zaprogramować za pomocą pętli. Zwróćmy jednak uwagę, że  rekursja pasuje tu wręcz idealnie: potrafimy sprowadzić zadanie do prostszego (parę $(a,b)$ do pary $(b,a-b)$), wiemy jak z "pośredniego" wyniku otrzymać "końcowy" (największy wspólny dzielnik jest po prostu taki sam), oraz wiemy, jak obsłużyć przypadek końcowy (dla pary $(a,0)$ wynikiem jest $a$). Implementacja rekurencyjna okazuje się zatem bardzo prosta:

```cpp
int nwd(int a, int b)
{
    ...  // tu jeszcze czegoś brakuje!
    if (b == 0)
        return a;                 // jeśli jedną z liczb jest zero, wynik to druga liczba
    return nwd(b, a - b);         // wynik dla (a, b) jest taki sam, jak dla (a - b, b)!
}
```

Niestety, program w tej wersji nie zadziała jeszcze poprawnie – tak naprawdę nie chcemy odejmować $b$ od $a$, tylko _mniejszą_ z liczb od _większej_. Bardzo łatwo jednak poprawić algorytm, aby upewnić się, że zawsze a jest większe, zaś b mniejsze, po prostu zamieniając liczby miejscami w razie potrzeby:

```cpp
int nwd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return nwd(b, a - b);
}
```

Algorytm daje już dobre wyniki, ale może się zdarzyć, że będzie działał powoli: na przykład dla pary (10003, 4) będzie 2500 razy odejmował mniejszą liczbę od większej. Aby tego uniknąć, zauważmy, że wynikiem wielokrotnego odejmowania mniejszej liczby  $b$ od większej  $a$, jest ostatecznie reszta z dzielenia  $a$ przez  $b$ (w wyżej wymienionym przykładzie widzimy, że po odjęciu 4 odpowiednią liczbę razy od 10003 otrzymamy 3 – taki sam wynik, jak gdybyśmy od razu podzielili z resztą 10003 przez 4). Zamiast więc liczyć kilka razy różnicę  $a-b$, można od razu przeskoczyć parę kroków zastępując różnicę przez wspomnianą resztę:

```cpp
int nwd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return nwd(b, a % b);
}
```

Jak szybko działa ten algorytm? Przy każdym wywołaniu rekurencyjnym liczba  $a$ (większa) jest zastępowana liczbą  $a \% b$, która jest od niej (co nietrudno pokazać) przynajmniej dwukrotnie mniejsza.
Wiemy zatem, że każde wywołanie zmniejsza przynajmniej dwukrotnie jedną z liczb.
Nie może być zatem więcej niż $\log a + \log b$ wywołań
(bo nie może być więcej niż $\log a$ zmniejszeń  $a$ i $\log b$ zmniejszeń  $b$).
Zatem odpowiedź poznamy po logarytmicznej (a więc bardzo niewielkiej) liczbie kroków.

## Zadania
[Krokodyle :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/VtKRQ2vwWS2XiV4Ga-DVDDpc/site/?key=statement){ .md-button .md-button--primary }

[Wesoła małpka :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/NJw-7zVrYMM4525BRI7emlMb/site/?key=statement){ .md-button .md-button--primary }
