/*
Il valore di soglia che ho messo è fittizio, 
bisogna sceglierne uno adatto ai valori letti dal sensore
nel momento in cui facciamo l'esperimento. Per questo ci aiutano
i valori che stampiamo sulla porta seriale.
Ho un termistore di tipo NTC, quindi quando la temperatura sale
la resistenza si abbassa, e quando la temperatura scende 
la resistenza si alza.

Quando poi faremo un prodotto "vero" andremo a calcolare
con precisione la soglia corretta da utilizzare.
*/

int sensorPin = A0;                  // Promemoria: su quale pin (analogico) è il sensore?
int soglia = 45;                     // Imposto il valore al di sotto del quale voglio accendere la caldaia
int led = 13;                        // Promemoria: su quale pin (digitale) è il LED (che rappresenta la caldaia)?

void setup() {
  Serial.begin(9600);                // Apro la comunicazione sulla porta seriale
  pinMode(led, OUTPUT);              // il pin "led" è un rubinetto
}

void loop() {
  int val = analogRead(sensorPin);   // Salvo il valore letto dal sensore nella variabile val
  Serial.println(val);             // Stampo il valore val sulla porta seriale
  if (val < soglia) {                // Se il valore letto è sotto la soglia
    digitalWrite(led, HIGH);  
  } else {
    digitalWrite(led, LOW);
  }
  delay(1000);
}
