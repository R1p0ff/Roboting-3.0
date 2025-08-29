#include <Arduino.h>

int motorPins[] = {
  16, 17, //motor1_pin1, motor1_pin2
  18, 19, //motor2_pin1, motor2_pin2
  15, 4, //motor3_pin1, motor3_pin2
  0, 2, //motor4_pin1, motor4_pin2
  
}; // todos los pines que usarás
int numPins = sizeof(motorPins) / sizeof(motorPins[0]);

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(motorPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numPins; i++) {
    if (i % 2 == 0) {        // índice impar
      digitalWrite(motorPins[i], LOW);
    }
    else {        // índice impar
      digitalWrite(motorPins[i], HIGH);
    }
  }
  delay(1000);
  for (int i = 0; i < numPins; i++) {
    if (i % 2 == 1) {        // índice impar
      digitalWrite(motorPins[i], LOW);
    }
    else {        // índice impar
      digitalWrite(motorPins[i], HIGH);
    }
  }
  delay(1000);
}
