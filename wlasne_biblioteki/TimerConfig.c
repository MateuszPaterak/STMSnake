#include "include.h"

void ConfTim2()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	NVIC_InitTypeDef NVIC_InitStructure;

	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); // -> in the button.c

	//przerwanie ogolne od timera2
	  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = 700ul;  		//0,5s: 999   1s: 1999  2s:3999  //co ile krok�w przepe�nienie licznika
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//0,5s: 41999 1s: 41999 2s:41999 //taka wartos� powoduje, �e w ci�gu sekundy, licznik zliczy 2000 krok�w
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);

	//TIM_ClearFlag(TIM1,TIM_FLAG_Update);   //Must first clear configuration the update flag

	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); //w EXTI_IRQHandler  //Enable interrupt, timer interrupt events - Events
	//TIM_Cmd(TIM2, ENABLE); //w EXTI_IRQHandler
}


void ConfTimX()
{
	/*
	 * Odczytanie wartosci rejestru:
	   unsigned int counter = TIMx->CNT;
	 *
	 * Odczytanie flagi przepe�nienia i jej reset:
	   if(TIM_GetFlagStatus(TIMx, TIM_FLAG_Update))
	   {
	   		TIM_ClearFlag(TIMx, TIM_FLAG_Update);
	   }
	 */

	/*
	 * TIMx
	 * x-numer odpowiedniego Timera
	 *
	 * cz�stotliwo�� rdzenia(fcpu) - 168MHz (lub w obliczaniu 2*84)
	 * Cz�stotliwo�� inkrementacji/dekrementacji timera:
	 * ftim=(fcpu)/(2*(prescaler+1))
	 * Cz�stotliwo�� przepe�nienia licznika(i wygenerowania flagi przerwania):
	 * f=(fcpu)/(2*(prescaler+1)*(period+1))
	 *
	 * Czas przepe�nienia:
	 *  = (2*(prescaler+1)*(period+1))/(fcpu)
	 */

			//Pod��czenie szyny zegarowej do odpowiedniego timera:
//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIMx, ENABLE);

			//Konfiguracja:
//		TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

//		TIM_TimeBaseStructure.TIM_Period = 0;  		//0,5s: 999   1s: 1999  2s:3999  //co ile krok�w przepe�nienie licznika
//		TIM_TimeBaseStructure.TIM_Prescaler = 0;	//0,5s: 41999 1s: 41999 2s:41999 //taka wartos� powoduje, �e w ci�gu sekundy, licznik zliczy 2000 krok�w
//		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//TIM_TimeBaseInit(TIMx, &TIM_TimeBaseStructure);

			//Uruchomienie timera:
//TIM_Cmd(TIMx, ENABLE);

	/*
	 *  TIM_Period - okres zliczania timera (uwa�a� na wartosci maksymalne!!! -12bit - 65�536)
		TIM_Prescaler - warto�� dzielnika cz�stotliwosci zegara
 	 	TIM_ClockDivision - dzielnik zegara, domy�lna warto�� to TIM_CKD_DIV1
		TIM_CounterMode - kierunek zliczania (g�ra/d�):
			-TIM_CounterMode_Up
			-TIM_CounterMode_Down

	 * W�asciwosci Timer�w:
	 * TIM 1 i 8 - najbardziej zaawansowane
	 * TIM 2-5 i 9-14 - og�lnego przeznaczenia
	 * TIM 6 i 7 - najprostsze/podstawowe
	 */
}
