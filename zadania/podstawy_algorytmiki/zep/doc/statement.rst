.. pdfinfo::
  :place: Kraków
  :date: 28 marca 2023
  :contest_name: Algorytmika V LO 1e
  :contest_date: rok szkolny 2022/23
  :leftlogo: vlo.png
  :rightlogo: tcs.pdf
  
Naczelny Statystyk kontratakuje
=====================================================

W Bajtocji dobiegł właśnie końca kolejny rok podatkowy. Zeznania podatkowe obywateli leżą
przed Tobą, jeszcze bez żadnego porządku. Nowy rząd chce od Ciebie odpowiedzi na zupełnie inne pytanie: zapytany o pewną grupę Bajtocjan tworzącą spójny przedział 
(czyli od :math:`a`-tego do :math:`b`-tego Bajtocjanina, dla pewnych :math:`a` i :math:`b`) powiedz, ile wynosi ich łączny zysk.


Wejście
-------
W pierwszej linii znajduje się liczba całkowita :math:`n` (:math:`1 \le n \le 10^6`) oznaczajaca liczbę zeznań podatkowych. 
W drugiej linii znajduje się :math:`n` liczb całkowitych dodatnich o wartości nie przekraczającej :math:`10^9` oddzielonych spacjami -- są zyski kolejnych Bajtocjan.
W trzeciej linii znajduje się liczba całkowita :math:`q` (:math:`1 \le q \le 10^6`) oznaczająca liczbę zapytań. Kolejnych :math:`q` linii zawiera po dwie liczby 
całkowite :math:`a`, :math:`b` (:math:`1 \leq a \leq b \leq n`).

Wyjście
-------
Dla każdego zestawu danych wypisz q linii zawierających odpowiedzi na zadane pytania.
Odpowiedzią jest łączny zysk Bajtocjan od :math:`a`-tego do :math:`b`-tego włącznie.

Przykład
--------
.. list-table::
 :header-rows: 1

 * - Dla danych wejściowych:
   - Poprawną odpowiedzią jest:
 * - ::

       5
       3 1 4 2 3
       3
       1 4
       3 3
       3 5

   - ::

       10
       4
       9
       
