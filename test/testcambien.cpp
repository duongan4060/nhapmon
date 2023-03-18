#include<Arduino.h>

int cambienam=A0;
int giatri;

void setup(){
    Serial.begin(9600);
    pinMode(cambienam,INPUT);
}
 
void loop()
{
    giatri=analogRead(cambienam);
    
    Serial.println("giá trị hiện tại của cảm biến âm : ");
    Serial.println(giatri);
    delay(20);
}