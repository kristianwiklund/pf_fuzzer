// thing to blink the led on pin PB3 on an attiny85

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>


int main() {
  //	DDRB |= 8; // LED on PB1
	DDRB = 0x3F;	
	while(1) {
		PORTB |= 2; // Turn LED on
		_delay_ms(1000);
		PORTB &= ~2; // Turn LED off
		_delay_ms(1000);
	}

	return 1;
}
