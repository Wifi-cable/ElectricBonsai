#include <avr/io.h>



void main( void){
	//outputs
	DDRB |= ((1 << DDB1) | (1 << DDB0)); 

	//pwm init ------------------
	// Pin5 or red LED
	TCCR0A |= (1 << COM0A1); 	//fast PWM
	TCCR0A |= ((1 << WGM01) | (1 << WGM00)); //top = OCRA

	// Pin5 or red LED
	TCCR0B |= (1 << COM0B1); //fast PWM
	TCCR0B |= (1 << WGM02) ; //top = OCRA
	
	//timer on 
	TCCR0B |= (1 << CS00 );	//no prescaler initially
	while(1){
	
	}
}
