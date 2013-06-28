/*
 * Temperature displayed on LCD
*/

const int lcdPin = 6;
const int temperaturePin = 0;

#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(255, lcdPin);

void setup() {
  pinMode(lcdPin, OUTPUT);
  digitalWrite(lcdPin, HIGH);
  //getting the voltage reading from the temperatur sensor
  float temperature = getVoltage(temperaturePin);
  //converting mv to temp
  temperature = (((temperature - .5) * 100) * 1.8) + 32;
  
  
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
  mySerial.write(12);                // Clear
  mySerial.write(17);                // Turn blackligh On
  delay(5);                          // Require delay
  mySerial.print("Loading");         // First Line
  delay(1000);
  mySerial.print(".");
  delay(1000); 
  mySerial.print(".");
  delay(1000);
  mySerial.print(".");
  delay(3000);                       // delay for 3 seconds.
  mySerial.write(219);               // Quarter Note
  mySerial.write(220);               // A tone
  mySerial.write(12);                // Clear
  mySerial.print("Temperature is");   // First Line
  mySerial.write(13);                // Form feed
  mySerial.print(temperature);       // Print Temp
}

void loop()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
  //Get temperature from Voltage
  float temperature = getVoltage(temperaturePin);
  temperature = (((temperature - .5) * 100) * 1.8) + 32;
  
  //Print Information to LCD
  mySerial.write(12);                // Clear
  mySerial.print("Temperature is");  // First Line
  mySerial.write(13);                // Form feed
  mySerial.print(temperature);       // Print Temp
  //mySerial.write(219);               // Quarter Note
  //mySerial.write(220);               // A tone
  delay(3000);  
  
}

/*
 * getVoltage() - return the voltage on the analog input defined by pin
*/
float getVoltage(int pin){
  //converiting from a 0 to 1023 digital range
  // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
  return (analogRead(pin) * .004882814);
  
  //Clear LCD
  mySerial.write(12);
  mySerial.write(219);               // Quarter Note
  mySerial.write(220);              // A tone
  
}

  
