const int TxPin = 8;

#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(255, TxPin);

void setup() {
    
  pinMode(TxPin, OUTPUT);
  digitalWrite(TxPin, HIGH);
  
  mySerial.begin(9600);
  delay(100);
  mySerial.write(12);                 // Clear             
  mySerial.write(17);                 // Turn backlight on
  delay(5);                           // Required delay
  mySerial.print("Hello, world...");  // First line
  mySerial.write(13);                 // Form feed
  mySerial.print("Arduino");   // Second line
  mySerial.write(219);                // Quarter note
  mySerial.write(220);                // A tone
  delay(3000);                        // Wait 3 seconds
  //mySerial.write(18);                 // Turn backlight off

}

void loop() {
}
