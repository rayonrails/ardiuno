/*
*  We are only using three pins and an additional chip to 
*  lightup the LEDs
*/

//Pin Definitions
//Pin Definitions
//The 74HC595 uses a serial communication
//link which has three pins
int data = 2;
int clock = 3;
int latch = 4;

//Used for single LED manipulation
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

/*
 *  setup()
*/
void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
}

/*
 * loop() - we set which LEDs we want on then call a routine which
 * send the states to the 74HC593
*/
void loop()
{
  int delayTime = 100; //the number of milliseconds to delay between LED upates
  for(int i = 0; i < 8; i++){
    changeLED(i, ON);
    delay(delayTime);
  }
  for(int i = 0; i < 8; i++){
    changeLED(i,OFF);
    delay(delayTime);
  }

  //for(int i = 0; i < 256; i++){
  //  updateLEDs(i);
  //  delay(delayTime);
  //}
}

/*
 * updateLEDs - sends the LED state in ledStates to the 74HC595
*/

void updateLEDs(int value)
{
  digitalWrite(latch, LOW);                //Pulls the chip latch low
  shiftOut(data, clock, MSBFIRST, value);  //Shifts out the 8 bigs to the shift register
  digitalWrite(latch, HIGH);               //Pulls the latch high displaying the data
}

/*
 * updateLEDsLong() - sends the LED states set in ledStates to the 74HC595 sequence
*/
void updateLEDsLong(int value){
  digitalWrite(latch, LOW);     //  Pulls the chips latch low
  for(int i = 0; i < 8; i++)
  {                             //  Will repeat 8 times (once for each bit)
    int bit = value & B10000000;  //  We use a "bitmask" to select only the eighth
                                //  bit in our number (the one we are addresing this time through
    value = value << 1;           //  we move our number up one bit value so next time bit 7 will be bit 8
                                //  and and we will do our match on it
    if (bit == 128){digitalWrite(data, HIGH);}  //  if bit 8 is set then set our data pin high
    else{digitalWrite(data, LOW);}              //  if bit 8 is unset then set the data pin low
    digitalWrite(clock, HIGH);                  //  the next three lines pulse then clock pin
    delay(1);
    digitalWrite(clock, LOW);
  } 
  digitalWrite(latch, HIGH);                    //pulls the latch high shifting our data into being displayed
}

//These are used in the bitwise math that we use to change individual LEDS
//For more details http://en.wikipedia.org/wiki/Bitwise_operation
int bits[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
int masks[] = {B11111110, B11111101, B11111011, B11110111, B11101111, B11011111, B10111111, B01111111};

/*
 * changeLED(int led, int state) - changes an individual LED
 * LEDs are 0 to 7 and state is either 0 - OFF or 1 - ON
*/
void changeLED(int led, int state){
  ledState = ledState & masks[led];                   //clears ledState of the bit we are adderssing
  if(state == ON) {ledState = ledState | bits[led];}  //if the bit is on we will add it to ledState
  updateLEDs(ledState);                               //send the new LED state to the shift register
}
                                
                                
