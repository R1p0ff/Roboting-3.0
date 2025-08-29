
#include <Arduino.h>

int pins_motores_izquierda[] = {
  19, 18, //motor1_pin1, motor1_pin2
};

int pins_motores_derecha[] = {
  17, 16, //motor3_pin1, motor3_pin2
};

//Se asume que izquierda y derecha tienen la misma cantidad de motores
int numero_de_pines = sizeof(pins_motores_izquierda) / sizeof(pins_motores_izquierda[0]);

//Funciones
  //Movimiento ruedas derechas
void movimiento_ruedas_izquierda(const char* direccion) {
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
  //Movimiento ruedas izquierdas
void movimiento_ruedas_derecha(const char* direccion) {
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
  //Avanzar
void avanzar() {
  movimiento_ruedas_izquierda("avanzar");
  movimiento_ruedas_derecha("avanzar");
}
  //Retrocerder
void retroceder() {
  movimiento_ruedas_izquierda("retroceder");
  movimiento_ruedas_derecha("retroceder");

}
  //Frenar
void frenar() {
  movimiento_ruedas_izquierda("detenerse");
  movimiento_ruedas_derecha("detenerse");

}
  //Girar con argumento de direccion
void girar(const char* direccion) {
  if (direccion == "derecha"){
    movimiento_ruedas_izquierda("avanzar");
    movimiento_ruedas_derecha("retroceder");
    }
  else { if (direccion == "izquierda") {
    movimiento_ruedas_izquierda("retroceder");
    movimiento_ruedas_derecha("avanzar");
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
  avanzar();
  delay(1000);
  
  //Frenar
  frenar();
  delay(1000);
  
  //Retroceder
  retroceder();
  delay(1000);

  //Frenar
  frenar();
  delay(1000);
  
  //Giro hacia la derecha
  girar("derecha");
  delay(1000);

  //Giro hacia la izquierda
  girar("izquierda");
  delay(1000);
}
