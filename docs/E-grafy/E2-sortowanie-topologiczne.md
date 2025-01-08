# Sortowanie topologiczne

## Kolejność w skierowanym grafie acyklicznym

Grafy skierowane, w których nie ma żadnych cykli (czyli ścieżek z pewnego
wierzchołka do niego samego) nazywa się *acyklicznymi* (ang. Directed Acyclic
Graph).

W takich grafach możemy przypisać wierzchołkom numery tak, aby krawędzie
przechodziły tylko od wierzchołka o niższym numerze do wierzchołka o
wyższym. Taką kolejność nazywamy *posortowaniem topologicznym* wierzchołków.
To, że zawsze jest to możliwe, najłatwiej pokazać konstruując algorytm, który
będzie je znajdować. Zaraz to zrobimy, ale najpierw zróbmy pewne spostrzeżenie.

Fakt:
*W każdym acyklicznym grafie skierowanym istnieje wierzchołek o stopniu
wejściowym zero.*  
Dowód:  
Załóżmy przeciwnie, czyli że każdy wierzchołek ma jakiegoś poprzednika. Weźmy
dowolny wierzchołek $v_0$. Ma on pewnego poprzednika $v_1$, który z kolei ma
swojego poprzednika $v_2$, i tak dalej, aż do $v_n$ (a nawet w nieskończoność,
ale nam wystarczy tyle). Mamy zatem ścieżkę
$v_n \rightarrow v_{n-1} \rightarrow \ldots \rightarrow v_1 \rightarrow v_0$
złożoną z $n+1$ wierzchołków, ale w naszym grafie jest tylko $n$ różnych
wierzchołków! Oznacza to, że któryś z nich się powtarza na tej ścieżce, czyli
wyszło nam, że mamy cykl w grafie, ale nasz graf wcale nie ma żadnych
cykli! Zatem to nasze założenie, że każdy wierzchołek ma pewnego
poprzednika, było błędne. Prawdą natomiast jest, że musi istnieć co najmniej jeden
wierzchołek o stopniu wejściowym zero.

## Algorytm iteracyjny

Algorytm iteracyjny będzie budować listę wierzchołków w kolejności topologicznej
i opierać się na następującej obserwacji:

- Jeżeli któryś wierzchołek nie ma poprzedników, to może znajdować się na
początku listy (czyli być pierwszym w kolejności topologicznej)

Oprócz tego zauważmy, że taki wierzchołek nie będzie miał wpływu na kolejność
pozostałych wierzchołków między sobą. W takim razie po umieszczeniu go na
początku listy możemy go usunąć z grafu. Zostajemy więc z nowym grafem, na
którym możemy powtórzyć nasze podejście (zauważmy jednak, że "początek" dla
następnego wierzchołka będzie *po* aktualnie umieszczonym wierzchołku).

### Implementacja

Jak szybki może być taki algorytm? Wykona on $n$ iteracji, w każdej musi wziąć
dowolny wierzchołek o stopniu wejściowym zero, nazwijmy go `v`, a następnie
usunąć go z grafu. Stopnie wejściowe wszystkich wierzchołków możemy pamiętać w
tablicy, więc naiwne szukanie zajęłoby nam czas $O(n)$.

Jak zaimplementować usuwanie z grafu? Tablicą `nastepnicy[v]` nie musimy się
przejmować, bo liczymy na to, że nigdy już nie potraktujemy `v` jako istniejący
wierzchołek, więc nie powinniśmy się do niej odwoływać. Drugą rzeczą, na którą
`v` ma wpływ, są stopnie wejściowe jego następników, a więc trzeba je wszystkie
pomniejszyć o 1.

Takie podejście mogłoby wyglądać następująco:

```cpp
vector<int> lista;
for (int i = 0; i < n; i++) {
  // Szukamy wierzchołka do usunięcia
  int v;
  for (int u = 0; u < n; u++) {
    if (stopien_wejściowy[u] == 0 && !usuniety[u]) {
      v = u;
      break;
    }
  }

  // Dodajemy v do listy za wierzchołkami, które już zostały dodane, ale przed
  // wierzchołkami, które zostaną dodane w późniejszych iteracjach
  lista.push_back(v);

  usuniety[v] = true;
  // Zmniejszamy stopnie następników
  for (int u : nastepnicy[v])
    stopien_wejsciowy[u]--;
}
```

Szukanie wierzchołków zajmie nam sumarycznie $O(n^2)$ operacji. Zmniejszanie
stopni wykona dokładnie jedną operację dla każdej krawędzi w naszym grafie, więc
sumarycznie zajmie czas $O(m)$. Niestety ten liniowy czynnik jest dominowany
przez pierwszy krok, więc finalna złożoność wynosi $O(n^2)$.

### Optymalizacja szukania wierzchołka do usunięcia

Jak zauważyliśmy, szukanie wierzchołka o stopniu wejściowym zero jest wąskim
gardłem w algorytmie. Czy możemy przyspieszyć ten krok?

Wyobraźmy sobie, że w kolejnych krokach algorytmu mamy worek, w którym znajdują
się wszystkie wierzchołki o stopniu zero. Wtedy jedna iteracja algorytmu
sprowadzałaby się do:

- Wyjmij dowolny wierzchołek `v` z worka i usuń go z grafu.
- Zaktualizuj worek.

Aktualizacja worka będzie polegać na dodaniu do niego wierzchołków, których
stopień wejściowy spadł do zera podczas usuwania `v` z grafu. Zatem wystarczy
sprawdzić jedynie następników `v`, jako że stopień pozostałych wierzchołków się
nie zmienił!

Daje nam to istotne przyspieszenie, jako że sumarycznie podczas aktualizacji
worka we wszystkich iteracjach rozpatrzymy każdą krawędź grafu dokładnie raz,
więc zajmie to czas $O(m)$. Włączając jeszcze koszt początkowej budowy worka i
iteracji algorytmu, dostaniemy czas $O(n+m)$.

Naszym „workiem” może być jakakolwiek kontener C++, który udostępnia szybkie
dodawanie i usuwanie elementów, na przykład kolejka, stos albo wektor.

Pełna implementacja tego algorytmu może wyglądać następująco:

```cpp
vector<int> nastepnicy[n];
int stopien_wejsciowy[n];

vector<int> sortuj() {
  // worek będzie trzymał wszystkie wierzchołki o stopniu wejściowym 0
  stack<int> worek;

  for (int v = 0; v < n; v++)
    if (stopien_wejsciowy[v] == 0)
      worek.push(v);

  vector<int> lista;

  while (!worek.empty()) {
    // Bierzemy dowolny wierzchołek stopnia 0
    int v = worek.top();
    worek.pop();

    // Dodajemy v do listy za wierzchołkami, które już zostały dodane, ale przed
    // wierzchołkami, które zostaną dodane w późniejszych iteracjach
    lista.push_back(v);

    // Usuwamy v z grafu
    for (int u : nastepnicy[v]) {
      stopien_wejsciowy[u]--;
      // Jeżeli stopień spadł do 0, to dodajemy do worka
      if (stopien_wejsciowy[u] == 0)
        worek.push(u);
    }
  }

  return lista;
}
```

Zniknęła nam tablica `usuniety`, ponieważ w worku mamy jedynie nieusunięte
wierzchołki.

## Algorytm rekurencyjny

Będziemy budować listę posortowanych wierzchołków rekurencyjnie. Przypomnijmy,
że aby kolejność wierzchołków spełniała warunek posortowania, wszyscy następnicy
każdego wierzchołka muszą być po nim na liście. My jednak, aby ułatwić
implementację, zrobimy odwrotnie i wszyscy następnicy wierzchołka będą *przed*
nim. Aby otrzymać wynik zgodny z definicją podaną wcześniej, wystarczy taką
listę odwrócić (choć nie zawsze jest to konieczne i czasami wygodniej pracować w
takiej formie).

Zaimplementujmy więc funkcję `dfs(v)`, której wywołanie będzie gwarantować, że
na naszej liście znajdzie się wierzchołek `v` i wszystkie wierzchołki
topologicznie od niego większe (i będą one w dobrej kolejności).

```cpp
vector<int> nastepnicy[n];
bool odwiedzony[n];
vector<int> lista;

// Po wywołaniu dfs(v), v będzie się znajdować na liście
int dfs(int v) {
  if (odwiedzony[v])
    // v już jest na liście, nic nie trzeba robić
    return;

  odwiedzony[v] = true;

  // Upewniamy się, że wszyscy następnicy są na liście
  for (int u : nastepnicy[v])
    dfs(u);

  // Teraz możemy dodać na koniec v
  lista.push_back(v);
}
```

Aby nasza lista była kompletna, możemy użyć założenia o funkcję `dfs` i
zagwarantować, że każdy wierzchołek się na niej znajdzie:

```cpp
for (int v = 0; v < n; v++)
  dfs(v);
```
