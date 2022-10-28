
int myDelay = 2000;   // non-block delay in milliseconds
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
    Serial.println("A0: " + String(myA0));
    myDealy = 1111 - myA0;   // myA0 max is 1024 so this always has some value.
    
    if ( (millis() - myStart ) >= myDelay) {       
       myStart = millis();      //  reset the delay time
       mySwitch = !mySwitch;    // flip the switch ture <--> false
    }
    
    if (mySwitch){
       digitalWrite(LED_BUILTIN, LOW); //  onboard LED on 
    } else {
       digitalWrite(LED_BUILTIN, HIGH); // onboard LED off
    }

}
