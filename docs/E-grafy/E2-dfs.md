# Przeszukiwanie w głąb

Poznaliśmy już algorytm BFS, a teraz poznamy alternatywny sposób przeszukiwania
grafu, który ze względu na swoją prostotę implementacji jest używany dużo
częściej. Jest to metoda przeszukiwania w głąb (ang. Depth First Search – DFS).

## Algorytm

Główny pomysł tego algorytmu polega na podążaniu jedną ścieżką tak daleko, jak to
możliwe i zawracanie się, gdy trafimy do wierzchołka, z którego nie możemy przejść
dalej do żadnego innego nieodwiedzonego sąsiada.

Popatrzmy na poniższą implementację:

```cpp
vector<int> odwiedzony;
vector<vector<int>> sasiedzi;

void dfs(int v) {
    odwiedzony[v] = true;
    for (int u : sasiedzi[v])
        if (!odwiedzony[u])
            dfs(u);
}
```

I jak zadziała na poniższym grafie:

![Przykład](../assets/dfs1-light.gif#only-light){ loading=lazy width="500" }
![Przykład](../assets/dfs1-dark.gif#only-dark){ loading=lazy width="500" class="no-invert" }

Zauważmy, że całą robotę wykonuje za nas rekurencja. Kiedy wchodzimy do
wierzchołka, od razu idziemy do jego sąsiada, a w momencie, gdy będziemy
wracać, automatycznie wybierzemy następnego nieodwiedzonego sąsiada. Gdy już
takich nie ma, wracamy z wywołania rekurencyjnego.

### Odległości

W algorytmie BFS mogliśmy przypisywać wierzchołkom odległości od wierzchołka
początkowego, gdy przechodziliśmy krawędzią. Niestety, gdybyśmy spróbowali zrobić
coś podobnego w algorytmie DFS, to otrzymane liczby nie byłyby prawdziwymi
odległościami od wierzchołka początkowego. Wynika to z faktu, że DFS do każdego wierzchołka dochodzi pierwszą znalezioną ścieżką, nie starając się, aby była to najkrótsza ścieżka -- tak jak robiłby to BFS.

Warto jednak wspomnieć, że DFS nadawałby się do obliczania odległości, gdyby nasz graf nie posiadał
cykli, czyli był drzewem. Jest tak dlatego, że w drzewie istnieje dokładnie
jedna ścieżka między każdymi dwoma wierzchołkami – zatem "pierwsza możliwa" ścieżka
znaleziona przez DFS będzie automatycznie tą najkrótszą.

### Co wybrać, BFS czy DFS?

Algorytm BFS wydaje się robić dokładnie to samo co DFS, a do tego potrafi też
policzyć odległości w grafie. Patrząc tylko na to, może wydawać się, że nie warto
się uczyć o DFS, bo zawsze można użyć BFS. Jednak mimo to, większość
programistów wybiera DFS, gdy może użyć dowolnego z tych dwóch
algorytmów. Wynika to z wyjątkowej prostoty implementacji DFS.

W przyszłych lekcjach tego kursu poznamy też unikatowe własności DFS, które
pozwolą nam rozwiązywać problemy, przy których BFS by sobie nie poradził.

!!! note "Stos zamiast kolejki"

    Co ciekawe, istnieje alternatywna metoda implementacji algorytmu DFS, która
    nie używa rekurencji. Wygląda ona tak samo jak implementacja BFS, tylko że
    zamiast kolejki używa się stosu.

    Takiej implementacji jednak rzadko się używa, ponieważ tracimy prostotę
    implementacji. Jej atutem jest jednak to, że zużywa mniej pamięci niż wersja
    rekurencyjna, w której wywołania funkcji potrafią zająć dużo pamięci stosu.

### Zadania

<!--

TODO: zadanie ze zliczaniem spójnych składowych grafu?

TODO: zadanie z wielokrotnym sprawdzaniem, czy dwa wierzchołki są w tej samej
spójnej składowej?

-->

[Gildie :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/Oys6jiVOIap59lYCHRwDMbNT/site/?key=statement){ .md-button .md-button--primary } <!-- TODO: dodać na konkurs -->

## Znajdowanie cykli w grafie skierowanym

Przejdźmy teraz do przypadku grafu skierowanego. Jednym z podstawowych pytań,
jakie możemy sobie zadać jest to, czy w danym grafie istnieje cykl (podążający
zgodnie ze skierowaniem krawędzi).

Aby rozwiązać to zadanie użyjemy algorytmu DFS. Kluczową właściwością okazuje
się tu fakt, że algorytm ten stara się iść "najgłębiej jak się da", a do danego
wierzchołka wraca się dopiero, gdy *wszystkie* wierzchołki osiągalne z niego
zostaną już odwiedzone.

Zauważmy, że pytanie "czy w grafie istnieje cykl" można inaczej powiedzieć jako
"czy w grafie jest wierzchołek osiągalny z niego samego". Taka cecha odpowiada
sytuacji, w której algorytm DFS napotyka ten wierzchołek drugi raz, ale zanim
pierwsze wywołanie rekurencyjne się skończyło. Widać to na poniższej animacji, w
której wierzchołki do których weszliśmy (ale nie wyszliśmy) są zaznaczone na
czerwono, a te z których wyszliśmy na niebiesko.

![Przykład](../assets/dfs2-light.gif#only-light){ loading=lazy width="500" }
![Przykład](../assets/dfs2-dark.gif#only-dark){ loading=lazy width="500" class="no-invert" }

Implementacja takiego podejścia mogłaby wyglądać tak:

```cpp
vector<int> kolor; // 0 - nieodwiedzony, 1 - czerwony, 2 - niebieski
vector<vector<int>> sasiedzi;
bool czy_cykl = false;

void dfs(int v) {
    kolor[v] = 1;
    for (int u : sasiedzi[v]) {
        if (odwiedzony[u] == 0)
            dfs(u);
        else if (odwiedzony[u] == 1)
            czy_cykl = true;
    }
}
```
