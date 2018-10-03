# LogicalImages [![Build Status](https://www.travis-ci.org/LordLukin/LogicalImages.svg?branch=master)](https://www.travis-ci.org/LordLukin/LogicalImages)

Program do rozwiązywania obrazków logicznych - LogicalImagesSolver 
===================
https://www.wydawnictwologi.pl/obrazki-logiczne
Głównym celem jest wymyślenie algorytmów do rozwiązywania obrazków logicznych. Wykorzystamy w tym celu wiele kombinacji pomniejszych technik na rozwiązywanie obrazków i za pomocą pewnych heurysytk spróbujemy złożyć je w pełny algorytm, który nie jest znany na początku. Jeśli dotrwamy do końca, to będziemy próbowali go także optymalizować. Być może wykorzystamy też jakąś bibliotekę graficzną.

**Input:**
Plik tekstowy w formacie JSON reprezentujący dane wejściowe, np.

```
{
  "rowNumber": 3,
  "colNumber": 3,
  "rows": [
    [1, 1],
    [2],
    [1, 1]
  ],
  "cols": [
    [1, 1],
    [1],
    [2]
  ]
}
```

Reprezentuje on taką planszę:

```
    +------+
    | 1    |
    | 1 1 2|
+---+------+
|1 1|??????|
|  2|??????|
|1 1|??????|
+---+------+
```

**Output:**
Plik tekstowy z narysowaną rozwiązaną planszą za pomocą znaków ASCII:

```
    +------+
    | 1    |
    | 1 1 2|
+---+------+
|1 1|■■  ■■|
|  2|  ■■■■|
|1 1|■■    |
+---+------+
```

**Założenia:**
3 wartości pola - UNKNOWN, BLACK, WHITE z ich odpowiednikami w formie znaków ASCII, wartości konfigurowalne w pliku tekstowym.
Maksymalna liczba podana w wierszu lub kolumnie: 99

**Wymagania obowiązkowe**, które muszą być spełnione w takiej właśnie kolejności:

1. Przetwarzanie pliku wejściowego i parsowanie go do odpowiedniej struktury danych
2. Wyświetlanie pustej planszy w formacie ASCII na ekranie
3. Zapisywanie planszy w formacie ASCII do pliku
4. Rozwiązywanie obrazków o wielkości planszy 3x3 (w TDD przetestowane wszystkie możliwe przypadki)
5. Rozwiązywanie obrazków o wielkości planszy 4x3 (w TDD przetestowane wszystkie możliwe przypadki)
6. Rozwiązywanie obrazków o wielkości planszy 3x4 (w TDD przetestowane wszystkie możliwe przypadki)
7. Rozwiązywanie obrazków o wielkości planszy 4x4 (w TDD przetestowane wszystkie możliwe przypadki)
8. Wizualizacja rozwiązywania obrazków krok po kroku na ekranie

**Wymagania dodatkowe**, kolejność również istotna. Weryfikacja przynajmniej za pomocą [próbek](https://www.wydawnictwologi.pl/pliki/probkaOL.pdf):

1. Rozwiązywanie przykładów o stopniu trudności 1 (wg skali wydawnictwa Logi, do zweryfikowania z kilkoma przykładami takich obrazków)
2. Rozwiązywanie przykładów o stopniu trudności 2 (wg skali wydawnictwa Logi, do zweryfikowania z kilkoma przykładami takich obrazków)
3. Rozwiązywanie przykładów o stopniu trudności 3 (wg skali wydawnictwa Logi, do zweryfikowania z kilkoma przykładami takich obrazków)
4. Rozwiązywanie przykładów o stopniu trudności 4 (wg skali wydawnictwa Logi, do zweryfikowania z kilkoma przykładami takich obrazków - tutaj zacznie się ciekawa praca algorytmiczna)
5. Rozwiązywanie przykładów o stopniu trudności 5 (wg skali wydawnictwa Logi, do zweryfikowania z kilkoma przykładami takich obrazków)

**Wymaganie dodatkowe**, do spełnienia w dowolnej kolejności po spełnieniu wszystkich wymagań obowiązkowych:

6. Wizualizacja rozwiązywania obrazków krok po kroku z wykorzystaniem biblioteki graficznej (Qt lub OpenCV)
7. Wczytywanie obrazków w formie graficznej oprócz formy tekstowej - ze zdjęcia lub ze skanu i przetwarzania ich do formatu JSON (może to być oddzielna binarka)
8. Optymalizacja algorytmów pod kątem czasu rozwiązywania obrazków

