/*
 * MYMICRO.c
 *
 * Created: 22/07/2015 02:31:41 ص
 *  Author: Muhammad
 */

#include "MYMICRO.h"
 
u8 i2c_read(u8 isLast)
{
	if(isLast == 0)
	{
		TWCR = (1<< TWINT) | (1<< TWEN) | (1<< TWEA) ;
	}
	else
	{
		TWCR = (1<< TWINT) | (1<< TWEN) ;
	}
	while((TWCR & (1 << TWINT)) == 0);
	return TWDR;
}

void i2c_write(u8 data)
{
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while((TWCR & (1 << TWINT)) == 0 );

}

void i2c_start(void) // to send the start bit
{
	TWCR = (1<< TWINT) | (1<<TWSTA) | (1<<TWEN); // control Register >> start >> write 1>>tagle to start
	while(!(TWCR & (1 << TWINT))); 		     // while sending it is 0 >> wait until it become 1
	//((TWCR & (1 << TWINT)) == 0)
}

void i2c_stop()
{
	TWCR = (1<< TWINT) | (1<< TWEN) | (1<< TWSTO) ;
	//while(!(TWCR & (1 << TWINT)));
}


