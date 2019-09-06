#define PIN_LDR A1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int maximo = 0;
int minimo = 1023;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int sensorValue = analogRead(PIN_LDR);
  maximo = max(maximo,sensorValue);
  minimo = min(minimo,sensorValue);
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.print(maximo);
  Serial.print(",");
  Serial.println(minimo);

  //lcd.init();
  //lcd.init();
  //lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Max: ");
  lcd.print(maximo);
  lcd.setCursor(0,1);
  lcd.print("Min: ");
  lcd.print(minimo);
  delay(100);
  lcd.clear(); //ESTA LINEA HACÍA QUE NO ME FUNCIONARA EL PROGRAMA
 /*La linea anterior hacia que no funcionara porque estaba antes del delay
 * y limpiaba la pantalla primero y hacia el delay después
 */

}
