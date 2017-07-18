/*
 * SSEG_HardWare_Layer_.c
 *
 * Created: 15/07/2015 06:44:35 م
 *  Author: Muhammad
 */ 

#include "MYMICRO.h"
#include "SSEG.h"
//#include "OStime.h"
//#include <avr/io.h>

//////////////   local variables   ////////////
static uint8_t SSEG_NUM;
uint8_t StartSSEG = 0;
///////////////////////////////////////////////

void init_SSEG(void)
{
	SSEG_Init;
	StartSSEG = 1;    // a flag of set it enable the SSEG to work By the OS
}

// function to print one digit number
void SSEG_Print9(POS Position,unsigned char num)  // take two parameter the one digit num & its position.
{
	SSEG_PINS(num); /* PORTB = (num<<4); */       // load the number to the 4 pins [HW-Design].
	if(Position == LEFT)
	{
		EN_LEFT_SEG;                              // display at left if the position is left.
	}
	else
	{
		EN_RIGHT_SEG;                             // display at Right if the position is Right.
	}
}

// this function is called in the main just to get the number to be print
void SSEG_Print99(unsigned char num)
{
	SSEG_NUM = num;                              // the number to be print
}

//// this cyclic should be called each 10ms from OS
void SSEG_cyclic10ms(void)
{												// static variable : the declaration and initialization
	static unsigned char flag=0;				// will happen once at the first call.
	if (StartSSEG)								// if this flag is set then the OS can Print
	{
		if(flag)								// if flag == 1
		{
			SSEG_Print9(LEFT,SSEG_NUM/10);      // print the left digit at left
			flag = 0;
		}
		else									// if flag == 0
		{
			SSEG_Print9(RIGHT,SSEG_NUM%10);     // print the Right digit at Right
			flag = 1;
		}
	}								
}
