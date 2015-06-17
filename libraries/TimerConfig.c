#include "include.h"

void ConfTim2()
{
	NVIC_InitTypeDef NVIC_InitStructure;

	//przerwanie ogolne od timera2
	  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = 500ul;  		//0,5s: 999   1s: 1999  2s:3999  //co ile kroków przepe³nienie licznika
	TIM_TimeBaseStructure.TIM_Prescaler = 8400-1;		//0,5s: 41999 1s: 41999 2s:41999 //taka wartosæ powoduje, ¿e w ci¹gu sekundy, licznik zliczy 2000 kroków
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);

}

void ConfTim3(unsigned int Period)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = Period-1;  		//0,5s: 999   1s: 1999  2s:3999  //co ile kroków przepe³nienie licznika
	TIM_TimeBaseStructure.TIM_Prescaler = 42000-1;		//0,5s: 41999 1s: 41999 2s:41999 //taka wartosæ powoduje, ¿e w ci¹gu sekundy, licznik zliczy 2000 kroków
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

}

