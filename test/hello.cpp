
//khai báo thư viện
#include <Arduino.h>
#include <Servo.h>

//khai báo số lượng servo
Servo servott2,servotp2,servodau;

// khai báo góc độ 
int gtt2,gtp2,gd;  

// tạo các lệnh setup
void setup() {
// gán váo các cái xung tín hiệu

  servodau.attach(1);
  servotp2.attach(4);
  servott2.attach(5);
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
  for(gtt2=0;gtt2<=180;gtt2+=1)
  {
    servott2.write(gtt2);
    servotp2.write(180-gtt2);
    delay(10);
  }
  
  if (gtt2=180){
    vaytay();
  }

  for(gtt2=180;gtt2>=0;gtt2-=1)
  {
    servott2.write(gtt2);
    servotp2.write(180-gtt2);
    delay(10);
  } 
}