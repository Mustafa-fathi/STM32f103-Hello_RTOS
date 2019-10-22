#ifndef _MSTK_interface_h
#define _MSTK_interface_h

void MSTK_Intialization(void);
void  MSTK_SetCallBack(void(*ptr)(void));
//we didnt have to make prototype for systick_handler because it is an interrupt and noone can control or interface it




#endif