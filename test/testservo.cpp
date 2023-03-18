#include<Servo.h>
#include<Arduino.h>

Servo servokt1,servokt2;

void setup(){
    servokt1.attach(4);
    servokt2.attach(6);
}
void loop() {
    servokt1.write(0);
    servokt2.write(180);

}
