int sensorPin = A0;                  // Promemoria: su quale pin (analogico) è il sensore?

void setup() {
  Serial.begin(9600);                // Apro la comunicazione sulla porta seriale
}

void loop() {
  int val = analogRead(sensorPin);   // Salvo il valore letto dal sensore nella variabile val
  Serial.println(val);               // Stampo il valore val sulla porta seriale
  delay(500);                        // aspetto mezzo secondo
}
