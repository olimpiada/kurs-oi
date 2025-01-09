# Liczby pierwsze, dzielniki

Szukanie liczb pierwszych i rozkład liczby na czynniki pierwsze zajmują w informatyce wyjątkowo ważne miejsce.
Jak dowiemy się w trakcie lekcji, byłoby lepiej dla światowego bezpieczeństwa, aby te problemy okazały się... trudne. I jak dotąd, rzeczywiście nie potrafimy szybko znajdować czynników pierwszych dla bardzo dużych liczb.

Małe liczby potrafimy jednak rozkładać dość skutecznie. Zacznijmy od problemu szukania dzielników zadanej liczby:

## Dzielniki i pierwszość

Bardzo łatwo napisać kod znajdujący wszystkie dzielniki zadanej liczby `n`:

```cpp
for (int i = 1; i <= n; i++)
    if (n % i == 0)
        cout << i << '\n';
```

Program ten ma w oczywisty sposób złożoność $O(n)$: wykona $n$ okrążeń pętli (i tyle samo operacji dzielenia i wypisywania).
Istnieje łatwy sposób przyśpieszenia tego algorytmu – popatrzmy, jakie dzielniki ma, na przykład, liczba 36:

```
36 = 1 * 36
36 = 2 * 18
36 = 3 * 12
36 = 4 * 9
36 = 6 * 6
```

Dzielniki można pogrupować w pary: jeden czynnik z pary jest zawsze mniejszy lub równy 6, drugi zawsze większy lub równy 6. W ogólnym wypadku jeden czynnik będzie mniejszy lub równy $\sqrt{n}$, drugi większy lub równy $\sqrt{n}$. Będziemy więc szukać tylko mniejszych dzielników, większe wyliczając na ich podstawie:

```cpp
for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
        cout << i;
        cout << n / i;
    }
}
```

Teraz mamy w algorytmie tylko jedną pętlę, wykonującą $\sqrt{n}$ iteracji – złożoność algorytmu jest więc $O(\sqrt{n})$.

Zauważmy, że przy okazji rozwiązaliśmy inny problem: potrafimy w złożoności $O(\sqrt{n})$. sprawdzić, czy zadana liczba `n` jest liczbą
pierwszą. Wystarczy w tym celu przekonać się, że nie ma żadnego dzielnika "małego" (mniejszego lub równego $\sqrt{n}$):

```cpp
bool czy_pierwsza(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)                // jeśli n ma mały dzielnik większy od 1
            return false;              // to nie jest pierwsza

    return true;                       // jeśli nie ma małych dzielników, to nie ma żadnych
}
```

## Sito Eratostenesa

Powyższy algorytm ma niezłą skuteczność, jeśli musimy sprawdzić pierwszość jednej, zadanej liczby. Gdybyśmy jednak musieli znaleźć wszystkie liczby pierwsze mniejsze od pewnego $N$, lepiej użyć znacznie szybszego (a przy tym znanego już starożytnym) sposobu, zwanego **sitem Eratostenesa**.

Najpierw piszemy w rzędzie wszystkie liczby $2, 3, ..., N$, po czym bierzemy najmniejszą liczbę – w tej chwili jest to 2 – i wykreślamy wszystkie jej
wielokrotności, czyli 4, 6, 8... Oczywiście wykreślone liczby nie mogą być liczbami pierwszymi, jako że są wielokrotnościami 2.
Teraz bierzemy najmniejszą liczbę, której jeszcze nie wykreśliliśmy (czyli 3), i wykreślamy wszystkie jej wielokrotności. Dalej powtarzamy operację: kolejną liczbą jest 4, ale jest już wykreślona, więc następnym krokiem będzie wykreślenie wielokrotności 5. Wszystkie niewykreślone liczby, które rozpatrywaliśmy po drodze (2, 3, 5, ...) to liczby pierwsze, co łatwo udowodnić: każda taka liczba była niewykreślona, kiedy do niej dotarliśmy, więc nie może być wielokrotnością żadnej z mniejszych liczb. Kontynuujemy tę procedurę tak długo, aż dotrzemy do końca tablicy i rozpatrzymy wszystkie liczby.

```cpp
bool tablica[N+1];           // tablica[j] == false, jeśli liczba jest wykreślona, true jeśli nie jest

for (int i = 2; i <= N; i++)
    tablica[i] = true;

for (int i = 2; i <= N; i++) // bierzemy kolejną liczbę i
    if (tablica[i])          // jeśli nie jest wykreślona
        for (int j = 2 * i; j <= N; j = j + i) // iterujemy się po wszystkich wielokrotnościach i
            tablica[j] = false;

```

Interesujące jest pytanie o złożoność tego algorytmu.
Przede wszystkim, raz sprawdzamy każdą liczbę, w zewnętrznej pętli, pod kątem tego, czy została
wykreślona, czy też musimy ją rozpatrywać.
To daje $N$ operacji. Oprócz nich pozostały właściwie tylko operacje wykreślania, policzmy je więc osobno:

Podczas rozpatrywania liczby 2 wykonamy $\frac{N}{2}$ operacji – tyle jest wielokrotności do wykreślenia. Podczas rozpatrywania liczby 3 wykonamy z kolei $\frac{N}{3}$ operacji, potem $\frac{N}{5}$, $\frac{N}{7}$, i tak dalej. Całkowita liczba wykreśleń wynosi $\frac{N}{2} + \frac{N}{3} + \frac{N}{5} + \frac{N}{7} + \ldots = N \cdot (\frac{1}{2} + \frac{1}{3} + \frac{1}{5} + \frac{1}{7} + \ldots)$, gdzie w
nawiasie sumowane są wszystkie odwrotności liczb pierwszych, nie większych od $N$. Dokładne oszacowanie sumy wykraczałoby daleko poza ramy tego wykładu,
wystarczy nam zatem wiedzieć, że suma jest równa $\log \log N$ (logarytmowi z logarytmu z $N$), pomnożonemu przez pewną stałą.

Całkowita złożoność algorytmu wynosi zatem $O(N \log \log N)$. Należy zauważyć, że $\log \log N$ jest dla wszystkich praktycznych
danych bardzo małą liczbą (na przykład dla $N = 10^{82}$ – szacowanej liczby cząstek we Wszechświecie – $\log \log N$ wciąż jest mniejszy od 9).
Algorytm ten jest więc w praktyce nie do odróżnienia od algorytmów liniowych.

## Zadanie: rozkład na czynniki

Jednym z zadań dołączonych do niniejszej lekcji jest rozkład danej liczby $N$ na czynniki pierwsze.
Co więcej, należy tego rozkładu dokonać w czasie $O(\sqrt{N})$, inaczej (prawdopodobnie) program przekroczy limity czasowe.
Zalecamy w tym zadaniu pamiętać o dwóch rzeczach:

- Okazuje się, że wystarczy znaleźć czynniki pierwsze mniejsze od $\sqrt{N}$ i
  podzielić $N$ przez nie – na przykład rozkładając $N = 110$,
  znajdujemy dzielniki pierwsze 2 i 5, a po podzieleniu przez nie pozostaje 11.
  W ogólnym wypadku albo zostanie 1 (czyli $N$ nie ma już więcej dzielników),
  albo jakaś inna liczba. Jaka musi być ta pozostała liczba?
- Można oczywiście szukać liczb pierwszych (na przykład sitem Eratostenesa),
  aby dzielić $N$ kolejno przez nie, ale nie jest to konieczne.
  Po prostu spróbujmy podzielić $N$ przez 2 tyle razy, ile się uda, a potem analogicznie przez 3.
  Teraz mamy pewność, że nie uda się podzielić przez 4 ani przez 6 – liczba w tym
  momencie na pewno nie jest parzysta.
  Przez jakie liczby uda się nam w ten sposób podzielić N, a przez jakie na pewno nie?

## Znaczenie praktyczne, czyli algorytm RSA

Jeden z najpopularniejszych, najczęściej stosowanych algorytmów szyfrowania, zwany (od nazwisk twórców)
[algorytmem RSA](http://pl.wikipedia.org/wiki/RSA_(kryptografia) "Algorytm RSA - Wikipedia"), bardzo mocno opiera się na
problemie rozkładu na czynniki.
W algorytmie tym wybiera się bardzo duże (na przykład mające po kilkaset _cyfr_) liczby pierwsze $p$ oraz
$q$ i oblicza się ich iloczyn $pq$, który można podać do publicznej wiadomości. Algorytm RSA pozwala zaszyfrować wiadomość, znając wyłącznie
iloczyn $pq$ – tak więc wysłać zakodowaną wiadomość może każdy. Aby jednak ją odszyfrować, trzeba znać liczby $p$ i $q$, czyli
rozłożyć $pq$ na czynniki.

Zauważmy, że nasze algorytmy są tu bezużyteczne – liczba o 100 cyfrach miałaby wielkość około $10^{100}$, więc algorytm sprawdzania dzielników
potrzebowałby aż $10^{50}$ operacji – na każdym komputerze trwałoby to o wiele dłużej, niż wynosi wiek Wszechświata. Jeśli ktoś zatem nie
znajdzie pewnego dnia istotnie szybszych algorytmów rozkładu na czynniki, można przyjąć, że szyfrowanie tą metodą jest bezpieczne. Ze względu na to, jak
szeroko ten algorytm jest stosowany, dobrze byłoby, gdyby rzeczywiście problem rozkładu na czynniki okazał się niemożliwy do szybkiego pokonania. Jak dotąd, nie mamy jednak takiej pewności. Wiemy, że komputer kwantowy – gdyby został skonstruowany i miał pełne możliwości przewidziane przez teorię – potrafiłby bardzo szybko rozkładać liczby na czynniki. Dotychczasowe próby z obliczeniami kwantowymi są jednak na razie dość odległe od tego celu.

Ciekawostką jest fakt, że bardzo podobny problem sprawdzania pierwszości liczby, który był tu dla nas równie trudny, daje się rozwiązać znacznie bardziej efektywnie. Od dawna znane były algorytmy probabilistyczne (takie, które dawały dobry wynik z bardzo dużą szansą, tym większą, im dłużej działały), a w 2002 roku trzech naukowców z Indii podało pierwszy deterministyczny (czyli "klasyczny") algorytm, który szybko sprawdza pierwszość.

## Dodatek: arytmetyka modulo liczba pierwsza

W zadaniu o szybkim potęgowaniu na lekcji 2 należało obliczyć wynik pewnego działania, ale wystarczyło podać jego cztery ostatnie cyfry, czyli resztę z
dzielenia przez 10000. W rozwiązaniu korzystaliśmy z faktu, że reszta z dzielenia zachowuje się "dobrze" przy mnożeniu i dodawaniu (a także odejmowaniu,
ale tej własności nie używaliśmy): jeśli na przykład chcemy pomnożyć przez siebie wiele liczb i znaleźć resztę z dzielenia iloczynu przez $M$,
możemy zamiast tego domnażać do wyniku po kolei każdą liczbę oddzielnie, i po każdej operacji brać resztę z dzielenia. Innymi słowy, możemy wyobrażać sobie,
że cały czas działamy na liczbach między 0 a $M-1$, a wynikami dodawania, mnożenia, a także odejmowania, również są takie liczby. Mówimy wtedy
o *działaniach modulo* $M$, a ogólniej o *arytmetyce modulo* $M$.

Problem pojawia się dopiero, gdy chcemy dokonać dzielenia. Z definicji dzielenie jest odwrotnością mnożenia – każde dzielenie możemy zapisać jako
mnożenie przez liczbę odwrotną: $a \div b = a \cdot \frac{1}{b} = ab^{-1}$. Oczywiście przez liczbę odwrotną do $b$ rozumiemy taką liczbę $b^{-1}$,
że $b \cdot b^{-1} = 1$. Będziemy trzymać się tej definicji także w arytmetyce modulo $M$: $b \cdot b^{-1} \equiv 1 \pmod{M}$. Działając w arytmetyce modulo
$M$ wykonanie dzielenia przez dowolną liczbę $x$ będzie zatem równoważne wykonaniu mnożenia przez $x^{-1}$. Znalezienie odwrotności jest czasami
niemożliwe, na przykład w modulo 9:

- $1 \cdot 1 \equiv 1 \pmod{9}$
- $2 \cdot 5 \equiv 1 \pmod{9}$
- 3 nie ma odwrotności
- $4 \cdot 7 \equiv 1 \pmod{9}$
- $5 \cdot 2 \equiv 1 \pmod{9}$
- 6 nie ma odwrotności
- $7 \cdot 4 \equiv 1 \pmod{9}$
- $8 \cdot 8 \equiv 1 \pmod{9}$

Okazuje się, że jeśli $M$ jest liczbą pierwszą, to dla każdej wartości z przedziału $1\ldots M-1$ istnieje jej odwrotność w arytmetyce modulo $M$.
Odwrotności można szukać na różne sposoby. My zademonstrujemy w tym celu pewną sztuczkę matematyczną: wiadomo (z tzw. [małego twierdzenia Fermata](http://pl.wikipedia.org/wiki/Ma%C5%82e_twierdzenie_Fermata "Małe twierdzenie Fermata - Wikipedia")), że $b^{M-1}$ daje
resztę 1 z dzielenia przez $M$. A zatem $b \cdot b^{M-2} \equiv 1 \pmod{M}$, więc mamy po prostu $b^{-1} = b^{M-2}$. Tę ostatnią potęgę można obliczyć za pomocą znanego z poprzednich lekcji algorytmu szybkiego potęgowania.

Warto wspomnieć jeszcze, że istnieje algorytm, oparty na algorytmie Euklidesa (zwany _rozszerzonym algorytmem Euklidesa_), który pozwala szukać odwrotności również wtedy, jeśli $M$ nie jest liczbą pierwszą – wystarczy, aby odwracana reszta $b$ nie miała wspólnego dzielnika z $M$.

## Zadania
[Rozkład na czynniki :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#roz){ .md-button .md-button--primary }

[Suma liczb pierwszych :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#sum){ .md-button .md-button--primary }
