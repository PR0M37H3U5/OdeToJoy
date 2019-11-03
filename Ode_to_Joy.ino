int speakerPin = 9;

int length = 15; //the number of notes
char notes[]= "eefggfedccdeedd"; // a space represents a rest
float beats[]= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0.5, 1};
int tempo = 300;

void playTone(int tone, int duration){
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration){
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    delay(tempo / 2);
  }
}

   
  

