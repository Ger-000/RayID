#include <Servo.h>

#define laserPIN 4

Servo myservo;

void readRI() {
  digitalWrite(laserPIN, HIGH);
  delay(500);

  float v[13];       // v5 to v17
  int pin = 5;       // starting pin

  float vs = 0;
  int sumAnalog = 0;

  for(int i = 0; i < 13; i++, pin++) {
    int val = analogRead(pin);
    sumAnalog += val;
    if(val > 20) {
      v[i] = 1.15 + i * 0.05;   // thy factor sequence: 1.15,1.2,...1.75
      Serial.print(v[i]);
      Serial.print(" ");
      vs += v[i] * val;
    } else {
      v[i] = 0;
    }
  }

  // Avoid division by zero
  float vf = (sumAnalog > 0) ? vs / sumAnalog : 0;

  Serial.print(" | vf = ");
  Serial.println(vf);

  digitalWrite(laserPIN, LOW);
}

void setup() {
  pinMode(laserPIN, OUTPUT);
  Serial.begin(9600);       // start serial communication
  myservo.attach(18);       // attach servo
}

void loop() {
  // Move servo to 0 degrees and read RI
  myservo.write(0);                    
  delay(500);        // allow servo to reach position
  readRI();
  delay(1000);

  // Move servo to 90 degrees and read RI
  myservo.write(90);                    
  delay(500);
  readRI();
  delay(1000);
}


