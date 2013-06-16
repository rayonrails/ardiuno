/* Blink
*  Turns on an LED on for one second, then off for one second,
*  repeatedly.
*  Credated 15 June 2013
*/
int ledPin  = 9; // LED connected to digital pin 13

// the setup() metho runs ones, when the sketch starts
void setup() {
 // nothing happens in Setup
}
  
// the loop() method runs over and over again.
// as long as the Arduino has power
void loop() {
  for(int fadeValue = 0; fadeValue <= 255; fadeValue += 5){
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  
  // fade out from max to min in increments of 5 points
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
   // sets the value (range from 0 to 255)
  analogWrite(ledPin, fadeValue);
 // wait for 30 milliseconds to see the dimming effect
 delay(30);
  } 
}


