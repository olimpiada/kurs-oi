# Systemy pozycyjne

## Skąd wziął się system dziesiętny

Ludzkość długo doskonaliła umiejętność zapisywania liczb. Dopiero w późnym średniowieczu Europa odeszła od zapisu ,,odziedziczonego'' po Imperium Rzymskim, do dziś zwanego *liczbami rzymskimi*. W tym systemie litera `I` oznaczała 1, `V` to 5, a litery `X`, `L`, `C`, `D` i `M` odpowiadały kolejno wartościom 10, 50, 100, 500 i 1000 − na przykład 73 to `LXXIII`. Co więcej, by zapisać 4, zamiast `IIII` używa się `IV`. Liczba 9 to `IX`, 40 to `XL` i tak dalej. 12

Czemu odeszliśmy od zapisu rzymskiego? Nie jest trudny do opanowania, ale problemy zaczynają się przy liczbach większych niż 3000 − sami Rzymianie nie byli konsekwentni i mieli kilka różnych metod na większe liczby. Kłopot leży między innymi w tym, że dla każdej ,,nowej'' liczby (5000, 10000, 50000, ...) trzeba użyć nowej litery. Na Olimpiadzie Informatycznej, w której często trzeba wczytywać i wypisywać nawet dziewięciocyfrowe liczby (np. 267 142 129) litery szybko by się skończyły.

Jeszcze większy problem pojawia się, jeśli trzeba często dodawać wiele liczb (*kto nie wierzy, niech spróbuje szybko odpowiedzieć na pytanie, ile to jest XCVII+CLXIX*). To prawdopodobnie względy praktyczne, takie jak księgi rachunkowe i rejestry kupieckie, wymusiły w końcu odejście od systemu rzymskiego. Nowy sposób zapisu został wynaleziony w Indiach, a do Europy dostał się za sprawą Arabów, którzy w średniowieczu panowali m.in. na Półwyspie Iberyjskim − stąd nazwa *cyfry arabskie*. Jak wiemy, w tym zapisie mamy dziesięć cyfr (0, 1, 2, 3, 4, 5, 6, 7, 8, 9), a wartość cyfry zależy od pozycji, na której stoi: w liczbie 273 cyfra 3 oznacza jedności (czyli $3 \cdot 1$, cyfra 7 to dziesiątki ($7 \cdot 10$), a 2 to setki ($2 \cdot 100$). Taki system nazywa się *pozycyjnym*.

## Nie-dziesiętne systemy pozycyjne

To jednak nie jest jedyny możliwy system pozycyjny! Wyobraźmy sobie inny system, w którym zamiast dziesięciu cyfr używamy ośmiu: $0_8, 1_8, 2_8, ..., 6_8, 7_8$ (dla jasności będziemy pisać małą ósemkę przy liczbie jako znak, że zapisana jest w tym nowym systemie). Zamiast liczby $8$ musimy teraz napisać $10_8$, zamiast $9$ − $11_8$, i tak dalej. Ostatnia cyfra w tym systemie będzie oznaczała tradycyjnie ,,jedności'', ale druga cyfra to teraz ,,ósemki'', a nie ,,dziesiątki''. Na przykład zapis $41_8$ w tym systemie oznacza $4 \cdot 8 + 1 = 33$. Największą możliwą liczbą do zapisania dwoma cyframi będzie $77_8$, czyli $7 \cdot 8 + 7 = 63$. Liczba 64, czyli $8 \cdot 8$, będzie już zapisywana jako $100_8$. Trzecia od końca cyfra, zamiast setek, będzie oznaczała ,,sześćdziesiątki czwórki'', czyli wielokrotności $8 \cdot 8$, czwarta od końca − wielokrotności $8 \cdot 8 \cdot 8 = 8^3 = 512$, i tak dalej. Taki system zapisu nazywa się *systemem ósemkowym*, lub *systemem o podstawie 8*, a ,,tradycyjny'' system − *dziesiętnym*. W systemie ósemkowym $k$-ta cyfra od końca, dla $k = 0, 1, 2, \ldots$ ma wagę $8^k$, podczas gdy w systemie dziesiętnym jest to $10^k$.

Podobnie do systemu ósemkowego możemy wprowadzić inne systemy pozycyjne, na przykład piątkowy lub siódemkowy. W systemie piątkowym używa się cyfr $0_5, 1_5, 2_5, 3_5, 4_5$, ostatnia cyfra oznacza jedności, przedostania wielokrotności $5$, a kolejne wielokrotności $5 \cdot 5 = 25$, $5^3 = 125$, i tak dalej. Na przykład $1204_5 = 4 + 2 \cdot 25 + 1 \cdot 125 = 179$.


## System dwójkowy, reprezentacja liczb w komputerze.

<!-- Część o reprezentacji komputerowej przeklejona z kursu programowania. -->

Wśród systemów pozycyjnych szczególne miejsce zajmuje *system dwójkowy*, w którym podstawą systemu jest 2, używa się w nim tylko cyfr 0 i 1, a kolejne pozycje cyfr oznaczają 1, 2, 4, 8, ..., czyli potęgi liczby 2. Na przykład $13 = 8 + 4 + 1 = 2^3 + 2^2 + 2^0$, a zatem $13_{10} = 1101_2$. System dwójkowy jest ,,naturalny'' dla maszyn, jako że cyfry 1 i 0 mogą oznaczać ,,brak sygnału'' i ,,jest sygnał'' (czyli np. ,,prąd nie płynie'' i ,,prąd płynie''). Praktycznie wszystkie komputery, i ogólnie wszystkie maszyny liczące, posługują się systemem dwójkowym.

Pojedyncza cyfra dwójkowa zwana jest *bitem*. Na przykład wspomniana wyżej liczba $13 = 1101_2$ ma 4 bity. Z kolei mając do dyspozycji 8 bitów można zapisać liczby od $0$ do $11111111_2 = 255$. Osiem bitów przyjęło się nazywać *bajtem* (ang. *byte* − z pewnością każdy słyszał tę nazwę!). W tym miejscu możemy powrócić do kwestii typów liczbowych z rozdziału "Wczytywanie, wypisywanie, zmienne": przykładowo typ **int** w języku C++ oznacza liczbę dwójkową zapisywaną na 4 bajtach, czyli 32 bitach. W wersji **unsigned int** przechowuje liczby nieujemne z zakresu $[0, 2^{32}-1]$, w wersji **int** − z zakresu $[-2^{31}, 2^{31}-1]$. (O tym, jak komputery radzą sobie z liczbami ujemnymi, przeczytasz za chwilę).

Operacje +, −, ∗ i / na liczbach całkowitych zapisanych dwójkowo wykonuje się według prostych algorytmów działań pisemnych znanych ze szkoły (czasem trochę przyśpieszonych przez zastosowanie sprytnych pomysłów). Przykładowo, dodawanie 100+86
zapisane dwójkowo wygląda tak (zauważ, że w przypadku dodawania dwóch jedynek powstaje cyfra – tj. bit – przeniesienia):

|   | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | numer bitu                   |
| - | - | - | - | - | - | - | - | - | -                            |
|   | 0 | 1 | 1 | 0 | 0 | 1 | 0 | 0 | ($100=2^6+2^5+2^2$)          |
| + | 0 | 1 | 0 | 1 | 0 | 1 | 1 | 0 | ($86=2^6+2^4+2^2+2^1$)       |
|   | 1 | 0 | 1 | 1 | 1 | 0 | 1 | 0 | ($186=2^7+2^5+2^4+2^3+2^1$)  |

Należy jednak pamiętać, że wynik może być nieokreślony (np. jeśli ktoś spróbuje dzielić przez 0), ale może także wyjść poza zakres (wtedy też jest w pewnym sensie nieokreślony). Gdy w arytmetyce jednobajtowej wykonamy dodawanie 129+129, otrzymamy:

| 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | numer bitu |
| - | - | - | - | - | - | - | - | - | -          |
|   | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | (129)      |
| + | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | (129)      |
| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | (258)      |

czyli wynik wychodzący poza zakres. Objawia się to bitem na pozycji 8 równym 1.

Komputer najczęściej radzi sobie z takimi sytuacjami, po prostu tracąc bity, które nie zmieszczą się w zakresie – czyli wynikiem powyższego działania w typie jednobajtowym byłoby po prostu $10_2 = 2$. Odpowiada to obliczeniu reszty z dzielenia wyniku przez $2^8$, a ogólniej przez $2^k$, gdzie $k$ jest liczbą bitów, które mamy do dyspozycji.

## Reprezentacja liczb ujemnych

Aby móc reprezentować liczby zarówno dodatnie i ujemne, można na przykład umówić się, że jeden z bitów (tradycyjnie: pierwszy od lewej) odpowiada za znak liczby. Gdy bit ten równa się 0, liczba jest nieujemna, gdy równa się 1, liczba jest ujemna. Taki rodzaj reprezentacji nazywa się *znak-moduł*. To rozwiązanie jednak nie pozwala na łatwe operacje arytmetyczne, trzeba bowiem za każdym razem sprawdzać znak obu liczb i postępować dla każdego przypadku inaczej.

Znacznie wygodniejszą i bardziej rozpowszechnioną metodą jest **reprezentacja uzupełnieniowa**: jeśli operujemy na liczbach $k$-bitowych, umawiamy się, że pierwszy bit, zamiast wartości $2^{k-1}$, oznacza $−2^{k-1}$. Tak więc zapis składający się z bitów $b_{k−1}b_{k−2}b_{k−3}\ldots b_3b_2b_1b_0$, reprezentuje liczbę całkowitą

$b_0⋅2^0+b_1⋅2^1+b_2⋅2^2+…+b_{k−2}⋅2^{k−2}-b_{k−1}⋅2^{k−1}$.

Na przykład dla $k=8$ zapis $00001101$ oznacza liczbę $13$, ale liczbę $-13$ musimy w reprezentacji uzupełnieniowej zapisać jako $11110011$, czyli $-256+128+64+32+16+2+1$. Na $k$ bitach w reprezentacji uzupełnieniowej można zapisać liczby z zakresu od $-2^{k−1}$ (zapis: jedynka i same zera) do $2^{k-1}-1$ (zapis: zero i same jedynki). Na przykład w języku C++ dla dla 32-bitowego typu `int` zakresem jest $[−2147483648,2147483647]$, a dla 16-bitowego typu `short` jest to $[−32768,32767]$.

W reprezentacji uzupełnieniowej dodawanie i odejmowanie wykonuje się tak jak dla liczb nieujemnych, tylko zapominamy o ostatnim przeniesieniu. Na przykład dla $k=8$ wykonajmy dodawanie $−64+64$:

|	| -128  |	 64  	| 32  |	 16  |	 8  	| 4  |	 2  |	 1  	| wartość bitu |
| - | - | - | - | - |- | - | - | - | - |
|	| 7 |	 6| 	 5| 	 4| 	 3 |	 2 |	 1 |	 0 	| numer bitu |
|	 |1 |	 1 |	 0 |	 0| 	 0 | 	 0 |	 0 |	 0 	| (-64) |
| +  |	 0 |	 1 |	 0 	| 0 | 	 0 |	 0 |	 0 	| 0 	| (64) |
|	| 0 	| 0 |	 0 |	 0 |	 0 	| 0 |	 0 	 |0 |	 (0) |

Natomiast próba wykonania dodawania −64+(−128) będzie wyglądała następująco:

|	| -128  |	 64  	| 32  |	 16  |	 8  	| 4  |	 2  |	 1  	| wartość bitu |
| - | - | - | - | - |- | - | - | - | - |
|	 |1 |	 1 |	 0 |	 0| 	 0 | 	 0 |	 0 |	 0 	| (-64) |
| +  |	 1 |	 0 |	 0 	| 0 | 	 0 |	 0 |	 0 	| 0 	| (-128) |
| |	 0 |	 1 |	 0 	| 0 | 	 0 |	 0 |	 0 	| 0 	| (64) |

Zauważmy, że w ostatnim przypadku wynik jest błędny. Jest tak dlatego, że faktyczny wynik -192 nie mieści się w 8-bitowej reprezentacji.

## System szesnastkowy

System szesnastkowy ma podstawę 16, a kolejne cyfry powinny oznaczać wielokrotności $1, 16, 16^2, \ldots$. Pojawia się jednak problem z notacją, którego nie miał system piątkowy czy ósemkowy: musimy mieć do dyspozycji 16 różnych cyfr. Na przykład $92 = 5 \cdot 16 + 12$, więc na ostatnim miejscu powinna stać ,,pojedyncza cyfra'' oznaczająca 12. Tradycyjnie używa się więc liter A, B, C, D, E, F na oznaczenie ,,cyfr'' 10, 11, 12, 13, 14, 15. Zatem $92_{10} = 5C_{16}$.

Dlaczego chcemy używać systemu szesnastkowego? Odpowiedź jest w poprzednim rozdziale: ponieważ komputery zapisują *wszystko* w systemie dwójkowym, często operują na bardzo długich ciągach złożonych z cyfr 0 i 1. Dla komputerów jest to naturalne, ale dla ludzi znacznie trudniejsze − co, jeśli pojawi się potrzeba chwilowego zapamiętania lub przepisania np. 20-bitowego ciągu? Można w celu zapamiętania przeliczyć ją na liczbę dziesiętną, ale wtedy nie będziemy mogli łatwo sprawdzić konkretnych jej konkretnych bitów (*Jaka jest trzecia cyfra w dwójkowym zapisie liczby 92?*). System szesnastkowy daje wygodne rozwiązanie: ponieważ $16 = 2^4$, każda cyfra w zapisie szesnastkowym odpowiada dokładnie 4 cyfrom dwójkowym. Cyfra $0_{16}$ to $0000_2$, cyfra $1_{16}$ to $0001_2$, ..., aż do $F = 1111_2$. Zatem liczba $01011010_2$ to $5E_{16}$ (czyli $92$). Taki sposób łączy ze sobą stosunkową łatwość pamiętania, przepisania, czy ,,ręcznej'' analizy ciągu bitów (dużo prościej pamięta się A4EB niż 1010010011101011), a bardzo łatwo w razie potrzeby błyskawicznie zamienić zapis szesnastkowy z powrotem na dwójkowy.

## Zamiana między systemami

Załóżmy, że chcemy przeliczyć liczbę zapisaną w systemie ósemkowym na system dziesiętny. Innymi słowy, dla liczby zapisanej ósemkowo za pomocą cyfr $c_{k-1} c_{k-2} \ldots c_1 c_0$ (gdzie $c_0$ to cyfra jedności, a cyfra $c_{k-1}$ jest najbardziej znacząca) chcemy obliczyć jej wartość. Na potrzeby tego kursu załóżmy, że obliczona wartość mieści się w zakresie typu, którego chcemy użyć (np. `int` w C++). Jak już wiemy, w systemie ósemkowym wartość takiej liczby jest równa:

$c_0 + c_1 \cdot 8 + c_2 \cdot 8^2 + \ldots + c_{k-1} 8^{k-1}$

Najprościej zapisać tę liczbę jako:

$c_0 + 8 \cdot (c_1 + 8 \cdot (c_2 + \ldots + 8 \cdot c_{k-1}))\ldots)$.

Na przykład $1452_8 = 2 + 8 \cdot (5 + 8 \cdot (4 + 8 \cdot 1)) = 810_{10}$. Zauważmy, że jeśli popatrzymy na to ostatnie wyrażenie od prawej do lewej, powstaje ono przez naprzemienne dodawanie kolejnej cyfry $c_i$, po czym mnożenie całości przez $8$. Daje to bardzo prosty algorytm:

```cpp
// Pominiemy wczytywanie danych i inne chwilowo nieistotne fragmenty.

vector<int> C(k);

// Zmienna k to długość liczby ósemkowej .
// Wektor C zawiera kolejne cyfry - C[0] to cyfra jedności, C[1] to cyfra "ósemek", i tak dalej.

int wynik = 0;

for (int i = k - 1; i >= 0; i--) {
    wynik = wynik * 8;
    wynik = wynik + C[k - 1];
}

cout << wynik << "\n";
```

Ten algorytm nazywa się czasem *schematem Hornera* (chociaż należy uważać: ta sama nazwa używana jest też w innych kontekstach). Bez trudu można go zmodyfikować tak, aby przeliczał z systemu piątkowego, siódemkowego lub o innej podstawie $a$: wystarczy wpisać $a$ w miejsce $8$ w powyższym kodzie. Zwróćmy też uwagę na fakt, że w zmiennej `wynik` tak naprawdę znajdują się wartości dla ,,kawałków'' naszej liczby: na przykład wywołany dla liczby $1452_8$ algorytm w pierwszym kroku przypisuje `wynik = 1` (czyli $1_8$) w drugim $1 \cdot 8 + 4 = 12$, czyli $14_8$, w trzecim $12 \cdot 8 + 5 = 101$, czyli $145_8$, w czwartym − $101 \cdot 8 + 2 = 810_{10}$, czyli $1452_8$. Dopisanie kolejnej cyfry $c$ do liczby ósemkowej $s$ to po prostu pomnożenie $s$ przez $8$ i dodanie $c$ − podobnie jak w systemie dziesiętnym dopisanie cyfry $c$ na koniec liczby $s$ to pomnożenie jej przez $10$ i dodanie $c$.

Wykorzystamy podobną obserwację, żeby rozwiązać problemem odwrotny: dana jest liczba dziesiętna $s$, a chcemy wyznaczyć jej zapis ósemkowy. Tak jak w zapisie dziesiętnym ostatnia cyfra jest zawsze resztą liczby z dzielenia przez $10$, tak w zapisie ósemkowym ostatnia cyfra będzie zawsze resztą liczby $s$ z dzielenia przez $8$ (w C++ to po prostu `s%8`). Formalnie, dzieje się tak dlatego, że w zapisie ósemkowym wszystkie pozostałe cyfry oznaczają wielokrotności $8$, $8^2$, $8^3$ itd., a zatem tylko ostatnia cyfra może wpływać na resztą z dzielenia. Weźmy dla przykładu liczbę $s = 791_{10}$ – jej reszta z dzielenia przez $8$ będzie równa $7$, a zatem to będzie ostatnia cyfra w zapisie ósemkowym.

Zauważmy teraz, że wynik dzielenia $s/8$ zaokrąglony w dół (czyli w C++ wynik `s/8`) ma taki sam zapis w zapisie ósemkowym jak $s$, tyle że bez ostatniej cyfry. Znowu, identycznie jest w systemie dziesiętnym: skreślenie z liczby ostatniej cyfry to po prostu podzielenie jej przez $10$ z zaokrągleniem w dół. Zatem po wykonaniu dzielenia `s = s/8` możemy łatwo określić przedostatnią cyfrę, jako że będzie to reszta z dzielenia ,,nowej'' liczby $s$ przez $8$. W naszym przykładzie, dla $s = 791$ po wyznaczeniu ostatniej cyfry ($7$) dzielimy $791$ przez $8$, otrzymując $98$. Reszta z dzielenia $98$ przez $8$ to $2$ − to będzie przedostatnia cyfra. Kolejne cyfry wyznaczamy, powtarzając ten sam schemat tak długo, aż po wyznaczeniu ostatniej cyfry wartość $s$ spadnie do $0$: $98 / 2 = 12$, więc kolejną cyfrą jest reszta z dzielenia $12$ przez $8$, czyli $4$. Wreszcie $12 / 8 = 1$, i to jest pierwsza cyfra liczby $s = 791$ w zapisie ósemkowym, a cały zapis to $1427$.

Podany schemat bardzo łatwo zapisać w postaci pętli. W C++ będzie to wyglądało jak poniżej. Aby poradzić sobie z faktem, że cyfry otrzymujemy od ostatniej do pierwszej, będziemy dodawać je do pomocniczego wektora `L`, który następnie wypiszemy w odwrotnej kolejności.

```cpp
int s;
cin >> s;
// Liczba s jest tą, którą chcemy zamienić na system ósemkowy.

vector<int> L;
// W wektorze L będziemy zapisywać kolejne cyfry wyniku, od ostatniej do pierwszej.

while (s > 0) {
    int c = s % 8; // Wyznaczamy ostatnią cyfrę...
    L.emplace_back(c);
    s = s / 8;     // ... po czym "skreślamy" ją z liczby s.
}

// Jeśli chcemy, możemy teraz wypisać wynik.
int d = int(L.size()); // Długość wektora L to liczba cyfr wyniku, będziemy ją potrzebować za chwilę.

for (int i = d - 1; i >= 0; i--) {
    cout << L[i];
}
cout << "\n";
```

## Zadania

[System dwójkowy :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#dwo){ .md-button .md-button--primary }

[Zamiana między systemami :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#zam){ .md-button .md-button--primary }
