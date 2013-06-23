/*
* The Arduinos pins are great for driving LEDs however if you hook
* up something that requires more power you will quickly break them
* To control bigger items we need the help of a transistor.
* Here we will use a transister to control a small toy moter
*/

  int motorPin = 9; // defind the pin the moter is connected to
                    // (if you use pin 9,10,11 or 3 you can also control speed)
  
  void setup()
  {
    pinMode(motorPin, OUTPUT);
  }
  
  void loop()
  {
    //motorOnThenOff();
    motorOnThenOffWithSpeed();
    //motorAcceleration();
  }
  
  /* motorOnThenOff() - turns motor on then off
  *  (notice this code is identical to the code we used for
  *  the blinking LED)
  */
  
  void motorOnThenOff(){
    int onTime = 2500;   //the number of millionseconds for the motor to turn on for
    int offTime = 1000; // the number of millionseconds for the motor to turn off for;
    
    digitalWrite(motorPin, HIGH);
    delay(onTime);
    digitalWrite(motorPin, LOW);
    delay(onTime);
  }
  
  /* motorOnThenOffWithSpeed() - turn motor on then off but uses speed values asl well
  *  (notice this code is identical to the code we used for
  *  the blinking LED)
  */
  
  void motorOnThenOffWithSpeed()
  {
    int onSpeed = 200;    //a number between 0 (stopped) and 255 (full speed)
    int onTime = 2500;    //the number of millionseconds for the moter to turn on for
  
    int offSpeed = 50;    //a number between 0 (stopped) and 255 (full speed)
    int offTime = 1000;  //the number of millionseconds for the motor to turn off for
  
    analogWrite(motorPin, onSpeed);      // turns the motor on
    delay(onTime);                       // waits for onTime millionseconds
    analogWrite(motorPin, offSpeed);    // turns motor off
    delay(offTime);                       // waits for offTime millionseconds
  }
  
  
  /* motorAcceleration() - accelerates the motor to full speed then
  *  back down to zero
  */
  
  void motorAcceleration()
  {
    int delayTime = 50; //millionseconds between each speed step
    
    //Accelerates the motor
    for (int i = 0; i < 256; i++)  //goes through each speed from 0 to 255
    {  
      analogWrite(motorPin, i);    //sets the new speed
      delay(delayTime);            //waits for delayTime millionseconds
    }
  }
