
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
void movimiento_ruedas(int* pins, const char* direccion) {
  //Movimiento ruedas izquierdas y derechas
    if (direccion == "avanzar") {
        for (int i = 0; i < numero_de_pines; i++) {
            if (i % 2 == 0) {
                digitalWrite(pins[i], HIGH);
            } else {
                digitalWrite(pins[i], LOW);
            }
        }
    } else if (direccion == "retroceder") {
        for (int i = 0; i < numero_de_pines; i++) {
            if (i % 2 == 0) {
                digitalWrite(pins[i], LOW);
            } else {
                digitalWrite(pins[i], HIGH);
            }
        }
    } else if (direccion == "detenerse") {
        for (int i = 0; i < numero_de_pines; i++) {
            if (i % 2 == 0) {
                digitalWrite(pins[i], LOW);
            } else {
                digitalWrite(pins[i], LOW);
            }
        }
    }
}

void avanzar() {
  movimiento_ruedas(pins_motores_izquierda, "avanzar");
  movimiento_ruedas(pins_motores_derecha, "avanzar");
}

void retroceder() {
  movimiento_ruedas(pins_motores_izquierda, "retroceder");
  movimiento_ruedas(pins_motores_derecha, "retroceder");

}

void frenar() {
  movimiento_ruedas(pins_motores_izquierda, "detenerse");
  movimiento_ruedas(pins_motores_derecha, "detenerse");

}

void girar(const char* direccion) {
  //Girar con argumento de direccion

  if (direccion == "derecha"){
    movimiento_ruedas(pins_motores_izquierda, "avanzar");
    movimiento_ruedas(pins_motores_derecha, "retroceder");
    }
  else { if (direccion == "izquierda") {
    movimiento_ruedas(pins_motores_izquierda, "retroceder");
    movimiento_ruedas(pins_motores_derecha, "avanzar");
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
