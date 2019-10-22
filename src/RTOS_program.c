#include "LSTD_TYPES.h"
#include"MSTK_interface.h"
#include "RTOS_interface.h"
#define TasksNumber 2

Task SysTasks [TasksNumber];
static volatile u32 TickCount=0;



void RTOS_createTask(u8 ID ,u16 perid , void (*func)(void))
{
	SysTasks[ID].periodicity=perid;
	SysTasks[ID].TaskHandler=func;
	
}
void schedular (void)
{
	u8 LoopCounter;
	TickCount++; 
	for(LoopCounter=0 ; LoopCounter<TasksNumber ; LoopCounter++)
	{
		if ((TickCount % SysTasks[LoopCounter].periodicity)==0 )
		{
			SysTasks[LoopCounter].TaskHandler();
			
		}
		
	}
}

void RTOS_initilaize(void)
{

	MSTK_SetCallBack(schedular);

}

