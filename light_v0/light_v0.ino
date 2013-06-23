/*
 * A simple program that changes the intensity of 
 * the LED base * on the amount of light incident on 
 * the photo resistor.
*/

//PhotoResistor Pin
  //the analog pin the photoresistor is connected to
  //the photoresistor is not calibrated to any units so
  //this is simply a raw sensor value (relative light)
  int lightPin = 0;
//LED Pin
  //the pin the LED is connected to
  //we are controlling brightness so
  //we use one of the PWM (pulse width modulation pins)
int ledPin = 9;

void setup()
{
  pinMode(ledPin, OUTPUT); //sets the led pin to output
}

void loop()
{
  // Read the lightlevel
  int lightLevel = analogRead(lightPin); 
  //adjust the value 0 to 900 to span 0 to 255
  lightLevel = map(lightLevel, 0, 900, 0, 255);
  //make sure the value is between 0 and 155
  lightLevel = constrain(lightLevel, 0, 255);
  //write the value
  analogWrite(ledPin, lightLevel);
}
  
