#include <Arduino.h>
#include <Servo.h>

//khai báo số lượng servo
Servo servoct2,servoct3;
Servo servocp2,servocp3;

// khai báo góc độ 
int gct2,gct3;  
int gcp2,gcp3;

int i;

// tạo các lệnh setup
void setup() {
// gán váo các cái xung tín hiệu

  servoct2.attach(9);
  servoct3.attach(10);

  servocp2.attach(12);
  servocp3.attach(13);
  
}

//động tác vẫy tay
void vaytay()
{
  //tay trai live 135 is vay tay
  //tay phai live 45 is vay tay
  for(gtt2=180;gtt2>=105;gtt2-=1){
    servott2.write(gtt2);
    servotp2.write(180-gtt2);
    delay(10);
  }

  for(gtt2=105;gtt2<=180;gtt2+=1){
    servott2.write(gtt2);
    servotp2.write(180-gtt2);
    delay(10);
  }
}

// tay trái
void loop() 
{  
  servoktt2.write(60);
  servoktt3.write(0);

  servocp2.write();
  servocp3.write();
}