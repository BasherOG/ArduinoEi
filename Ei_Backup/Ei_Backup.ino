#include "Arduino.h"
#include "Keypad.h"
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
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Motor
int GSM1 = 12;
int in1 = 11;
int in2 = 10;


void setup() {
  Serial.begin(9600);
  pinMode(GSM1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}


  digitalWrite(in1, HIGH);  // Motor 1 beginnt zu rotieren
  digitalWrite(in2, LOW);

  analogWrite(GSM1, 200);   // Motor 1 soll mit der Geschwindigkeit "200" (max. 255) rotieren
void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    Eingabe[counter] = key;
    counter++;
    Serial.println(Eingabe);
    if (counter == 4) {
      if ((Eingabe[0] == '1') && (Eingabe[1] == '3') && (Eingabe[2] == '3') && (Eingabe[3] == '7')) {
        Serial.println("Richtig");
      }
      else {
        Serial.println("Falsch");
      }
      Serial.println(sizeof(Eingabe));
      for (int i = 0; i < 4; i++) {
        Eingabe[i] = ' ';
      }
      counter = 0;
    }
  }

}
