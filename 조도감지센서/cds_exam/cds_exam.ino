void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(0);
  Serial.println(value);
  if (value > 1000){
    digitalWrite(2, HIGH);
  }
  else digitalWrite(2, LOW);
 
  delay(1000);
}
