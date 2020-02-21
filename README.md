# Algorytmy sortowania

W pliku `main.c` znajduje się początkowy kod z zaznaczonymi liniami `TODO`
wymagającymi stworzenia implementacji. Można oczywiście napisać dowolny
dodatkowy kod (nowe funkcje), ale należy zachować ogólny szablon pliku.

Do skompilowania projektu można użyć pliku `Makefile`. Przy jego użyciu,
komenda `make` wygeneruje dwa pliki wykonywalne (jeśli nie będzie błędów
kompilacji): `debug` i `release`. Pierwszy z nich zawiera wszystkie symbole
wymagane do debugowania i przyda się podczas tworzenia aplikacji. Drugiego
pliku wykonwalnego należy użyć aby dokonać pomiarów czasu działania.

# Krótkie omówienie kodu

- Tablica `fill_functions` zawiera wskaźniki na funkcje generujące zbiory
  danych
- Tablica `check_functions` zawiera wskaźniki na funkcje sprawdzające rozkład
  danych
- Tablica `sort_functions` zawiera wskaźniki na funkcje zawierające
  implementacje algorytmów sortujących
- W funkcji `main()` zawarte są zagnieżdżone pętle, które:
  - dla każdego algorytmu sortowania:
    - dla każdego generatora danych:
      - dla każdego `n` (wielkość instancji):
        - generują tablicę liczb całkowitych
        - sprawdzają czy jest ona zgodna z oczekiwaniami
        - sortują dane
        - mierzą czas tej operacji
        - sprawdzają czy dane są posortowane

# Zadania

- [1 pkt] Zaimplementuj funkcję `fill_increasing`, tak aby spełniała wymagania funkcji
  `is_increasing` (każdy kolejny element jest większy niż poprzedni)
- [1 pkt] Zaimplementuj funkcję `fill_decreasing`, tak aby spełniała wymagania
  funkcji `is_decreasing` (każdy kolejny element jest mniejszy niż poprzedni)
- [1 pkt] Zaimplementuj funkcję `fill_vshape`, tak aby spełniała wymagania
  funkcji `is_vshape` (dane w tablicy ułożone w kształt litery `V` tzn.
  największy element wejściowy jest na pierwszej pozycji, a drugi największy
  element na pozycji ostatniej, itd.)
- [2 pkt] Zaimplementuj funkcję `selection_sort` aby sortowała dane w tablicy
  zgodnie z algorytmem Selection Sort
- [2 pkt] Zaimplementuj funkcję `insertion_sort` aby sortowała dane w tablicy
  zgodnie z algorytmem Insertion Sort
- [2 pkt] Zaimplementuj funkcję `quick_sort` aby sortowała dane w tablicy
  zgodnie z algorytmem Quick Sort
- [2 pkt] Zaimplementuj funkcję `heap_sort` aby sortowała dane w tablicy
  zgodnie z algorytmem Heap Sort
- Ustaw wartość globalnej tablicy `ns`, aby odpowiednio przygotować wykresy do
  raportu
