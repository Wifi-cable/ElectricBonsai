#include <avr/io.h>
#include<avr/delay.h>
void main( void){
	//outputs
	DDRB |= ((1 << DDB1) | (1 << DDB0)); 

	//pwm init ------------------
	// Pin5 or red LED
	TCCR0A |= (1 << COM0A1); 	//fast PWM 
 
	
	TCCR0A |= ((1 << WGM01) | (1 << WGM00)); //top = OCRA fast PWM
	
	TCCR0A |= (1 << COM0B1); 
	// Pin5 or red LED
	TCCR0A |= (1 << COM0B1); //fast PWM
	
	//timer on 

	
	TCCR0B |= ((0 << CS02)| (1 << CS00));  // /64
	
	uint8_t blue = 0;
	uint8_t pink = 253; 
	uint8_t pink_fade = 0;
	uint8_t blue_fade = 1; 
	
	uint8_t prescale = 0;

OCR0A = 128;

		while(1){
		/**TODO
		setup slow timer interrupt, conter and flag
		fade LEDs 
		
		Maybe look for formula or arrayy with logarythmic fadees
**/
		_delay_ms(20);
		OCR0A++;
		OCR0B--;
}
	

}
