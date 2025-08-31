#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

int anillo1_pin = 4;
int anillo2_pin = 5;
int pins_motores_izquierda[] = {
  26, 32, //motor1_pin1, motor1_pin2
};
int pins_motores_derecha[] = {
  27, 33, //motor3_pin1, motor3_pin2
};
int numero_de_pines = sizeof(pins_motores_izquierda) / sizeof(pins_motores_izquierda[0]);

Adafruit_NeoPixel anillo1(16, anillo1_pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel anillo2(16, anillo2_pin, NEO_GRB + NEO_KHZ800);

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
  anillo1.begin();
  anillo2.begin();
}


void loop() {
  anillo1.fill(anillo1.Color(0, 0, 255));
  anillo2.fill(anillo2.Color(255, 0, 0));
  anillo1.show();
  anillo2.show();
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
