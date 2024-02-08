/*
 * buzzer.c
 *
 * Created: 2/6/2024 3:24:55 AM
 *  Author: DELL
 */ 
#include "DIO.h"
void buzzer_init(unsigned char port, unsigned char pin)
{
	vDIO_SET_BIT_DIR(port,pin,1);
}
void buzzer_on(unsigned char port,unsigned char pin)
{
	vDIO_WRITE_BIT(port,pin,1);
}
void buzzer_off(unsigned char port,unsigned char pin)
{
	vDIO_WRITE_BIT(port,pin,0);
}
void buzzer_toggle(unsigned char port,unsigned char pin)
{
	vDIO_TOGGLE_BIT(port,pin);
}
unsigned char buzzer_readstatus(unsigned char port,unsigned char pin)
{
		return u8DIO_READ_BIT(port,pin);
}
