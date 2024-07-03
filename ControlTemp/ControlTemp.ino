#include "OneWire.h"
#include "DallasTemperature.h"

#define temperatura 16 //pin Sensor de temperatura
#define luz 13 //pin de la luz

float temp_des=23;//temperatura deseada
float temp;//variable para registrar la temperatura

OneWire onewire(temperatura);
DallasTemperature sensor(&onewire);

void setup() {
  Serial.begin(115200);
  sensor.begin();
  pinMode(luz,OUTPUT);
}

void loop() {
  sensor.requestTemperatures();//pedir temperaturas al sensor
  temp=sensor.getTempCByIndex(0);
  Serial.println(temp);//mostrar la temperatura
  if(temp_des>temp){//si la temperatura actual es menor a la que se desea se enciende la luz
    digitalWrite(luz,LOW);
  }else{//si la temperatura actual es mayor la luz se apaga
    digitalWrite(luz,HIGH);
  }
}
