/*
   Ejercicio01 - Test del entrono de trabajo para el curso Programación con Arduino
   Web: https://www.aprendiendoarduino.com/cursos/programacion-arduino-2019/
   Montaje: https://github.com/jecrespo/aprendiendoarduino-Curso_Programacion_Arduino_2019/blob/master/Esquemas%20Montajes%20Pr%C3%A1cticas%20Fritzing/Curso_Programacion-Montaje%20Arduino_bb.png
*/

//Librerías pantalla LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


//PINES
#define PIN_BOTON_A 2
#define PIN_BOTON_B 3

int pulsos_a = 0;
int pulsos_b = 0;

//Objeto pantalla
LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  //Inicializo puerto serie
  Serial.begin(9600);

  //Inicializo Pines
  Serial.println(F("Inicializando pines digitales..."));
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);

  //Inicializo pantalla
  Serial.println(F("Inicializando pantalla..."));
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(2000);
  lcd.clear();

}

void loop() {
  //
  //    lcd.setCursor(0, 0);
  //    lcd.print("Prueba de Pantalla");
  //    lcd.setCursor(0, 1);
  //    lcd.print("Completada...");
  //
  //  }
  //  int pulsos_a = 0;
  //  int pulsos_b = 0;
  static boolean anterior_a = digitalRead(PIN_BOTON_A);
  static boolean anterior_b = digitalRead(PIN_BOTON_B);
  lcd.setCursor(0, 0);
  lcd.print("Pulsos A: ");
  lcd.print(pulsos_a);
  lcd.setCursor(0, 1);
  lcd.print("Pulsos B: ");
  lcd.print(pulsos_b);
  boolean estado_a = digitalRead(PIN_BOTON_A);
  boolean estado_b = digitalRead(PIN_BOTON_B);

  if (anterior_a != estado_a) {
    if (estado_a == LOW) {  //flanco descendente pull-up
      Serial.println(F("Pulsado boton A"));
      pulsos_a++;
      Serial.println("Numero pulsaciones boton A: " + (String)pulsos_a);
    }
  }

  if (anterior_b != estado_b) {
    if (estado_b == HIGH) {  //flanco ascendente pull-down
      Serial.println(F("Pulsado boton B"));
      pulsos_b++;
      Serial.println("Numero pulsaciones boton B: " + (String)pulsos_b);
    }
  }
  anterior_a = estado_a;
  anterior_b = estado_b;
  delay(50); //Evitar rebotes
  lcd.clear();
}
