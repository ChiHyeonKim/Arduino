void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // LED, Buser, Output
  pinMode(3, INPUT);  // Sensor Input
  Serial.begin(9600); //Serial initialize
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(3);
  Serial.println(value);

  if(value == HIGH){  // human detected
    digitalWrite(2, HIGH);
  }
  else{ //human not detected
    digitalWrite(2, LOW);
  }
  
  delay(1000);

}
