/*
 * Temperature
*/

//TMP36 Pin Variables
//the analog pin the TMP36's Vout (sense) Pin is connected to
//the resoluation is 10mV / degree centigrade
//(500 mV offset) to make negative temp an option
int temperaturePin = 0;

void setup()
{
  //Start the serial connection with the computer
  //to view results open the serial monitor
  //last button beneath the file bar (looks like a box with an antenea)
  Serial.begin(9600);
}

void loop()
{
  //getting the voltage reading from the temperatur sensor
  float temperature = getVoltage(temperaturePin);
  //converting from 10 mv per degree wit 500 mV offset
  //temperature = (temperature - .5) * 100;
  //to degrees ((volate - 500mv) times 100)
  //print the result
  //waiting a second
  temperature = (((temperature - .5) * 100)*1.8) + 32;
  Serial.println(temperature);
  delay(1000);
}

/*
 * getVoltage() - return the voltage on the analog input defined by pin
*/
float getVoltage(int pin){
  //converiting from a 0 to 1023 digital range
  // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
  return (analogRead(pin) * .004882814);
}
