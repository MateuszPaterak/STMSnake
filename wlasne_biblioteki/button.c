#include "include.h"

//left
void InitEXTIButtonPA0()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;    		// numer przerwania
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// priorytet glowny
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; 		// subpriorytet
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// uruchom dany kanal
    	NVIC_Init(&NVIC_InitStructure);			    		// zapisz wypelniona strukture do rejestrow

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_0;		    	// wybor numeru aktualnie konfigurowanej lini przerwan
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// wybor trybu - przerwanie badz zdarzenie
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		// wybor zbocza, na ktore zareaguje przerwanie
    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// urochom dana linie przerwan
    	EXTI_Init(&EXTI_InitStructure);			    		// zapisz strukture konfiguracyjna przerwan zewnetrznych do rejestrow
    	SYSCFG_EXTILineConfig(GPIOA, EXTI_PinSource0);    		// podlaczenie danego pinu portu do kontrolera przerwan

    }

//up
void InitEXTIButtonPA1()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;    		// numer przerwania
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// priorytet glowny
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; 		// subpriorytet
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// uruchom dany kanal
    	NVIC_Init(&NVIC_InitStructure);			    		// zapisz wypelniona strukture do rejestrow

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_1;		    	// wybor numeru aktualnie konfigurowanej lini przerwan
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// wybor trybu - przerwanie badz zdarzenie
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		// wybor zbocza, na ktore zareaguje przerwanie
    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// urochom dana linie przerwan
    	EXTI_Init(&EXTI_InitStructure);			    		// zapisz strukture konfiguracyjna przerwan zewnetrznych do rejestrow
    	SYSCFG_EXTILineConfig(GPIOA, EXTI_PinSource1);    		// podlaczenie danego pinu portu do kontrolera przerwan

    }

//right
void InitEXTIButtonPA2()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;    		// numer przerwania
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// priorytet glowny
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; 		// subpriorytet
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// uruchom dany kanal
    	NVIC_Init(&NVIC_InitStructure);			    		// zapisz wypelniona strukture do rejestrow

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_2;		    	// wybor numeru aktualnie konfigurowanej lini przerwan
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// wybor trybu - przerwanie badz zdarzenie
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		// wybor zbocza, na ktore zareaguje przerwanie
    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// urochom dana linie przerwan
    	EXTI_Init(&EXTI_InitStructure);			    		// zapisz strukture konfiguracyjna przerwan zewnetrznych do rejestrow
    	SYSCFG_EXTILineConfig(GPIOA, EXTI_PinSource2);    		// podlaczenie danego pinu portu do kontrolera przerwan

    }

//down
void InitEXTIButtonPA3()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;    		// numer przerwania
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// priorytet glowny
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; 		// subpriorytet
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// uruchom dany kanal
    	NVIC_Init(&NVIC_InitStructure);			    		// zapisz wypelniona strukture do rejestrow

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_3;		    	// wybor numeru aktualnie konfigurowanej lini przerwan
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// wybor trybu - przerwanie badz zdarzenie
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		// wybor zbocza, na ktore zareaguje przerwanie
    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// urochom dana linie przerwan
    	EXTI_Init(&EXTI_InitStructure);			    		// zapisz strukture konfiguracyjna przerwan zewnetrznych do rejestrow
    	SYSCFG_EXTILineConfig(GPIOA, EXTI_PinSource3);    		// podlaczenie danego pinu portu do kontrolera przerwan

    }

//akcept
void InitEXTIButtonPA4()
    {
	GPIO_InitTypeDef  GPIO_InitStructure;

    	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    	GPIO_Init(GPIOA, &GPIO_InitStructure);

    	NVIC_InitTypeDef NVIC_InitStructure;
    	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;    		// numer przerwania
    	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// priorytet glowny
    	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; 		// subpriorytet
    	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    		// uruchom dany kanal
    	NVIC_Init(&NVIC_InitStructure);			    		// zapisz wypelniona strukture do rejestrow

    	EXTI_InitTypeDef EXTI_InitStructure;
    	EXTI_InitStructure.EXTI_Line = GPIO_Pin_4;		    	// wybor numeru aktualnie konfigurowanej lini przerwan
    	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    		// wybor trybu - przerwanie badz zdarzenie
    	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		// wybor zbocza, na ktore zareaguje przerwanie
    	EXTI_InitStructure.EXTI_LineCmd = ENABLE;	    		// urochom dana linie przerwan
    	EXTI_Init(&EXTI_InitStructure);			    		// zapisz strukture konfiguracyjna przerwan zewnetrznych do rejestrow
    	SYSCFG_EXTILineConfig(GPIOA, EXTI_PinSource4);    		// podlaczenie danego pinu portu do kontrolera przerwan

    }
