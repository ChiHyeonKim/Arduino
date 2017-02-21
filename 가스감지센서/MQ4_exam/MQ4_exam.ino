void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // LED, Buser output
  pinMode(3, INPUT); //MQ-4 output
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(0); //MQ-4 AOUT input
  int limit = digitalRead(3); //MQ-4 DOUT input
  Serial.println(value);
  Serial.println(limit);

  if(value > 600){
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
  }

  else if (value < 540){
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  }
  delay(1000);

}
