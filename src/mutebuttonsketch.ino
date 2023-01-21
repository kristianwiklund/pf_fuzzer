#include <TrinketKeyboard.h>


/*
TrinketKeyboard example
For Trinket by Adafruit Industries
*/


#define PIN_BUTTON_CAPITAL_A 4
#define PIN_LED 3
void setup()
{

	// frequency thing...

	/* cli(); // Disable interrupts */
  /* CLKPR = (1<<CLKPCE); // Prescaler enable */
  /* CLKPR = 0x02; // Clock division factor */
  /* sei(); // Enable interrupts */
	
  // button pins as inputs
	pinMode(PIN_BUTTON_CAPITAL_A, INPUT_PULLUP);
	pinMode(PIN_LED,OUTPUT);
	//	DDRB |= 8; // LED on PB3
  // start USB stuff
  TrinketKeyboard.begin();
	digitalWrite(PIN_LED,LOW); 
}
char old=HIGH;
bool muted=false;

extern uint8_t report_buffer[];
void usbReportSend(uint8_t);

void loop()
{
	int fr=F_CPU/1000000L;
  char nnew;
  int cnt=0;
	uint8_t clkps3_0 = CLKPR & 0x0F;
	
	TrinketKeyboard.poll();
	// the poll function must be called at least once every 10 ms
	// or cause a keystroke
	// if it is not, then the computer may think that the device
	// has stopped working, and give errors
	nnew = digitalRead(PIN_BUTTON_CAPITAL_A); 
	
	if (nnew==LOW) 
    { 
			TrinketKeyboard.pressKey(0,KEYCODE_1 + int(random(6)));
			delay(5);
      digitalWrite(PIN_LED,HIGH); 
			TrinketKeyboard.pressKey(0,0);
			delay(5);
	  } 
	else 
		digitalWrite(PIN_LED,LOW); 
	
}

