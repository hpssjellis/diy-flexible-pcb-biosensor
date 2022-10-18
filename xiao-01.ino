#include <TimerTC3.h>


bool isLEDOn = false;
char time = 0;
int myOld =0;
int myNew = 0;
int myPlusMinusAcceptable = 20;

void setup() 
{
    SerialUSB.begin(115200);
    //while(!SerialUSB);
    
    pinMode(13, OUTPUT);    

    TimerTc3.initialize(1000000);
    TimerTc3.attachInterrupt(timerIsr);
}
 
void loop()
{
     myNew = analogRead(0);
     if (myNew > myOld - myPlusMinusAcceptable && myNew < myOld + myPlusMinusAcceptable){      
       // Serial.print(".");
      //  delay(100);
      // it didn't change
     }
      else {
        Serial.println();
        Serial.println("A0:"+String(myNew));
       // delay(100);  
    }
    delay(50);  
    myOld = myNew;
    /*
    time ++;
    if(time == 10)TimerTc3.detachInterrupt();
    else if(time == 20)
    {
       TimerTc3.attachInterrupt(timerIsr);
       time = 0;
    }
    delay(1000);
    */
}

void timerIsr()
{    
    digitalWrite(13, isLEDOn);
   // delay(myOld);
    isLEDOn = !isLEDOn;
}
