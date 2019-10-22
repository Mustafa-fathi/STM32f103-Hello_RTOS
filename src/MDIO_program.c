#include "LSTD_TYPES.h"

#include "MDIO_private.h"
#include "MDIO_interface.h"

void MDIO_Initialize(void)
{
	GPIOA -> CRL = 0x22;     //output mode
}

void MDIO_SetPinValue (u8 Port, u8 PinNum, u8 Value)
{
	switch (Port)
	{
		case MDIO_PORTA : if (Value == MDIO_HIGH)
						GPIOA -> ODR |= (1<<PinNum);
					    else
						GPIOA -> ODR &= ~(1<<PinNum);
					    break;
		case MDIO_PORTB:
					if (Value == MDIO_HIGH)
						GPIOB -> ODR |= (1<<PinNum);
					else
						GPIOB -> ODR &= ~(1<<PinNum);
					break;
		case MDIO_PORTC:
					if (Value == MDIO_HIGH)
						GPIOC -> ODR |= (1<<PinNum);
					else
						GPIOC -> ODR &= ~(1<<PinNum);
					break;
	}
}


/*if you need to (set) pin you should select (BSRR) register take care without using AND or OR operations */
void MDIO_SetPin (u8 Port,u8 PinNum)
{
	
	
	switch (Port)
	{
		case MDIO_PORTA :  GPIOA -> BSRR = (1<<PinNum); 
		                   break;
						
					   
		case MDIO_PORTB:   GPIOB -> BSRR = (1<<PinNum); 
		                   break;
						   
						   
		case MDIO_PORTC:   GPIOC -> BSRR = (1<<PinNum); 
		                   break;
	}
	
}

/*if you need to (reset) pin you should select (BRR) register take care without using AND or OR operations */
void MDIO_ClearPin(u8 Port, u8 PinNum)
{
	switch (Port)
	{
		case MDIO_PORTA :  GPIOA -> BRR = (1<<PinNum); 
		                   break;
						
					   
		case MDIO_PORTB:   GPIOB -> BRR = (1<<PinNum); 
		                   break;
						   
						   
		case MDIO_PORTC:   GPIOC -> BRR = (1<<PinNum); 
		                   break;
	}
	
	
	
}


void MDIO_AssignPort(u8 Port,u16 value)
{
	
	switch (Port)
	{
		case MDIO_PORTA : GPIOA -> ODR =value;
		                  break;
						  
		case MDIO_PORTB: GPIOB -> ODR =value;
		                  break;
					
		case MDIO_PORTC: GPIOC -> ODR =value;
		                  break;
					
	}
	
	
}




	
	

