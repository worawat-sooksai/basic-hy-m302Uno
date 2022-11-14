
/*  
http://www.arduino.cc/en/Tutorial/Tone

*/

#include "pitches.h"

int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

// notes in the melody:
int red_light_pin= 9;
int green_light_pin = 10;
int blue_light_pin = 11;
int r=0,g=0,b=0;
long randomRED;
long randomGREEN;
long randomBLUE;
const int buzzer = 5;

String a;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(red_light_pin, OUTPUT); //d9
  pinMode(green_light_pin, OUTPUT); //d10
  pinMode(blue_light_pin, OUTPUT);//d11
  pinMode(buzzer, OUTPUT); // Set buzzer - pin d5 as an output

  

  Serial.begin(9600);
  randomSeed(42);
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(buzzer, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(buzzer);

  }   
}

void playnote(int melody[],int noteDurations[]){
  
 }
//

// the loop function runs over and over again forever
void loop() {
while(Serial.available()) {

a= Serial.readString();// read the incoming data as string

Serial.println(a);
Serial.println(__func__);
   delay(1000);

int noteDuration = 1000 / 2;
tone(buzzer, a.toInt(), noteDuration);
delay(1000);
noTone(buzzer);

}
  
  //generate a random number
//  randomRED = random(0,255);
//  randomGREEN = random(0,255);
//  randomBLUE = random(0,255);

//  tone(buzzer,1000);
//  delay(1000);        // ...for 1 sec
//  noTone(buzzer);     // Stop sound...
//  delay(1000);        // ...for 1sec
//tone(buzzer, melody[thisNote], noteDuration);
  
  //display the random number on the serial monitor
//  Serial.print("The Color is = ");
//  String r=String(randomRED),g=String(randomGREEN),b=String(randomBLUE);
//  Serial.println("("+String(randomRED)+","+String(randomGREEN)+","+String(randomBLUE)+")");
//  RGB_color(randomRED,randomGREEN,randomBLUE);
//  delay(500);
  
//  for(r=0,g=0,b=0;r<255&&g<255&&b<255;r++,g++,b++){
//    RGB_color(r,g,b);
//    delay(10);
//    }
//  for(r=255,g=0,b=0;r<255&&g<255;r--,g++){
//    RGB_color(r,g,b);
//    delay(10);
//    }
//  for(r=0,g=255,b=0;g>0&&b<255;g--,b++){
//    RGB_color(r,g,b);
//    delay(10);
//    }
// for(r=0,g=0,b=255;r<255&&b>0;r++,b--){
//    RGB_color(r,g,b);
//    delay(10);
//    }
//for(r=0,g=0,b=0;g<255&&b<255;g++,b++){
//    RGB_color(r,g,b);
//    delay(10);
//    }    

   
//  for(;g<255;g++){
//    RGB_color(r,g,b);
//    delay(10);
//    }
//    g=0;
//    
//    for(;b<255;b++){
//    RGB_color(r,g,b);
//    delay(10);
//    }
//    b=0;
    
  
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
