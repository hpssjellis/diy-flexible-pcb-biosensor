/*
* d-mbed-thread.ino
* For the Arduino PortentaH7
*
* GNU GENERAL PUBLIC LICENSE
* Use at your own risk.
************************************************ Important stuff if needed ****************************************
*
*
*
********************************************************** end ****************************************************
*
*/



#include "mbed.h"
#include "rtos.h"

//using namespace mbed;  // sometimes needed
using namespace rtos;

Thread thread;
int myDuration = 400;



void myLedBlue_thread(){
   while (true) {
      digitalWrite(LEDB, !digitalRead(LEDB));   //switch on / off
      ThisThread::sleep_for(myDuration);
   }
}

void setup() {
   pinMode(A1, INPUT_PULLDOWN); 
   pinMode(LEDB, OUTPUT);   // LEDB = blue, LEDG or LED_BUILTIN = green, LEDR = red 
   thread.start(myLedBlue_thread);
   Serial.begin(15200);
}

void loop() {
    int myA1 = analogRead(A1);
    Serial.println("A1: " + String(myA1));
    delay(100);
    myDuration = 1111 - myA1;   // max A1 = 1023 so this will still have a delay
}




