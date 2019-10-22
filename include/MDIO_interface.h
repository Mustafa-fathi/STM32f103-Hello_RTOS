#ifndef MDIO_INTERFACE_H
#define MDIO_INTERFACE_H

#define MDIO_PORTA     22
#define MDIO_PORTB     9
#define MDIO_PORTC     91

#define MDIO_HIGH      11
#define MDIO_LOW       15

void MDIO_Initialize(void);
void MDIO_SetPinValue (u8 Port, u8 PinNum, u8 Value);
void MDIO_SetPin (u8 Port,u8 PinNum);
void MDIO_ClearPin(u8 Port, u8 PinNum);
void MDIO_AssignPort(u8 Port,u16 value);
#endif
