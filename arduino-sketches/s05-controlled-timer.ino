
int myPlotterDelay = 5;   // non-block delay in milliseconds
unsigned long myPlotterStart; 


int myActivateDelay = 2000;   // non-block delay in milliseconds
unsigned long myActivateStart; 

int myStopDelay = 500;   // non-block delay in milliseconds
unsigned long myStopStart; 

bool  mySwitch = false; 

void setup() {
   myPlotterStart  = millis();   
   myActivateStart = millis();   // could use micros()
   myStopStart    = millis();    
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(1, OUTPUT);  // A1
   pinMode(0, INPUT);   // A0
   Serial.begin(115200);
}

void loop() {
   
    if ( (millis() - myActivateStart ) >= myActivateDelay) {       
       myActivateStart = millis();      //  reset the delay time
       mySwitch = true;    
       digitalWrite(1, HIGH);      
       digitalWrite(LED_BUILTIN, LOW);  // LOW sets onboard LED on
       myStopStart = millis();          //  reset the stop delay time 
    }


    if ( (millis() - myStopStart ) >= myStopDelay) {       
       myStopStart = millis();      //  reset the delay time
       if (mySwitch) {     
       digitalWrite(1, LOW);     
       digitalWrite(LED_BUILTIN, HIGH);  // HIGH sets onboard LED off
       mySwitch = false;
       }
    }

    

    // only reads the sensor at a preset interval
    if ( (millis() - myPlotterStart ) >= myPlotterDelay) {       
       myPlotterStart = millis();      //  reset the delay time
       int myA0 = analogRead(A0);
       Serial.println(myA0);
    }

}
