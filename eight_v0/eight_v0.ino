  /*
  *
  *  A few Simple LED animations
  *  
  */

  //LED Pin Variables
  int ledPins[] = {2,3,4,5,6,7,8,9}; //An array to hold the pin each LED is connected to
                                 //i.e. Led #0 is connected to pin 2, LED #1, 3 and so on
                                 //to address an array use ledPins[0] this would equal 2
                                 //and ledPins[7] would equal 9

  /*
  * setup() - this function runs once when you turn your Arduino on
  * We the three control pinis to outputs
  */
  
  void setup(){
  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
    for(int i = 0; i < 8; i++){        //this is a loop and will repeat eight times
      pinMode(ledPins[i],OUTPUT);      //we use this to set each LED pin to output
    }                                  //the code this replaces is below 
   }

  /*
  * oneAfterAnotherNoLoop() - Will light one led then delay for delayTime then light
  * the next LED until all LEDs are on it will then turn off one after another
  *
  * this does it without using a loop makes for a lot of typing.
  * oneOnAtATimeLoop() does exactly the same thing with less typing
  */
  void loop()
  {
    oneAfterAnotherNoLoop();
  }
  void oneAfterAnotherNoLoop(){
    int delayTime = 100;

    digitalWrite(ledPins[0], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[1], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[2], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[3], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[4], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[5], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[6], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[7], HIGH);
    delay(delayTime);

    //Turns Each LED off
    digitalWrite(ledPins[7], LOW);      
    delay(delayTime);
    digitalWrite(ledPins[6], LOW);
    delay(delayTime);
    digitalWrite(ledPins[5], LOW);
    delay(delayTime);
    digitalWrite(ledPins[4], LOW);
    delay(delayTime);
    digitalWrite(ledPins[3], LOW);
    delay(delayTime);
    digitalWrite(ledPins[2], LOW);
    delay(delayTime);
    digitalWrite(ledPins[1], LOW);
    delay(delayTime);
    digitalWrite(ledPins[0], LOW);
    delay(delayTime);    
  }

  void oneAfterAnotherLoop(){
    int delayTime = 100;
    for (int i = 0; i <= 7; i++){
      digitalWrite(ledPins[i], HIGH);
      delay(delayTime);
    }

    for(int i = 7; i>= 0; i--){
      digitalWrite(ledPins[i], LOW);
      delay(delayTime);
     }
  }
