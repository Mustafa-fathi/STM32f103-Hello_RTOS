#ifndef _RTOS_INTERFACE_H
#define _RTOS_INTERFACE_H

typedef struct
{
	void (* TaskHandler)(void);  //pointer to function that we want to execute   
	u16 periodicity;    //the time that the task take execute but in TICK
	
	
} Task;

void RTOS_createTask(u8 ID ,u16 perid , void (*func)(void));
void RTOS_initilaize(void);

#endif