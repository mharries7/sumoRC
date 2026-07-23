#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Motor pins
#define mtrA01 17
#define mtrA02 12
#define mtrB01 18
#define mtrB02 19

#define buzzer 25
#define lampu  15
#define bttnA  26
#define bttnB  32

void setup() {
  // Motor pins
  pinMode(mtrA01, OUTPUT);
  pinMode(mtrA02, OUTPUT);
  pinMode(mtrB01, OUTPUT);
  pinMode(mtrB02, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(lampu, OUTPUT);

  pinMode(bttnA, INPUT);
  pinMode(bttnB, INPUT);

  Serial.begin(115200);
  delay(100);

  // Start Dabble Bluetooth
  Dabble.begin("dabble_promo_gold"); 
}

void loop() {
  Dabble.processInput();

  // Default: stop motors
  stopMotors();

  // Forward
  if (GamePad.isUpPressed()) {
    forward();
  }
  // Backward
  else if (GamePad.isDownPressed()) {
    backward();
  }
  // Left
  else if (GamePad.isLeftPressed()) {
    right();
  }
  // Right
  else if (GamePad.isRightPressed()) {
    left();
  }

  // Optional buttons (example: buzzer or lamp control)
  if (GamePad.isSquarePressed()) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  if (GamePad.isCirclePressed()) {
    digitalWrite(lampu, HIGH);
  } else {
    digitalWrite(lampu, LOW);
  }
}

// ----- Motor movement functions -----

void forward() {
  digitalWrite(mtrA01, LOW);
  digitalWrite(mtrA02, HIGH);
  digitalWrite(mtrB01, HIGH);
  digitalWrite(mtrB02, LOW);
  Serial.println("Motor DEPAN");
}

void backward() {
  digitalWrite(mtrA01, HIGH);
  digitalWrite(mtrA02, LOW);
  digitalWrite(mtrB01, LOW);
  digitalWrite(mtrB02, HIGH);
  Serial.println("Motor UNDUR");
}

void left() {
  digitalWrite(mtrA01, HIGH);
  digitalWrite(mtrA02, LOW);
  digitalWrite(mtrB01, HIGH);
  digitalWrite(mtrB02, LOW);
  Serial.println("Motor KIRI");
}

void right() {
  digitalWrite(mtrA01, LOW);
  digitalWrite(mtrA02, HIGH);
  digitalWrite(mtrB01, LOW);
  digitalWrite(mtrB02, HIGH);
  Serial.println("Motor KANAN");
}

void stopMotors() {
  digitalWrite(mtrA01, LOW);
  digitalWrite(mtrA02, LOW);
  digitalWrite(mtrB01, LOW);
  digitalWrite(mtrB02, LOW);
  Serial.println("Motor STOP");
}
