/*
Per ottenere l'effetto desiderato bisogna invertire il 
comportamento "naturale" della funzione map.
Il LED si accende con un'intensità inversamente proporzionale 
al valore letto dalla fotoresistenza.
Sembra non funzionare? Proviamo ad applicare la mappa solo ai valori
rilevati dalla fotoresistenza nelle condizioni in cui proviamo:
aggiungiamo una nuova variabile maxVal, nel setup le assegniamo
il valore letto dal sensore in condizioni di massima luminosità
(meglio se aumentato di qualche unità),
poi applichiamo la mappa all'intervallo (0, maxVal)
*/

int sensorPin = A0;                  // Promemoria: su quale pin (analogico) è il sensore?
int led = 9;                         // Promemoria: su quale pin (digitale, ma PWM) è il LED?
int maxVal;                          // qual è il valore massimo letto dal sensore?

void setup() {
  Serial.begin(9600);                // Apro la comunicazione sulla porta seriale
  pinMode(led, OUTPUT);              // il pin "led" è un rubinetto
  maxVal = 32;                       // il valore massimo letto dal sensore
}

void loop() {
  int val = analogRead(sensorPin);   // Salvo il valore letto dal sensore nella variabile val
  Serial.println(val);               // Stampo il valore val sulla porta seriale
  int quantaLuce = map(val, 0, maxVal, 255, 0); // Riporto il valore a un intervallo accettabile per il LED
  //Serial.println(quantaLuce);        // Stampo il valore quantaLuce sulla porta seriale
  analogWrite(led, quantaLuce);      // Faccio uscire un po' di acqua dal rubinetto
  delay(500);                        // Aspetto mezzo secondo
}
