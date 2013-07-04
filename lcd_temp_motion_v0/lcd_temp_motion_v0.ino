/*
 *
 * Outputs to Display - that motion was detected and temperature
 * 
*/
#include <SoftwareSerial.h>

//Setup Motion sensor
//CalibrationTime
int calibrationTime = 30;
//LCD Pin

//the time when the sensor outputs a low impulse
long unsigned int lowIn;

//the amount of milliseconds the senor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000;

boolean lockLow = true;
boolean takeLowTime;

//Pins Setup
//Digital LCD Pin
const int lcdPin = 8;
SoftwareSerial mySerial = SoftwareSerial(255, lcdPin);

//Analog Temp Pin
const int tempPin = 0;

//Digital Motion Pin
int pirPin = 3;

///////////////////////////////////////////////////
//Setup

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(pirPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  
  //Display Loading on LCD
  mySerial.begin(9600);
  
  delay(100);
  //Clear LCD
  mySerial.write(12);
  //Turns blacklight on
  mySerial.write(17);
  //Require delay
  delay(5);
  mySerial.print("Loading...");
  delay(1000);
  mySerial.write(12);
  delay(5);
  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
  mySerial.print("Calibrating Senor");
    for(int i = 0; i < calibrationTime; i++){
      mySerial.write(12);
      mySerial.print("Calibrating...");
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    mySerial.write(12);
    mySerial.print("SENSOR ACTIVE");
    mySerial.write(13);

    delay(50);  
}

void loop(){
  if(digitalRead(pirPin) == HIGH){
    mySerial.write(12);
    if(lockLow){
      lockLow = false;
      Serial.println("---");
      Serial.print("motion detected at ");
      Serial.print(millis()/1000);
      Serial.println(" sec");
      delay(50);
    }
    takeLowTime = true;
  }
  
  if(digitalRead(pirPin) == LOW){
    mySerial.write(12);
    if(takeLowTime){
      lowIn = millis();
      takeLowTime = false;
    }
    
    if(!lockLow && millis() - lowIn > pause){
      lockLow = true;
      Serial.print("motion ended at ");
      Serial.print((millis() - pause)/1000);
      Serial.println(" sec");
      delay(50);
    }
  }
}

