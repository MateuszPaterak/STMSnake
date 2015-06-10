# STMSnake

<h2>Overview</h2>
</br>Our procject implement a polular 2D game Snake on STM32F4 microcontroler with display screen from Nokia 3310, SD Card Module and simple keyboard build with microswitch buttons.
<h2>Description</h2>
<h4>Display</h4>
</br>Dispaly resolution: 84 x 48
</br>Interface: SPI
</br>Driver source: http://stm32f4-discovery.com (by Tilen Majerle)
<ul>
<li>Drawing: points, lines, rectangles and circles</li>
<li>Drawing: chars 5x7 and 3x5 (pixels)</li>
<li>Change a display contrast</li>
</ul>
</br>Our functions
<ul>
<li>Drawing bitmap</li>
<li>Drawing snake</li>
<li>Drawing simple elements of game environment (in gird)</li>
</ul>

<h4>SD Card Module</h4>
</br>Interface: SPI
</br>Driver source: www.elektroda.pl (by mrh)
</br>Support FAT file system

<h4>The most important file in project:</h4>
<ul>
<li>snkakelib (graphic)</li>
<li>snake_engine (important function for game logic)</li>
snake_game
<li></li>
<li></li>
<li></li>
<li></li>
</ul>

<h2>Tools </h2>
<h2>How to run </h2>
<h2>How to compile</h2>
<h2>Future improvements</h2>
<h2>Attributions</h2>
</br>Display driver source: http://stm32f4-discovery.com (by Tilen Majerle)
</br>SD Card driver source: www.elektroda.pl (by mrh)
<h2>License</h2>
<h2>Credits</h2>


The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Michał Fularz 


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

