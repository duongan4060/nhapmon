#include <Arduino.h>
#include <Servo.h>

//khai báo số lượng servo
Servo servodau; // đầu

Servo servott1,servott2;//tay trai
Servo servotp1,servotp2;//tay phai

Servo servoct1,servoct2,servoct3;//chân trái
Servo servocp1,servocp2,servocp3;// ch

// khai báo góc độ 
int gdau;

int gtt1,gtt2;
int gtp1,gtp2;

int gcp1,gct2,gct3;  
int gcp1,gcp2,gcp3;

int i;

void setup() {
// gán váo các cái xung tín hiệu
  servodau.attach(2);

  servott1.attach(3);
  servott2.attach(4);

  servotp1.attach(5);
  servotp2.attach(6);

  servoct1.attach(8);
  servoct2.attach(9);
  servoct3.attach(10);

  servocp1.attach(11);
  servocp2.attach(12);
  servocp3.attach(13);
  
}
//chạy chương trìnhn nạp 
void loop() 
{  
    for
}
