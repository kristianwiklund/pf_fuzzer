// thing to blink the led on pin PB3 on an attiny85

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>


int main() {
  	DDRB |= 8; // LED on PB3
	//	DDRB = 0x3F;	
	while(1) {
	  //		PORTB = 255; // Turn LED on
		PORTB |= (1 << PB3);
		_delay_ms(1000);
		//		PORTB = 0; // Turn LED off

		PORTB &= ~(1 << PB3);
		_delay_ms(1000);
	}

	return 1;
}
