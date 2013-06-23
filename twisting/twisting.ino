/*
 * Anaglog Input
 * Potentiometer attached to analog input 0
 * center pin of the potentometer to the analog pin
 * one side pin to +5v
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short let) attached to ground
 * Note: becuase most Arduinos have built in LED attached
 * to pin 13 on the board, the LED is optional. 
*/

int sensorPin = 0;          //select the input pin for the potentiometer
int ledPin = 9;            //select the pin for the LED
int sensorValue = 0;        // variable store the value coming from the sensor

void setup()
{
  //declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  //int threshold = 512;
  //if(analogRead(sensorPin) > threshold) {
  //  digitalWrite(ledPin, HIGH);
  //} else {
  //  digitalWrite(ledPin, LOW);
  //}
  //int value = analogRead(sensorPin) / 4;
  //analogWrite(ledPin, value);
    
    
    
  // read the value from the senor:
  sensorValue = analogRead(sensorPin);
  // then the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for millionseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for milliseconds
  delay(sensorValue);
}
