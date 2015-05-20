#include "include.h"
#include "snake_engine.h"
void TIM2_IRQHandler()
    {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{

	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);	    //kasowanie znacznika przerwania
	TIM_Cmd(TIM2, DISABLE);                             //wylaczenie licznika
	TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);         //wylaczenie przerwania

	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1))
	    {
	    if(GetModifyFlag()==NotModify)
	    	{
	    	SetButtonState(Button_Up);
	    	SetModifyFlag(Modify);
	    	}
	    }
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2))
	    {
	    if(GetModifyFlag()==NotModify)
		{
		SetButtonState(Button_Right);
		SetModifyFlag(Modify);
		}
	    }

	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3))
	    {
	    if(GetModifyFlag()==NotModify)
		{
		SetButtonState(Button_Down);
		SetModifyFlag(Modify);
		}
	    }

	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4))
	    {
	    if(GetModifyFlag()==NotModify)
		{
		SetButtonState(Button_Left);
		SetModifyFlag(Modify);
		}
	    }

	 }//TIM_GetItStatus
    }//handler

/*
//akcept
void EXTI0_IRQHandler(void)
	{
		if(EXTI_GetITStatus(EXTI_Line0) != RESET)
		{



		    EXTI_ClearITPendingBit(EXTI_Line0);
		}
	}
*/

//up
void EXTI1_IRQHandler(void)
	{
		if(EXTI_GetITStatus(EXTI_Line1) != RESET)
		{
		    TIM_SetCounter(TIM2, 0);            //zerowanie licznika
		    TIM_Cmd(TIM2, ENABLE);              //wlaczenie licznika
		    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//wlaczenie przerwania

		    EXTI_ClearITPendingBit(EXTI_Line1);
		}
	}

//right
void EXTI2_IRQHandler(void)
	{
		if(EXTI_GetITStatus(EXTI_Line2) != RESET)
		{
		    TIM_SetCounter(TIM2, 0);            //zerowanie licznika
		    TIM_Cmd(TIM2, ENABLE);              //wlaczenie licznika
		    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//wlaczenie przerwania

		    EXTI_ClearITPendingBit(EXTI_Line2);
		}
	}

//down
void EXTI3_IRQHandler(void)
	{
		if(EXTI_GetITStatus(EXTI_Line3) != RESET)
		{
		    TIM_SetCounter(TIM2, 0);            //zerowanie licznika
		    TIM_Cmd(TIM2, ENABLE);              //wlaczenie licznika
		    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//wlaczenie przerwania

		    EXTI_ClearITPendingBit(EXTI_Line3);
		}
	}
//left
void EXTI4_IRQHandler(void)
	{
		if(EXTI_GetITStatus(EXTI_Line4) != RESET)
		{
		    TIM_SetCounter(TIM2, 0);            //zerowanie licznika
		    TIM_Cmd(TIM2, ENABLE);              //wlaczenie licznika
		    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//wlaczenie przerwania

		    EXTI_ClearITPendingBit(EXTI_Line4);
		}
	}
