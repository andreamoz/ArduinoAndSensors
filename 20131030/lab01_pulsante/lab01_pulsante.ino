int led = 13;                  // promemoria: dov'è il LED?
int pulsante = 7;              // promemoria: dov'è il pulsante?

void setup() {
  pinMode(led, OUTPUT);        // il pin 13 è un rubinetto
  pinMode(pulsante, INPUT);    // il pin 7 è un pozzetto
}

void loop() {
  // metto nella variabile val quello che arriva nel pozzetto
  // se il pulsante è premuto passa corrente e val vale HIGH
  // altrimenti vale LOW
  int premuto = digitalRead(pulsante);

  if (premuto == HIGH) {       // se il pulsante è premuto
    digitalWrite(13, HIGH);    // apri l'acqua
  } else {                     // altrimenti
    digitalWrite(13, LOW);     // chiudi l'acqua
  }
}


