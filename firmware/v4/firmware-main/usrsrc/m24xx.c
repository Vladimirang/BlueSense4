/*
 * m24xx.c
 *
 *  Created on: 8 Aug 2019
 *      Author: droggen
 */

#include "m24xx.h"
#include "i2c/megalol_i2c.h"

#include "i2c.h"
//#include "stm32f4xx_hal_i2c.h"
#include "usrmain.h"

#include <stdio.h>
#include "usrmain.h"
#include "global.h"

// Select whether to use HAL (1) or megalol transactions.
#define M24XX_USEHAL 0

// Return: 1 if ok
unsigned char m24xx_isok()
{
	unsigned char d;
	unsigned char rv = m24xx_read(0,&d);
	if(rv==0)
		return 1;
	return 0;
}
// Return: 0=success
unsigned char m24xx_write(unsigned short addr16,unsigned char d)
{
#if M24XX_USEHAL==1
	HAL_StatusTypeDef r;
	r = HAL_I2C_Mem_Write(&hi2c1,M24XX_ADDRESS<<1,addr16,2,&d,1,100);
	if(r==HAL_OK)
		return 0;
	return r;
#else
	unsigned char rv = i2c_writereg_a16(M24XX_ADDRESS,addr16,d);
	HAL_Delay(5);	// Maximum write time: 5ms
	return rv;
#endif
}
/******************************************************************************
	function: m24xx_write_buffer_nowait
*******************************************************************************
	Writes a buffer to the eeprom in a single write operation.

	The maximum size of a buffer is limited by the I2C transaction subsystem
	and is 16-3=13 bytes.

	Writes must not cross a page boundary (32 bytes)

	Interrupts:
		Suitable for call in interrupt; does not guarantee that the transaction
		was successfully enqueud, nor that the operation completed.


	Parameters:
		buffer	-		Pointer to the buffer with the data to write
		n		-		Number of bytes to write

	Returns:
		0		-		Success
		1		-		Error

******************************************************************************/
// Return: 0=success
unsigned char m24xx_write_buffer_nowait(unsigned short addr16,unsigned char *buffer,unsigned char n)
{
	unsigned char rv = i2c_writeregs_a16_try(M24XX_ADDRESS,addr16,buffer,n);
	// Normally a maximum write time of 5ms could occur; this fuction does not wait for the EEPROM to be ready.
	return rv;
}

// Return: 0=success
unsigned char m24xx_read(unsigned short addr16,unsigned char *d)
{
#if M24XX_USEHAL==1
	HAL_StatusTypeDef r;
	r = HAL_I2C_Mem_Read(&hi2c1,M24XX_ADDRESS<<1,addr16,2,d,1,100);
	if(r==HAL_OK)
		return 0;
	return r;
#else

	return i2c_readreg_a16(M24XX_ADDRESS,addr16,d,0);
#endif
}

// from: 	Start address, inclusive
// to:		Last address, exclusive
void m24xx_printreg(FILE *f,unsigned from,unsigned to)
{
	for(unsigned addr=from;addr<to;addr++)
	{
		if(!(addr%64))
			fprintf(f,"%04X: ",addr);

		unsigned char data;
		m24xx_read(addr,&data);
		fprintf(f,"%02X ",data);

		if(!((addr+1)%64))
			fprintf(f,":%04X\n",addr);
	}
	fprintf(f,"\n");
}

