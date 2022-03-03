#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
                                  // IN1 IN3 IN2 IN4
Stepper stepper1(stepsPerRevolution, 21, 18, 19, 5);
Stepper stepper2(stepsPerRevolution, 17, 4, 16, 2);

void setup() {
  // set the speed at 5 rpm
  stepper1.setSpeed(15);
  stepper2.setSpeed(15);
  
  // initialize the serial port
  Serial.begin(115200);
}

void turnall(float rev1, float rev2, float rev3) { 
  size_t count1 = 0
  size_t count2 = 0;
  size_t count3 = 0;
  int steps1 = rev1 * stepsPerRevolution;
  int steps2 = rev2 * stepsPerRevolution;
  int steps3 = rev3 * stepsPerRevolution;

  while ((count1 < steps1) && (count2 < steps2) && (count3 < steps3)) {
    if (count1 < steps1) {
      stepper1.step(1);
      count1++;
    }
    if (count2 < steps2) {
      stepper2.step(1);
      count2++;
    }
    if (count3 < steps3) {
      stepper3.step(1);
      count3++;
    }
  }
}

void loop() {
  turnboth(1.0f, 1.0f, 1.0f);
}
