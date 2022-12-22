#define ANIMATION_CHANNELS 4

template <int N>
struct AnimationFrame {
  uint8_t pins[N];
  uint8_t modes[N];
};

/// Animation frames. Overkill for this project, but maybe I'll make something more interesting in the future.
AnimationFrame<ANIMATION_CHANNELS> animations[] {
  {{2, 3, 4, 5}, {HIGH, HIGH, LOW, LOW}},
  {{2, 3, 4, 5}, {LOW, LOW, HIGH, HIGH}}
};

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

  // Initialise all pins to be on
  for (int x = 2; x <= 9; x++) {
    digitalWrite(x, HIGH);
  }

  // Status pins
  pinMode(10, OUTPUT); // Pin 10 is a status LED on the EL Escudo Dos.
  pinMode(13, OUTPUT); // Pin 13 is the status LED on both the EL Sequencer and Arduino for use with the EL Escudo Dos.
}

void loop() {
  int status;

  // Iterate through animation frames
  for (auto & animation : animations) {
    // Animate all EL channels that are part of the animation
    for (uint8_t pin = 0; pin < ANIMATION_CHANNELS; ++pin) {
      // turn the EL channel on / off
      digitalWrite(animation.pins[pin], animation.modes[pin]);
    }
    delay(2000); // wait for 2 seconds

    // blink status LEDs
    digitalWrite(10, status);
    digitalWrite(13, status);
    status = !status;
  }
}
