#include <Arduino.h>

int pins_motores_izquierda[] = {
  19, 18, //motor1_pin1, motor1_pin2
  2, 0, //motor2_pin1, motor2_pin2
};

int pins_motores_derecha[] = {
  17, 16, //motor3_pin1, motor3_pin2
  4, 15, //motor4_pin1, motor4_pin2
};

//Se asume que izquierda y derecha tienen la misma cantidad de motores
int numero_de_pines = sizeof(pins_motores_izquierda) / sizeof(pins_motores_izquierda[0]);

// funciones
//Movimiento ruedas derechas
void movimiento_ruedas_izquierda(const String& direccion) {
    if (direccion == "avanzar") {
        for (int i = 0; i < numero_de_pines; i++) {
            if (i % 2 == 0) {
                digitalWrite(pins_motores_izquierda[i], HIGH);
            } else {
                digitalWrite(pins_motores_izquierda[i], LOW);
            }
        }
    } else if (direccion == "retroceder") {
        for (int i = 0; i < numero_de_pines; i++) {
            if (i % 2 == 0) {
                digitalWrite(pins_motores_izquierda[i], LOW);
            } else {
                digitalWrite(pins_motores_izquierda[i], HIGH);
            }
        }
    } else if (direccion == "detenerse") {
        for (int i = 0; i < numero_de_pines; i++) {
            if (i % 2 == 0) {
                digitalWrite(pins_motores_izquierda[i], LOW);
            } else {
                digitalWrite(pins_motores_izquierda[i], LOW);
            }
        }
    }
}


void movimiento_ruedas_derecha(const String& direccion) {
    if (direccion == "avanzar") {
        for (int i = 0; i < numero_de_pines; i++) {
            if (i % 2 == 0) {
                digitalWrite(pins_motores_derecha[i], HIGH);
            } else {
                digitalWrite(pins_motores_derecha[i], LOW);
            }
        }
    } else if (direccion == "retroceder") {
        for (int i = 0; i < numero_de_pines; i++) {
            if (i % 2 == 0) {
                digitalWrite(pins_motores_derecha[i], LOW);
            } else {
                digitalWrite(pins_motores_derecha[i], HIGH);
            }
        }
    } else if (direccion == "detenerse") {
        for (int i = 0; i < numero_de_pines; i++) {
            if (i % 2 == 0) {
                digitalWrite(pins_motores_derecha[i], LOW);
            } else {
                digitalWrite(pins_motores_derecha[i], LOW);
            }
        }
    }
}


void setup() {
  for (int i = 0; i < numero_de_pines; i++) {
    pinMode(pins_motores_izquierda[i], OUTPUT);
    pinMode(pins_motores_derecha[i], OUTPUT);
  }
}


void loop() {
  //Avanzar
  movimiento_ruedas_izquierda("avanzar");
  movimiento_ruedas_derecha("avanzar");

  delay(1000);
  //Frenar
  movimiento_ruedas_izquierda("detenerse");
  movimiento_ruedas_derecha("detenerse");

  //Retroceder
  delay(1000);
  movimiento_ruedas_izquierda("retroceder");
  movimiento_ruedas_derecha("retroceder");

  //Frenar
  delay(1000);
  movimiento_ruedas_izquierda("detenerse");
  movimiento_ruedas_derecha("detenerse");

  //Giro hacia la derecha
  delay(1000);
  movimiento_ruedas_izquierda("avanzar");
  movimiento_ruedas_derecha("retroceder");


  //Giro hacia la derecha
  delay(1000);
  movimiento_ruedas_izquierda("retroceder");
  movimiento_ruedas_derecha("avanzar");

  delay(1000);
}
