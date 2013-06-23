
/* This example uses a piezo speaker to play melodies.  It sends
 * a square wave of the appropriate frequency to the piezo, generating
 * the corresponding tone.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note 	frequency 	period 	timeHigh
 * c 	        261 Hz 	        3830 	1915 	
 * d 	        294 Hz 	        3400 	1700 	
 * e 	        329 Hz 	        3038 	1519 	
 * f 	        349 Hz 	        2864 	1432 	
 * g 	        392 Hz 	        2550 	1275 	
 * a 	        440 Hz 	        2272 	1136 	
 * b 	        493 Hz 	        2028	1014	
 * C	        523 Hz	        1912 	956
 *
 * http://www.arduino.cc/en/Tutorial/Melody
 */
    
int speakerPin = 8;

int length = 295; // the number of notes
char notes[] = "EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb  GNFR E uaC aCD GNFR E 1 11   GNFR E uaC aCD L  D C   CC C CD EC ag  CC C CDE  CC C CD EC ag  EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb EC g u aF Fa  bAAAGFEC ag  EC g u aF Fa  bF FFEDCe ec  "; // a space represents a rest
float beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, //Page 1
                2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 4, //Page 2
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, //Page4
                1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, //Page 5
                1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1.3, 1.3, 1.3, 1, 1, 1, 1, 1, 1, 2 }; //Page 6
                
int tempo = 95;

void playTone(int ton1, int duration) {
  for (long i = 0; i < duration * 1000L; i += ton1) {
    tone(speakerPin, ton1);
    delayMicroseconds(ton1);
  }
  noTone(speakerPin);
}

void playNote(char note, int duration) {
//                        c    c#   d    d#   e    f    f#   g    g#   a    a#   b
  char names[] = { ' ',  '!', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'i', 'N', 'R', 'u',  '1', 'L', 'k'}; // [i = b flat] [N = G flat] [R = D#] [u = g#] [1 = C oct. 5] [L = E flat]
  int tones[] =  {   0, 1046, 138, 146, 155, 164, 174, 184, 195, 207, 220, 233, 246, 261, 293, 329, 349, 391, 440, 493, 523, 587, 659, 698, 783, 880, 987, 466, 740, 622, 415, 1046, 622u, 227};
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 34; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    
    // pause between notes
    delay(tempo / 2); 
  }
}
