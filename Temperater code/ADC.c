
#include <avr/io.h>
#include "std_macros.h"
void ADC_vINIT(void)
{
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,MUX4);
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
}
unsigned short ADC_u16READ(void)
{
	unsigned short read;
	SET_BIT(ADCSRA,ADSC);
	while(IS_BIT_CLR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
    read=(ADCL);
	read|=(ADCH<<8);
	return read;	
}




















// #include <avr/io.h>
// #include "ADC.h"
// #include "LCD 8BIT.h"
// char read;
// unsigned short temp;
// int main(void)
// {
	// 	LCD_clear_screen();
	// 	LCD_INIT();
	// 	ADC_vINIT();
	// 	LCD_SEND_STRING("Temperature=");
	// 	while(1)
	// 	{
		// 		temp=(ADC_u16READ()*0.25);
		//
		// 			if(temp<10)
		// 			{
			// 				LCD_MOVE_CURSOR(1,13);
			// 				LCD_SEND_CHAR(0x30);
			// 				LCD_SEND_CHAR((temp%10)+48);
			// 				LCD_SEND_CHAR(0xDF);//.
			// 				LCD_SEND_CHAR('C');
			// 				LCD_SEND_CHAR(0x43);
			// 				LCD_SEND_CMD(0x0c);
		// 			}
		// 			else if(temp<100)
		// 			{
			// 				LCD_MOVE_CURSOR(1,13);
			// 				LCD_SEND_CHAR(0x30);
			// 				LCD_SEND_CHAR((temp/10)+48);
			// 				LCD_SEND_CHAR((temp%10)+48);
			// 				LCD_SEND_CHAR(0xDF);
			// 				LCD_SEND_CHAR('C');
			// 				LCD_SEND_CMD(0x43);
		// 			}
	// 	}
// }