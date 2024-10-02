# Wstęp

W tej lekcji napiszemy i uruchomimy nasz pierwszy program komputerowy.
W tym celu wykonamy następujące kroki:

1. Zainstalujemy oprogramowanie potrzebne do napisania i uruchomienia naszego programu.
2. Napiszemy i uruchomimy pierwszy program wykonujący obliczenia.

Zaczynajmy!


# Środowisko programistyczne C++

Żeby stworzyć program w C++, potrzebujemy wykonać następujące kroki:

1. Najpierw musimy napisać kod źródłowy programu w języku C++.
2. Mając już kod źródłowy, można go *skompilować*, czyli sprowadzić go do pliku wykonywalnego (na systemie Windows taki plik ma rozszerzenie `.exe`).
3. Plik wykonywalny można już po prostu wywołać.
Programy, które będziemy tworzyć w tym kursie, po uruchomieniu otworzą konsolę.
W takiej konsoli można programowi podać dane, po czym program się wykona i wypisze obliczone dane.

Żebyśmy mogli napisać sami kod źródłowy, teoretycznie "wystarczy" najzwyklejszy notatnik na komputerze, a do skompilowania "wystarczy" pobrać i użyć kompilatora do języka C++.
Jak się niedługo okaże, kody źródłowe programów bywają na tyle skomplikowane, że lepiej jest skorzystać ze *środowiska programistycznego*.
Takie środowisko zazwyczaj jest edytorem tekstu, który pomaga pisać kody źródłowe, oraz umożliwia łatwe kompilowanie i uruchamianie programu.

Istnieje wiele środowisk programistycznych, a żeby ułatwić wybór, pokażemy jak zainstalować dwa konkretne, zależnie od preferencji:

- Visual Studio Code - na tę chwilę najpopularniejsze środowisko programistyczne, które wspiera wiele języków programowania, w tym C++ oraz Python.
- Geany - bardzo lekki edytor tekstu z minimalnym interfejsem do skompilowania i uruchamiania kodu.

# Krok 1: Instalacja WSL oraz g++

Na tę chwilę, najłatwiej jest zainstalować kompilator C++ na systemach Windows poprzez *Windows Subsystem for Linux (WSL)*.
To tak naprawdę sposób uruchomienia *Linux*a, w którym łatwo się instaluje narzędzia dla programistów (z tego też powodu wiele zaawansowanych programistów korzysta z Linuxa zamiast Windowsa).

Alternatywnie, można zainstalować kompilator MinGW do C++, ale wymaga to więcej kroków instalacyjnych.

<style>
iframe {
width: 100%;
aspect-ratio: 16 / 9;
}
</style>

<iframe src="https://www.youtube.com/embed/euA_T1Ll6ZM?si=hUyOGDeo274rVrLi" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

<iframe src="https://www.youtube.com/embed/ArDf2yqbVaw?si=R2TzQUWXvhL2V4Hc" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Krok 2a: Instalacja Visual Studio Code

<iframe src="https://www.youtube.com/embed/maE3cigf1uA?si=Mva2LzQ4yROK3BlB" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Krok 2b: Instalacja Geany

Instalator `geany-2.0_setup.exe` można pobrać ze strony [geany.org](https://www.geany.org/download/releases/).
Kroki instalacyjne są prostsze, niż te dla Visual Studio Code.

<iframe src="https://www.youtube.com/embed/SnsaP3msEBQ?si=EcmGdGHOrwR6CZm_" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Krok 3: Napisanie programu

Pod koniec filmików do instalacji środowisk graficznych pojawił się program, który wypisuje do konsoli napis [Hello world!](https://pl.wikipedia.org/wiki/Hello_world).
Większość naszych programów będzie miała właśnie taką formę:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // <tutaj kod programu>
}
```

Pojawia się tutaj kilka "magicznych linijek", które na razie będziemy przepisywać do każdego programu bez większego zastanowienia się.
Nie jest to "najlepsza praktyka" programistyczna, ale pozwoli nam to sprawniej przejść do nauki programowania oraz rozwiązywania zadań.

Linijka `#include <bits/stdc++.h>` umożliwia skorzystanie z wszystkich dostępnych bibliotek C++ (w przypadku zainstalowania kompilatora bezpośrednio na Windowsie, bez WSL, ta opcja nie jest dostępna i trzeba zadeklarować się jakich bibliotek chcemy użyć, na przykład `#include <iostream>`).
Linijka `cin.tie(0)->sync_with_stdio(0);` przyśpiesza operacje wejścia-wyjścia, co jest potrzebne do wysyłania zadań na systemie (pierwsze zadanie jest na dole strony).
Nie wchodzimy w szczegóły działania tych linijek.

Spróbujmy coś wypisać!
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cout << "100 stopni w skali Celsjusza to " << 100 * 9 / 5 + 32 << " w skali Fahrenheita\n";
}
```
Po skompilowaniu i uruchomieniu tego programu, w konsoli pojawi się taki napis:
```
100 stopni w skali Celsjusza to 212 w skali Fahrenheita
```

`"100 stopni w skali Celsjusza to "` to _napis_, który w C++ zapisuje się cudzysłowach (`""`).
Napisy, jak i inne wartości (np. wyrażenie `100 * 9 / 5 + 32`), można wypisywać używając składni `cout << wartość`, gdzie `wartość` to rzecz, którą chcemy wypisać.
Natomiast fragment `\n` występujący na końcu napisu `" w skali Fahrenheita\n"` to tzw. znak końca linii, który sprawia, że wyświetla się nowa linijka w jego miejscu.

## Zadania i system Szkopuł

Na końcu każdej lekcji kursu mamy dla Ciebie zadania do samodzielnego rozwiązania. Będą powiązane z treściami lekcji, na początku będą bardzo proste
Rozwiązaniem każdego z zadań jest program (a dokładniej: kod źródłowy), który powinieneś zgłosić w serwisie [Szkopuł](https://szkopul.edu.pl/).
Programy są oceniane w pełni automatycznie. **Zacznij zatem od założenia konta w tym systemie**.

Aby program został zaakceptowany w systemie, wynik działania programu powinien być idealnie zgodny z wymaganiami z treści zadania.
Jeśli Twój program nie zadziała za pierwszym razem – nie przejmuj się, możesz przesłać jego poprawioną wersję jeszcze raz! Jeśli chcesz uniknąć ciągłego wysyłania, najpierw sprawdź poprawność kompilacji i działania programu na swoim komputerze.

### Zadanie 1. Początek

To jest Twoje pierwsze zadanie do samodzielnego rozwiązania.
Napisz program, który wypisze następujący komunikat (trzy wiersze):

````
Mount Everest - 8850 m n.p.m.
McKinley - 6194 m n.p.m.
Mont Blanc - 4810 m n.p.m.
````

Pamiętaj, że aby twój program został zaakceptowany w systemie, należy wypisać **dokładnie** ten sam tekst co powyżej - bez żadnych dodatkowych znaków (w tym spacji). Nasza automatyczna sprawdzarka jest bardzo rygorystyczna i niezbyt domyślna. Napiszemy o niej więcej w lekcji "Technikalia, pierwsze zadania", na razie musisz

#### Wyjście

Twój program powinien wypisać dokładnie podany wyżej komunikat.

Kiedy Twój program będzie gotowy, zaloguj się na swoje konto w systemie Szkopuł, wybierz konkurs "Kurs OI", a następnie "Wyślij" i z listy zadań wybierz "Początek". Możesz też od razu (będąc zalogowanym w systemie Szkopuł) kliknąć w poniższy link:

[Sprawdź kod na Szkopule :fontawesome-solid-paper-plane:](https://szkopul.edu.pl/c/kurs-oi/p/#poc){ .md-button .md-button--primary }
