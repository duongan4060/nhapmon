
//khai báo thư viện
#include <Arduino.h>
#include <Servo.h>


//khai báo số lượng servo
Servo servorktt1,servoktt2; //servorktt1 xug 9 và lservorktt2 xung 10

int gockt1,gockt2 = 0;
int i,itt1,itt2;
int sound=0;

//hàm setup
void setup()
{
    //gán các sevor vào các cái chân của arduino
    servorktt1.attach(10);
    Serial.begin(115200);   

}

void loop()
{
    sound=analogRead(A0);
    Serial.println(sound);
    delay(15);

    

    for (i=0;i<=200;i+=1){

        if ( i>0 and i % 10 == 0)
        {   
            gockt1=gockt1+1;
            servorktt1.write(gockt1);
        } 
        delay(10/3);
    }

    for(i=200;i<=400;i+=1)
    {
         if(i>200 and i % 10==0){
            gockt1=gockt1-1;
            servorktt1.write(gockt1);   
        }
        delay(5);
    }
    
}
    //các chương cần chạy

    

    
