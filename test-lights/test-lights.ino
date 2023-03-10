void setup() {
  // The EL channels are on pins 2 through 9 on the ATMega328
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A
  pinMode(3, OUTPUT);  // channel B
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H

  // Status pins
  pinMode(10, OUTPUT); // Pin 10 is a status LED on the EL Escudo Dos.
  pinMode(13, OUTPUT); // Pin 13 is the status LED on both the EL Sequencer and Arduino for use with the EL Escudo Dos.
}

void loop() {
  int status;

  //Step through all eight EL channels (pins 2 through 9)
  for (int x=2; x<=9; x++) {
    digitalWrite(x, HIGH);   // turn the EL channel on
    delay(100);              // wait for 1/10 second
    digitalWrite(x, LOW);    // turn the EL channel off

    // blink status LEDs
    digitalWrite(10, status);
    digitalWrite(13, status);
    status = !status;
  }
}
