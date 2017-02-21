void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT); // LED, Buser Output
  pinMode(3, INPUT);  // Human Sensor 
  pinMode(4, INPUT);  // Sound Sensor
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int value = analogRead(1); // Light Sensor 
  int value2 = digitalRead(3); // Human Sensor
  int value3 = analogRead(A0); //Sound Sensor
  int sensorstate = digitalRead(4); //Sound Sensor
  
  Serial.println(value);
  Serial.println(value2);
  Serial.println(value3);
  delay(1000);

  // Sound, Human, Dark  detect
  if(sensorstate == HIGH && value2 == HIGH && value < 50 ){
    digitalWrite(2, HIGH);
   }

   // not detect case : LED, Buser Off
   else digitalWrite(2, LOW);
}
