/*
 * SSEG.h
 *
 * Created: 15/07/2015 07:23:23 
 * Author: Muhammad
 */ 


#ifndef SSEG_H_
#define SSEG_H_
	/*********** Typedef **********/
	typedef enum BitLocation
	{
		RIGHT,
		LEFT
	}
	POS;
	/******* function Prototyprs *******/
	void init_SSEG(void);
	// you must call init_SSEG before calling this function
	//POS should be LEFT or RIGHT
	void SSEG_Print9(POS Position,unsigned char num);
	// you must call init_SSEG and OStime_start() before using this function
	void SSEG_Print99(unsigned char num);
	// this function is called by the timer ISR every 10ms
	void SSEG_cyclic10ms(void);

#endif /* SSEG_H_ */