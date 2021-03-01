#include <avr/io.h>

void main( void){
	//outputs
	DDRB |= ((1 << DDB1) | (1 << DDB0)); 

	//pwm init ------------------
	// Pin5 or red LED
	//TCCR0A |= (1 << COM0A1); 	//fast PWM 
	//TCCR0A |= (1 << COM0A1) |(1 << COM0A0); 	//fast PWM Clear OC0A on Compare Match, set OC0A at TOP
	TCCR0A |= (1 << COM0A0); 
	
	TCCR0A |= ((1 << WGM01) | (1 << WGM00)); //top = OCRA fast PWM
	
	TCCR0A |= (1 << COM0B1); 
	// Pin5 or red LED
	TCCR0B |= (1 << COM0B1); //fast PWM
	
	//timer on 

	TCCR0B |= (1 << WGM02); // wave form generation mode 7 
	TCCR0B |= ((1 << CS02)| (1 << CS00));
	
	uint8_t blue = 0;
	uint8_t pink = 253; 
	uint8_t pink_fade = 0;
	uint8_t blue_fade = 1; 
	
	uint8_t prescale = 0;
	
	
	
		while(1){
		
		
		//if(prescale >= 253){
		
			if(pink_fade){
				pink--;
				blue--;
			}
			else{
				pink++; 
				blue--;
			}
			
			if(blue_fade){
				blue--;
			}
			else{
			 blue++; 
			}
		//prescale = 0;
		//}
		/**
		else{
			prescale ++; 
		}
		**/
		if(pink >= 253){	// decrease
			pink_fade = 1;
		}
		
		else if(pink <= 1){	// increase 
			pink_fade = 0;
		}
		
		else if(blue >= 253){	//decrease
			blue_fade = 1;
		}
		
		else if(blue <= 1){	// increase
			blue_fade = 0;
		}
		
		OCR0A = blue;
		OCR0B = pink;
	
		}
}
