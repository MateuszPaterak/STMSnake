#include "include.h"
#include "snake_engine.h"

//left
void EXTI0_IRQHandler(void)
	{
		if(EXTI_GetITStatus(EXTI_Line0) != RESET)
		{
		    if(GetModifyFlag()==NotModify)
			{
			SetButtonState(Button_Left);
			SetModifyFlag(Modify);
			}

		    EXTI_ClearITPendingBit(EXTI_Line0);
		}
	}

//up
void EXTI1_IRQHandler(void)
	{
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

//akcept
void EXTI4_IRQHandler(void)
	{
		if(EXTI_GetITStatus(EXTI_Line4) != RESET)
		{



		    EXTI_ClearITPendingBit(EXTI_Line4);
		}
	}

