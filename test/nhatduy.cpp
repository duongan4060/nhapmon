#include <Arduino.h>
#include<Wire.h>
#include<PCA9685.h>

PCA9685 Controller(Wire);         
PCA9685_ServoEval servodau(128,324,526);  

void setup() {
    Serial.begin(115200);               
    Wire.begin();
    Controller.resetDevices();       
    Controller.init();               
    Controller.setPWMFreqServo(); 
}

void loop (){
  Controller.setChannelPWM(14, servodau.pwmForAngle(0));
}