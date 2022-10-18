


bool isLEDOn = false;
char time = 0;
int myOld =1000;
int myNew = 0;
int myPlusMinusAcceptable = 20;
int myDelay;
float myMath = 0.0;

void setup() 
{
    SerialUSB.begin(115200);
    //while(!SerialUSB);
    
    pinMode(13, OUTPUT);    

}
 
void loop()
{
     myMath = (300000000.0 / (myOld*myOld));
     myDelay = (int)myMath;
     myNew = analogRead(0);
     if (myNew > myOld - myPlusMinusAcceptable && myNew < myOld + myPlusMinusAcceptable){      
       // Serial.print(".");
      // it didn't change
     }
      else {
       // Serial.println();
       // Serial.println("A0:"+String(myNew)+", delay: "+String(myMath)+ ", myOld: "+ String(myOld));
    }
    digitalWrite(13, isLEDOn);
    isLEDOn = !isLEDOn;
    delay(myDelay);  
    myOld = myNew;

}

