#include "stm32f4xx_gpio.h"
#include "stm32f4xx_exti.h"
#include "misc.h"
#include "stm32f4xx_syscfg.h"

//Accept
void InitEXTIButtonPA0()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;    		// interrupt number
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	// main priority
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		// subpriority
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// run the channel
    	NVIC_Init(&NVIC_InitStructure);			    		// save structure

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_0;		    	// select line
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// select mode - interruption or event
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;		// selection slopes
    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// run a interrupt lines
    	EXTI_Init(&EXTI_InitStructure);			    		// save structure
    	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);	// connect pin with the interrupt controller

    }

//up
void InitEXTIButtonPA1()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);
    	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			//group:2 sub-priority:8

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;    		// interrupt number
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	// main priority
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		// subpriority
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// run the channel
    	NVIC_Init(&NVIC_InitStructure);			    		// save structure

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_1;		    	// select line
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// select mode - interruption or event
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;    	// selection slopes
    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// run a interrupt lines
    	EXTI_Init(&EXTI_InitStructure);			    		// save structure
    	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource1);	// connect pin with the interrupt controller

    }

//right
void InitEXTIButtonPA2()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);

    	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			//group:2 sub-priority:8

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;    		// interrupt number
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	// main priority
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		// subpriority
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// run the channel
    	NVIC_Init(&NVIC_InitStructure);			    		// save structure

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_2;		    	// select line
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// select mode - interruption or event
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;		// selection slopes
    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// run a interrupt lines
    	EXTI_Init(&EXTI_InitStructure);			    		// save structure
    	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource2);	// connect pin with the interrupt controller

    }

//down
void InitEXTIButtonPA3()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);

   	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//group:2 sub-priority:8

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;    		// interrupt number
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	// main priority
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		// subpriority
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// run the channel
    	NVIC_Init(&NVIC_InitStructure);			    		// save structure

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_3;		    	// select line
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// select mode - interruption or event
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;		// selection slopes
    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// run a interrupt lines
    	EXTI_Init(&EXTI_InitStructure);			    		// save structure
    	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource3);	// connect pin with the interrupt controller

    }

//left
void InitEXTIButtonPA4()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);

    	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			//group:2 sub-priority:8

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;    		// interrupt number
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	// main priority
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		// subpriority
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// run the channel
    	NVIC_Init(&NVIC_InitStructure);			    		// save structure

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_4;		    	// select line
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// select mode - interruption or event
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;		// selection slopes

    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// run a interrupt lines
    	EXTI_Init(&EXTI_InitStructure);			    		// save structure
    	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource4);	// connect pin with the interrupt controller
    }
