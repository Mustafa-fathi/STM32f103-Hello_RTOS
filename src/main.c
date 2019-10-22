/*
 * main.c
 *
 *  Created on: Jul 20, 2018
 *      Author: Hampota
 */

#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MRCC_interface.h"
#include "MSTK_interface.h"
#include "RTOS_interface.h"

volatile u8 flag1=0;
volatile u8 flag2=0;

void tooggle1(void)
{
	if(flag1==0)
	{
		MDIO_SetPinValue(MDIO_PORTA,0,MDIO_HIGH);
		flag1=1;
	}
	else
	{
		MDIO_SetPinValue(MDIO_PORTA,0,MDIO_LOW);
				flag1=0;
	}

}



void toggle2(void)
{
	if(flag2==0)
		{
			MDIO_SetPinValue(MDIO_PORTA,1,MDIO_HIGH);
			flag2=1;
		}
		else
		{
			MDIO_SetPinValue(MDIO_PORTA,1,MDIO_LOW);
					flag2=0;
		}
}


void main(void)
{
   MRCC_Initialize();
   MRCC_EnableClock(BUS_ABP2,PERIPHERAL_GPIOA);
   MDIO_Initialize();

   RTOS_initilaize();
   RTOS_createTask(0,1,tooggle1);   //1=500,000 tick
   RTOS_createTask(1,2,toggle2);   //2= 1000,000 tick

   MSTK_Intialization();

	while (1)
	{

	}
}

