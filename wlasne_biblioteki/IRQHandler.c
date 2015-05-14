#include "include.h"
#include "snake_engine.h"
/*
//akcept
void EXTI0_IRQHandler(void)
	{
//	int i=0;
//	for(;i<10000;i++){}

		if(EXTI_GetITStatus(EXTI_Line0) != RESET)
		{



		    EXTI_ClearITPendingBit(EXTI_Line0);
		}
	}
*/

//up
void EXTI1_IRQHandler(void)
	{
	int i=0;
	for(;i<10000;i++){}

		if(EXTI_GetITStatus(EXTI_Line1) != RESET)
		{
		    if(GetModifyFlag()==NotModify)
			{
		    	SetButtonState(Button_Up);
		    	SetModifyFlag(Modify);
		    	}

		    EXTI_ClearITPendingBit(EXTI_Line1);
		}
	}

//right
void EXTI2_IRQHandler(void)
	{
	int i=0;
	for(;i<10000;i++){}

		if(EXTI_GetITStatus(EXTI_Line2) != RESET)
		{
		    if(GetModifyFlag()==NotModify)
			{
		    	SetButtonState(Button_Right);
		    	SetModifyFlag(Modify);
		    	}

		    EXTI_ClearITPendingBit(EXTI_Line2);
		}
	}

//down
void EXTI3_IRQHandler(void)
	{
	int i=0;
	for(;i<10000;i++){}

		if(EXTI_GetITStatus(EXTI_Line3) != RESET)
		{
		    if(GetModifyFlag()==NotModify)
		    	{
		    	SetButtonState(Button_Down);
		    	SetModifyFlag(Modify);
		    	}

		    EXTI_ClearITPendingBit(EXTI_Line3);
		}
	}
//left
void EXTI4_IRQHandler(void)
	{
		int i=0;
		for(;i<10000;i++){}

		if(EXTI_GetITStatus(EXTI_Line4) != RESET)
		{
		    if(GetModifyFlag()==NotModify)
			{
			SetButtonState(Button_Left);
			SetModifyFlag(Modify);
			}

		    EXTI_ClearITPendingBit(EXTI_Line4);
		}
	}
