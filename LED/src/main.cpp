#include <Arduino.h>

int redLED = D1;
int yellowLED = D6;
int greenLED = D8;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  digitalWrite(redLED, HIGH);
  delay(5000); //ms
  digitalWrite(redLED, LOW);

  digitalWrite(yellowLED, HIGH);
  delay(1000); //ms
  digitalWrite(yellowLED, LOW);

  digitalWrite(greenLED, HIGH);
  delay(3000); //ms
  digitalWrite(greenLED, LOW);
}