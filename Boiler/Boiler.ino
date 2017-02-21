#include <SoftwareSerial.h>
#include "DHT11.h"

DHT11 dht11(4);
SoftwareSerial btSerial(2, 3);

int power = 0, heat = 0, buzer = 0; //POWER 0 : OFF, 1 : ON. HEAT 0: NANBANG, 1 : HOT WATER 
void setup() {
  // put your setup code here, to run once: 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

   Serial.begin(9600);
  btSerial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(btSerial.available() ){
    char ch = btSerial.read();

    //CLICK POWER ON
    if( ch == '1'){ 
      //IF POWER OFF
      if(power == 0){
        power = 1;  //POWER
        heat = 0;
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
      }
      
      //IF POWER ON
      else{
        power = 0;
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
      }
    }

    //CLICK NANBANG
    else if( ch == '2'){
      if (power == 1 && heat == 1 ){
        heat = 0;
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
      }
    }
    
    else if( ch == '3'){
       if (power == 1 && heat == 0 ){
        heat = 1;
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
      }
    }

    else if( ch == '4'){
       if ( buzer == 0 ){
        buzer = 1;
        digitalWrite(8, HIGH);
      }

      else{
        buzer = 0;
        digitalWrite(8, LOW);   
      }
    }
    
    else if( ch == '4'){
    }

  }
  float temp, humidity;

  int err = dht11.read(humidity, temp);

  if(err == 0){
    btSerial.print(temp);
    btSerial.print(":");
    btSerial.print(humidity);
    btSerial.print(":");
  }
}
