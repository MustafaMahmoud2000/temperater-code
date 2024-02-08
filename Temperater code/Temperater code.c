//Author Mustafa mahmoud
#include <avr/io.h>
#include "ADC.h"
#include "LCD 8BIT.h"
#include "LED.h"
#include "buzzer.h"
#include "button.h"
unsigned char read;
#include "std_macros.h"
unsigned short temp,Volt;
unsigned char read1=0 ,read2=0,read3=0;
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	LCD_INIT();
	ADC_vINIT();
	vLed_init('a',3);
	vLed_init('b',6);
	buzzer_init('b',7);
	LCD_SEND_STRING("Temperature=");
	vButton_init('a',2);
	vButton_init('a',4);
	vButton_init('b',5);
	DDRC=0xff;
	SET_BIT(PORTC,2);
    while(1)
    {
		LCD_SEND_CMD(0x0c);
		Volt=(ADC_u16READ()*2.5);
		temp=(ADC_u16READ()*0.25);
       if(Volt>=1000)//(+)degree
 		{ 
			temp=(Volt-1000)/10;
			if(temp>0 && temp<10)
		   {
			   
				LCD_MOVE_CURSOR(1,13);
				LCD_SEND_CHAR((temp/10)+48);
				LCD_SEND_CHAR((temp%10)+48);
				LCD_SEND_CHAR(0xDF);
				LCD_SEND_CHAR('C');
			    LCD_MOVE_CURSOR(2,6);
				read1=u8Button_read('a',2);
				if (read1==1)
				{
					vLed_off('a',3);
				}
				else
				{
					vLed_on('a',3);
				}
				
				LCD_SEND_STRING(" Cold   ");
				CLEAR_BIT(PORTC,0);
				vLed_off('b',6);
				buzzer_off('b',7);
			}
			
			else if(temp>=10 && temp<25)
			{
				
				LCD_MOVE_CURSOR(1,13);
				LCD_SEND_CHAR((temp/10)+48);
				LCD_SEND_CHAR((temp%10)+48);
				LCD_SEND_CHAR(0xDF);
				LCD_SEND_CHAR('C');
				LCD_MOVE_CURSOR(2,6);
				LCD_SEND_STRING("  Cold   ");
				read1=u8Button_read('a',2);
				if (read1==1)
				{
					vLed_off('a',3);
					
				}
				else
				{
					vLed_on('a',3);
				}
			CLEAR_BIT(PORTC,0);
			vLed_off('b',6);
			buzzer_off('b',7);
			
			}				
			
			else if (temp>=25 && temp<35)
			{
			
				LCD_MOVE_CURSOR(1,13);
				LCD_SEND_CHAR((temp/10)+48);
				LCD_SEND_CHAR((temp%10)+48);
				LCD_SEND_CHAR(0xDF);
				LCD_SEND_CHAR('C');
				LCD_MOVE_CURSOR(2,6);
				LCD_SEND_STRING(" warm    ");
				vLed_off('a',3);
				CLEAR_BIT(PORTC,0);
				vLed_off('b',6);
				buzzer_off('b',7);
			}
			else if (temp>= 35 && temp<45)
			{
					LCD_MOVE_CURSOR(1,13);
					LCD_SEND_CHAR((temp/10)+48);
					LCD_SEND_CHAR((temp%10)+48);
					LCD_SEND_CHAR(0xDF);
					LCD_SEND_CHAR('C');	
					LCD_MOVE_CURSOR(2,6);
					LCD_SEND_STRING("   Hot    ");
					read2=u8Button_read('a',4);
					if (read2==1)
					{
						
						CLEAR_BIT(PORTC,0);
						
						
					}
					else
					{
						SET_BIT(PORTC,0);
					}
					vLed_off('a',3);
					vLed_off('b',6);
					buzzer_off('b',7);
				}
					
			else if (temp>=45 && temp<=55)
			{
					LCD_MOVE_CURSOR(1,13);
					LCD_SEND_CHAR((temp/10)+48);
					LCD_SEND_CHAR((temp%10)+48);
					LCD_SEND_CHAR(0xDF);
					LCD_SEND_CHAR('C');	
					LCD_SEND_CMD(0x0c);
					LCD_MOVE_CURSOR(2,5);
					LCD_SEND_STRING(" Very Hot     ");
					vLed_off('a',3);
					read2=u8Button_read('a',4);
				    if (read2==1)
					{
						CLEAR_BIT(PORTC,0);
					}
					else
					{
						SET_BIT(PORTC,0);
					}					
					vLed_off('a',3);
					vLed_off('b',6);
					buzzer_off('b',7);
			
			}
			else if(temp>55)
			{
				LCD_MOVE_CURSOR(1,13);
				LCD_SEND_CHAR((temp/10)+48);
				LCD_SEND_CHAR((temp%10)+48);
				LCD_SEND_CHAR(0xDF);
				LCD_SEND_CHAR('C');	
				LCD_MOVE_CURSOR(2,6);
				LCD_SEND_STRING("  fire      ");
				vLed_off('a',3);
				CLEAR_BIT(PORTC,0);
				
				read3=u8Button_read('b',5);
				if (read3==1)
				{
					vLed_off('b',6);
					buzzer_off('b',7);
				}
				else
				{
					vLed_toggle('b',6);
					buzzer_on('b',7);
				}
			}		
	}
	
	
	
	
	
			
      else //(-)degree
      {
			 
				  LCD_MOVE_CURSOR(2,7);
				  LCD_SEND_STRING(" Snow   ");
				 temp=((1000-Volt)/10)+1;
				if(temp<0)
				 {
				
					 LCD_MOVE_CURSOR(1,13);
					 LCD_SEND_CHAR('-');
					 LCD_SEND_CHAR((temp%10)+48);
					 LCD_SEND_CHAR(0xDF);
					 LCD_SEND_CHAR('C');
		               CLEAR_BIT(PORTC,0);
					   vLed_off('b',6);
					   buzzer_off('b',7);
					   read1=u8Button_read('a',2);
					   if (read1==1)
					   {
						   vLed_off('a',3);
						   
					   }
					   else
					   {
						   vLed_on('a',3);
					   }
				
				 }
				 else 
				 {
				 
					 LCD_MOVE_CURSOR(1,13);
					 LCD_SEND_CHAR('-');
					 LCD_SEND_CHAR((temp/10)+48);
					 LCD_SEND_CHAR((temp%10)+48);
					 LCD_SEND_CHAR(0xDF);
					 LCD_SEND_CHAR('C');
				      CLEAR_BIT(PORTC,0);
					  vLed_off('b',6);
					  buzzer_off('b',7);
					  read1=u8Button_read('a',2);
					  if (read1==1)
					  {
						  vLed_off('a',3);
						  
					  }
					  else
					  {
						  vLed_on('a',3);
					  }
		        
				 }	
	     }			 		 
         
    }
}
