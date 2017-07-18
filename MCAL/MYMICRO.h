/*
 * MYMICRO.h
 *
 * Created: 16/07/2015 02:38:21 م
 *  Author: Muhammad
 */ 


#ifndef MYMICRO_H_
#define MYMICRO_H_

#include <avr/io.h>

typedef unsigned char u8;

							/*** General ***/
#define Bit_Set(REG, Num) REG |= (1<<Num)
#define Bit_Clr(REG, Num) REG &= ~(1<<Num)
							/***  SSEG iInitialization ***/
#define SSEG_Init Bit_Set(DDRA, 4);\
				  Bit_Set(DDRA, 5);\
				  DDRB |= 0xF0
				     		// Print **/
#define SSEG_PINS(NUM) PORTB = (PORTB&0x0F)|(NUM<<4)
							// switch  */
#define EN_RIGHT_SEG	PORTA &= ~(1<<4);\
						PORTA |= (1<<5)
#define EN_LEFT_SEG		PORTA &= ~(1<<5);\
						PORTA |= (1<<4)
						/** OS  **/
#define Enable_GlobalInterrupt sei()
#define Enable_OverFlow_Timer0 Bit_Set(TIMSK, TOIE0)
#define Start_With_Speed_Type1 Bit_Set(TCCR0, CS00);\
							   Bit_Clr(TCCR0, CS01)
							   
						/*** EEPROM ***/
//initialization
#define statusRegister_0	TWSR = 0x00 // status register initialize zeros
#define bitRate_47			TWBR = 0x47 // set bit rate of the clock pulse to send by
#define I2C_Enable			TWCR = 0x04 // enable TWI(I2C)(0000-0100) control register


u8 i2c_read(u8 isLast);
void i2c_write(u8 data);
void i2c_start(void);
void i2c_stop(void);

							
#define Start_Count TCNT0

#endif /* MYMICRO_H_ */