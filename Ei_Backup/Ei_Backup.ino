#include "Arduino.h"
#include "Keypad.h"

#define EnA 11
#define In1 10
#define In2 12

// Keypad
const byte ROWS = 4; // vier Reihen
const byte COLS = 4; // vier Spalten
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Pins fuer die Reihen
byte colPins[COLS] = {5, 4, 3, 2}; // Pins fuer die Spalten
char Eingabe[4];
int counter = 0;
int code = 0;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



void setup() {
  Serial.begin(9600);
  pinMode(EnA, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
}


void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    Eingabe[counter] = key;
    counter++;
    Serial.println(Eingabe);
    if (counter == 4) {
      if ((Eingabe[0] == '1') && (Eingabe[1] == '3') && (Eingabe[2] == '3') && (Eingabe[3] == '7')) {
        Serial.println("Richtig");
        bewegung();
      }
      else {
        Serial.println("Falsch");
      }
//      Serial.println(sizeof(Eingabe));
//      for (int i = 0; i < 4; i++) {
//        Eingabe[i] = ' ';
//      }
      counter = 0;
    }
  }
}

void bewegung(){
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(EnA, 200);
  delay(4000);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  delay(4000);
  digitalWrite(In2, LOW);
  }
