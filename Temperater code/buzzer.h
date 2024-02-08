/*
 * buzzer.h
 *
 * Created: 2/6/2024 3:26:07 AM
 *  Author: DELL
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_
void buzzer_init(unsigned char port, unsigned char pin);
void buzzer_on(unsigned char port,unsigned char pin);
void buzzer_off(unsigned char port,unsigned char pin);
void buzzer_toggle(unsigned char port,unsigned char pin);
unsigned char buzzer_readstatus(unsigned char port,unsigned char pin);
#endif /* BUZZER_H_ */