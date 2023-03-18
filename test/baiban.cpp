#include <Wire.h>
#include <PCA9685.h>

PCA9685 Controller(Wire);         
PCA9685_ServoEval servodau(128,324,526);
PCA9685_ServoEval servott(128,324,526);
PCA9685_ServoEval servotp(128,324,526);
PCA9685_ServoEval servoct1,servoct2(128,324,526);
PCA9685_ServoEval servocp1(128,324,526);
PCA9685_ServoEval servocp2(128,324,526);

int posdau = 0;
int postp = 0;
int postt=0;
int poscp1=0;
int posct1=0;
int poscp2=0;
int posct2=0;


int dau =1;                              
int tt =2;                      
int tp =3;                     
int ct1=4;int ct2=5;;       
int cp1=6;int cp2=7;     


void setup() {
    Serial.begin(115200);               
    Wire.begin();
    Controller.resetDevices();       
    Controller.init();               
    Controller.setPWMFreqServo();  

}

void loop() {
  Controller.setChannelPWM(dau, servodau.pwmForAngle(posdau));
  Controller.setChannelPWM(ct1, servoct1.pwmForAngle(posct1));
  Controller.setChannelPWM(ct2, servoct2.pwmForAngle(posct2));
  Controller.setChannelPWM(tt, servott.pwmForAngle(postt));
  Controller.setChannelPWM(tp, servotp.pwmForAngle(postp));
  Controller.setChannelPWM(cp1, servocp1.pwmForAngle(poscp1));
  Controller.setChannelPWM(cp2, servocp2.pwmForAngle(poscp2));
  for( posdau=0; posdau<90;posdau++){
    Controller.setChannelPWM(dau,servodau.pwmForAngle(posdau));
    delay(15);
  }
  if(posdau=90){
    posdau=0;
    delay(2000);
  }
}