#include <Servo.h>

Servo sg90;

void setup() {
  // put your setup code here, to run once:
  sg90.attach(15);

}

void loop() {
  // put your main code here, to run repeatedly:
  sg90.write(0);

}
