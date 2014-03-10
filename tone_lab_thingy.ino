/*

Combination of code from both the tone and button tutorials
rewritten so that the arduino plays happy birthday when a  button i
 http://arduino.cc/en/Tutorial/Tone
 
 */
 #include "pitches.h"
const int buttonPin = 2;
int buttonState = 0;

int melody[] = {
  NOTE_C2, NOTE_C2,NOTE_D2, NOTE_C2, NOTE_F2, NOTE_E2 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 4, 4,4,2};

void setup() {
  
  pinMode(buttonPin, INPUT); 
  
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) { // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
   noTone(8);
  } }
  else {noTone(8);}
}
