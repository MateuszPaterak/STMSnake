# STMSnake

<h2>Overview</h2>
</br>Our procject implement a polular 2D game Snake on STM32F4 microcontroler with display screen from Nokia 3310, SD Cart Module and simple keyboard build with microswitch buttons.
<h2>Description</h2>
<h4>Display</h4>
</br>Dispaly resolution: 84 x 48
</br>Interface: SPI
</br>
</br>

<h2>Tools </h2>
<h2>How to run </h2>
<h2>How to compile</h2>
<h2>Future improvements</h2>
<h2>Attributions</h2>
<h2>License</h2>
<h2>Credits</h2>


The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Michał Fularz 











Implementacja gry Snake na mikrokontrolerze STM32F4 z wykorzystaniem wyświetlacza LCD Nokii 3310 (84 x 48).


Wykorzystane gotowe biblioteki:
</br>-sterownik wyświetlacza:
</br> +źródło: by Tilen Majerle (http://stm32f4-discovery.com)
</br> +obsługa wymiany danych z wyświetlaczem
</br> +rysowanie punktów, linii, prostokątów, okręgów
</br> +ustawienie kursora i wyświetlanie znaków 5x7 oraz 3x5
</br> +zmiana konstrastu obrazu

-sterownik SD
 +źródło: F4_Fat_SD by mrh (www.elektroda.pl)
 +obsługa interfejsu SPI
 +obsługa systemu plików FAT

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
