# Przeszukiwanie w głąb

Poznaliśmy już algorytm BFS, a teraz poznamy alternatywny sposób przeszukiwania
grafu, który ze względu na swoją prostotę implementacji jest używany dużo
częściej. Jest to metoda przeszukiwania w głąb (Depth First Search).

## Algorytm

Główny pomysł tego algorytmu polega na podążaniu jedną ścieżką tak daleko jak to
możliwe i zawracanie się gdy trafimy do wierzchołka z którego nie możemy przejść
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

Zauważmy, że całą robotę wykonuje za nas rekurencja. Gdy wchodzimy do
wierzchołka, od razu idziemy do jego sąsiada, a w momencie gdy będziemy się
wracać, automatycznie wybierzemy następnego nieodwiedzonego sąsiada. A gdy już
takich nie ma, to wracamy z wywołania rekurencyjnego.

## Odległości

W algorytmie BFS mogliśmy przypisywać wierzchołkom odległości od wierzchołka
początkowego gdy przechodziliśmy krawędzią. Niestety gdybyśmy spróbowali zrobić
coś podobnego w algorytmie DFS, to otrzymane liczby nie byłyby prawdziwymi
odległościami od wierzchołka początkowego – wynika to z faktu, że DFS znajduje
*jakąś* ścieżkę do wierzchołka, a nie tę najkrótszą, tak jak to było w przypadku
BFS. Możemy się o tym przekonać na poniższym przykładzie:

TODO: Przykład

Warto jednak wspomnieć, że zadziałałoby jeżeli nasz graf nie posiadał cykli,
czyli był drzewem. Jest tak dlatego, że w drzewie istnieje dokładnie jedna
ścieżka między każdymi dwoma wierzchołkami – zatem ta *jakaś* ścieżka znaleziona
przez DFS będzie automatycznie tą najkrótszą.

## Co wybrać, BFS czy DFS?

Algorytm BFS wydaje się robić dokładnie to samo co DFS, a do tego potrafi też
policzyć odległości w grafie. Patrząc tylko na to, może wydawać się że nie warto
się uczyć o DFS, bo zawsze można użyć BFS. Jednak mimo to, większość
programistów wybiera DFS gdy może użyć dowolnego z nich. Wynika to z wyjątkowej
prostoty implementacji tego algorytmu.

W przyszłych lekcjach tego kursu poznamy też unikatowe własności DFS, które
pozwolą nam rozwiązywać problemy, przy których BFS by sobie nie poradził.

## Zadania

TODO: zadanie ze zliczaniem spónych składowych grafu?

TODO: zadanie z wielokrotnym sprawdzaniem czy dwa wierzchołki są w tej samej
spójnej składowej?

TODO: czy zadania z szachownicą w tym dziale? może w oddzielnym?

TODO: zadania z odzyskiwaniem ścieżki
