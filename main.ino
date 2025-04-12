#include "max6675.h"
#include "AVR_PWM.h"


int thermoDO = 50;
int thermoCS = 22;
int thermoCLK = 52;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);





void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
Serial.println("Main code:");
PWM_Instance = new AVR_PWM(pinToUse, 20000, 0);
Serial.println("---AVR PWM SET---");
lcd.init();         // initialize the lcd
lcd.backlight();    // Turn on the LCD screen backlight
delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = thermocouple.readCelsius();
  Serial.println(temp);
if (temp > 32) {
frequency = 20;    //20000;
  dutyCycle = 10;     //90;

  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
}
else{
  frequency = 20;    //20000;
  dutyCycle = 90;     //90;

  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
}
lcd.setCursor(7,0);
lcd.print(string(temp));
delay(10000);
}
