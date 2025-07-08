#include <Arduino.h>
 
#define LED_PIN 6
#define BUTTON_PIN 2
 
int ledState = LOW; // Initial state of the LED
 
void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
}
 
void loop() {
  // Constantly check the button's state
  int newState = digitalRead(BUTTON_PIN);
 
  // If the state has changed...
  if(newState != ledState) {
    if(newState == HIGH) {
      Serial.println("The button is pressed.");
    } else {
      Serial.println("The button is released.");
    }
    // Remember the value and update the LED
    ledState = newState;
    digitalWrite(LED_PIN, ledState);
  }
  // A small delay for debouncing
  delay(100); 
}