void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  int reading = analogRead(A0);
  int value = map(reading, 0, 1023, 255, 0);
  analogWrite(9, value);
  delay(500);
}
