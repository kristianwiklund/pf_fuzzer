#include <TrinketHidCombo.h>
#include <TrinketHidComboC.h>

/*
TrinketHidCombo example
For Trinket by Adafruit Industries
*/


#define PIN_BUTTON_CAPITAL_A 4
#define PIN_LED 3
void setup()
{
  // button pins as inputs
  pinMode(PIN_BUTTON_CAPITAL_A, INPUT);
  pinMode(PIN_LED,OUTPUT);
  
  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(PIN_BUTTON_CAPITAL_A, HIGH);
  //digitalWrite(PIN_BUTTON_STRING, HIGH);
  // remember, the buttons arusbReportSende active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketHidCombo.begin();
}
char old=HIGH;
bool muted=false;

extern uint8_t report_buffer[];
void usbReportSend(uint8_t);

void sendmicmute(uint8_t x) {
  report_buffer[0]=8;
  report_buffer[1]=x;
  report_buffer[2]=0;
  report_buffer[3]=0;

  usbReportSend(4);

}

void loop()
{
  char nnew;
  
  TrinketHidCombo.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors

  nnew = digitalRead(PIN_BUTTON_CAPITAL_A);

  if (old != nnew)
  {
    old = nnew;
    if (nnew == LOW) {
        if(!muted) 
        sendmicmute(4);
            else
        sendmicmute(0);
       
  muted=!muted;
    digitalWrite(PIN_LED,muted);
    delay(5);
    }
    // this releases the key
  }
}
