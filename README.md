# STMSnake
STMSnake repository

Implementacja gry Snake na mikrokontrolerze STM32F4 z wykorzystaniem wyświetlacza LCD Nokii 3310 (84 x 48).


Wykorzystane gotowe biblioteki:
-sterownik wyświetlacza:
 +źródło: http://stm32f4-discovery.com
 +obsługa wymiany danych z wyświetlaczem
 +rysowanie punktów, linii, prostokątów, okręgów
 +ustawienie kursora i wyświetlanie znaków 5x7 oraz 3x5
 +zmiana konstrastu obrazu

Własne bibliteki rozszerzające funkcjonalność:
-snkakelib (grafika)
 +wyświetlanie wypełnionych i pustych w środku prostokątów (o stałej wielkości) 'na siatce'
 +rysowanie bitmap z gotowej tablicy 
 +rysowanie węża na podstawie tablicy

 +ramka gry
 +czyszczenie okna wewnątrz ramki
 +i inne mniejszcze dodatki

-snake_engine (najważniejsze elementy gry)
 +struktury:
  +Coordinate	(współrzędne)
  +StateGame	(informacje o współrzędnych węża, punkty gracza itd)
  +StateButton	(ostatni przycisk i flaga zmodyfikowania)
 
 +Typy wyliczeniowe:
  +ModifyFlagStatus	(flaga przycisku)
  +ButtonState		(oznaczenia przycisków)
  +CollisionsState	(flagi kolizji)
  +GameStatus		(flagi statusu gry)

 +funkcje:
  +wypełnienie wstępnych wartości struktur
  +dodawanie i pobieranie informacji o współrzędnych węża
  +dodawanie i pobieranie długości węża
  +dodawanie i pobieranie punktów
  +sprawdzanie kolizji z ramką, samym sobą i owocem
  +blokada 'cofnięcia się w siebie'
  +generowanie owocu wewnątrz ramki i poza wężem

  +pobieranie i wstawianie stanu przycisku i jej flagi

  +pauza gry
  +regulowana długość czasu kroku

-snake_game
 +zawiera główną pętlę gry

-main_menu_lib
 +funkcje odpowiedzialne za działanie poszczególnych menu
  +rysowanie pozycji menu
  +wyświetlanie ramki zaznaczenia
  +możliwość przejścia z pierwszej pozycji do ostatniej i vice versa

-button
 +konfiguracja przycisków
 +wejście z podcięgnięciem do GND z wyzwalaniem przerwania na zbocze narastające

-IRQHandler (obsługa przerwań przycisków)
 +załączenie timera sprawdzającego ponownie stan przycisku
 +przerwanie timera ustawia zawartość struktury przycisku i wyłącza się

-TimerConfig (ustawienia timerów)
 +ponownego sprawdzania przycisku
 +sterowanie długością cyklu gry



Do wprowadzenia opcjonalnie w przyszłości:
-losowe generowanie przeszkód wewnątrz
-losowe generowanie tuneli
-powiększenie mapy poza widoczny obszar