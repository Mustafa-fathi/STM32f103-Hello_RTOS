#ifndef _MSTK_private_h
#define _MSTK_private_h


typedef struct{
	
	volatile u32  CTRL;
	volatile u32  LOAD;
	volatile u32  VAL;
	volatile u32  CALIB;
	 
	 
	 
} MSTK_type;
#define MSTK ((volatile MSTK_type *)0xe000e010)







#endif
