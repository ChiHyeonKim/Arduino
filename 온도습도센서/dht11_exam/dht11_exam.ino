#include "DHT11.h"
DHT11 dht11(4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp, humidity;
  int error = dht11.read(humidity, temp);

  if(error == 0){
    Serial.print("temp:"); 
    Serial.println(temp);
    Serial.print("humidity");
    Serial.println(humidity);
  }

  delay(1000);
}
