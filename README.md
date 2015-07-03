# STMSnake

<h2>Overview</h2>
</br>Our project implement a popular 2D game Snake on STM32F4 microcontroller with display screen from Nokia 3310, SD Card Module and simple keyboard build with micro-switch buttons.
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
<li>snkakelib.c (graphic)</li>
<li>snake_engine.c (important function for game logic and SD support)</li>
<li>snake_game.c (main game loop)</li>
<li>button.c (configure buttons)</li>
<li>IRQHandler.c (handling buttons interrupts)</li>
<li>main_menu_lib.c (function to serve menu)</li>
<li>TimerConfig (configure timers)</li>
</ul>

<h2>Tools </h2>
<ul>
<li>CooCox CoIDE v 1.7.7</li>
<li>FastLCD 1.2.0 by Bojan (Free tools to help drawing bitmap)</li>
<li>LCDAssistant by Radoslaw Kwiecen (Free tools for conversions bitmap to byte arrays)</li>
</ul>

<h2>How to run </h2>
</br>Version 1.0.0
</br>You need only STM32F4, Nokia 3310 display screen, SD Cart Module and keyboard with min 5 buttons
</br>
</br>Pinout:
</br>Display:
<ul>
<li>SCK - PB10</li>
<li>MOSI - PC3</li>
<li>D/C - PC14</li>
<li>RST - PC15</li>
<li>SCE - PC13</li>
</ul>

</br>SD Card Module:
<ul>
<li>CS - PB11</li>
<li>MOSI - PB15</li>
<li>SCK - PB13</li>
<li>MISO - PB14</li>
</ul>

</br>Keyboard (secodn side to +3V):
<ul>
<li>Accept - PA0</li>
<li>Up - PA1</li>
<li>Right - PA2</li>
<li>Down - PA3</li>
<li>Left - PA4</li>
</ul>

<h2>How to compile</h2>
</br> Keep calm and compile it.

<h2>Future improvements</h2>
</br>Correct function organizations inside libraries
</br>Sometimes game crashing when SD Card is not in module.
</br>To add in future: generate tunnel, barriers and multiplayer mode

<h2>Attributions</h2>
</br>Display driver source: http://stm32f4-discovery.com (by Tilen Majerle)
</br>SD Card driver source: www.elektroda.pl (by mrh)
</br>Source graphic for bitmap: http://etc.usf.edu/clipart/7200/7221/snake_7221.htm

<h2>License</h2>
</br> License: GNU GPL v3

<h2>Credits</h2>
<ul>
<li>Mateusz Paterak</li>
<li>Adam Filipowicz</li>
</ul>


The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
</br> Supervisor: Michal Fularz 