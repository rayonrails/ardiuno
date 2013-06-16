/* Blink
*  Turns on an LED on for one second, then off for one second,
*  repeatedly.
*  Credated 15 June 2013
*/
int ledPin  = 9; // LED connected to digital pin 13

// the setup() metho runs ones, when the sketch starts
void setup() {
  pinMode(ledPin, OUTPUT); 
}
  
// the loop() method runs over and over again.
// as long as the Arduino has power
void loop() {
  digitalWrite(ledPin, 255);
  delay(1000);
  digitalWrite(ledPin, 5);
  delay(1000);
  analogWrite(ledPin, 5);
}


