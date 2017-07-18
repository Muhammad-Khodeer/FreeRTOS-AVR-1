#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//#include "SSEG.h"
//#include "MYMICRO.h"

#include "FreeRTOS.h"
#include "task.h"


#define PinSet(port,num) port |= (1<<num)
#define Pinclr(port,num) port &=~(1<<num)

/*-----------------------------------------------------------*/
void LED_Task( void *pvParameters );
void SSEG_Task( void *pvParameters );

volatile unsigned long ul;
#define mainDELAY_LOOP_COUNT 50000


int main(void)
{
	///////////////////////////////////////////////////////////////
	
	PinSet(DDRD,2); // make pin2 at portD as an output(1)
	PinSet(DDRA,1); // make pin2 at portD as an output(1)
	
	
	xTaskCreate( LED_Task, "Task 1", 200, NULL, 2, NULL );

	xTaskCreate( SSEG_Task, "Task 2", 200, NULL, 2, NULL );

	vTaskStartScheduler();
	//////////////////////////////////////////////////////////////
	for ( ;; );
	return 0;
}


void LED_Task( void *pvParameters )
{
	PinSet(PORTD,2);
//	PORTA = 0b00000000;
	for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
	{ }
}

void SSEG_Task( void *pvParameters )
{
	PinSet(PORTA,1);
//	PORTD = 0b00000000;
	for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
	{ }
}
