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

## Odległości

W algorytmie BFS mogliśmy przypisywać wierzchołkom odległości od wierzchołka
początkowego, gdy przechodziliśmy krawędzią. Niestety, gdybyśmy spróbowali zrobić
coś podobnego w algorytmie DFS, to otrzymane liczby nie byłyby prawdziwymi
odległościami od wierzchołka początkowego – wynika to z faktu, że DFS znajduje
*jakąś* ścieżkę do wierzchołka, a nie tę najkrótszą, tak jak to było w przypadku
BFS.

Warto jednak wspomnieć, że DFS nadawałby się do obliczania odległości, gdyby nasz graf nie posiadał 
cykli, czyli był drzewem. Jest tak dlatego, że w drzewie istnieje dokładnie
jedna ścieżka między każdymi dwoma wierzchołkami – zatem ta *jakaś* ścieżka
znaleziona przez DFS będzie automatycznie tą najkrótszą.

## Co wybrać, BFS czy DFS?

Algorytm BFS wydaje się robić dokładnie to samo co DFS, a do tego potrafi też
policzyć odległości w grafie. Patrząc tylko na to, może wydawać się, że nie warto
się uczyć o DFS, bo zawsze można użyć BFS. Jednak mimo to, większość
programistów wybiera DFS, gdy może użyć dowolnego z tych dwóch
algorytmów. Wynika to z wyjątkowej prostoty implementacji DFS.

W przyszłych lekcjach tego kursu poznamy też unikatowe własności DFS, które
pozwolą nam rozwiązywać problemy, przy których BFS by sobie nie poradził.

## Zadania

<!--

TODO: zadanie ze zliczaniem spójnych składowych grafu?

TODO: zadanie z wielokrotnym sprawdzaniem, czy dwa wierzchołki są w tej samej
spójnej składowej?

-->

[Gildie :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/problemset/problem/Oys6jiVOIap59lYCHRwDMbNT/site/?key=statement){ .md-button .md-button--primary } <!-- TODO: dodać na konkurs -->

!!! note "Stos zamiast kolejki"

    Co ciekawe, istnieje alternatywna metoda implementacji algorytmu DFS, która
    nie używa rekurencji. Wygląda ona tak samo jak implementacja BFS, tylko że
    zamiast kolejki używa się stosu.

    Takiej implementacji jednak rzadko się używa, ponieważ tracimy prostotę
    implementacji. Jej atutem jest jednak to, że zużywa mniej pamięci niż wersja
    rekurencyjna, w której wywołania funkcji potrafią zająć dużo pamięci stosu.
