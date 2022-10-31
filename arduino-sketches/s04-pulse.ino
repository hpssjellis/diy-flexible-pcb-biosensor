
int myDelay = 1000;   // non-block delay in milliseconds
unsigned long myStart; 
bool  mySwitch = false; 

void setup() {
   myStart = millis();   // set delay
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(A0, INPUT);
   Serial.begin(115200);
}

void loop() {
    int myA0 = analogRead(A0);
    Serial.println(myA0);
   // myDelay = 1111 - myA0;   // myA0 max is 1024 so this always has some value.
    delay(10);  // just to slow it down a bit
    
    if ( (millis() - myStart ) >= myDelay) {       
       myStart = millis();      //  reset the delay time
       mySwitch = !mySwitch;    // flip the switch true <--> false
       digitalWrite(1, mySwitch);
       delayMicroseconds(200);
       digitalWrite(1, !mySwitch);
    }
    
    // this should flip the LED on and off
    digitalWrite(LED_BUILTIN, mySwitch);
}
