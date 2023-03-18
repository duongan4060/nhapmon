
//khai báo thư viện
#include <Arduino.h>
#include <Servo.h>


//khai báo số lượng servo
Servo servorktt1,servoktt2; //servorktt1 xug 9 và lservorktt2 xung 10

int gockt1,gockt2 = 0;
int i,itt1,itt2;

//hàm setup
void setup()
{
    //gán các sevor vào các cái chân của arduino
    servorktt1.attach(10);
    servoktt2.attach(9);     
}

void loop(){
    //các chương cần chạy
    if
        for (i=0;i<=200;i+=1)
        {
            gockt1=0;
            gockt2=0;

            if ( i>0 and i % 10 == 0){   
                
                if(gockt1<=60){
                    gockt1=gockt1+1;
                    servorktt1.write(gockt1);
                }  

                
                if(gockt2<=60){
                    gockt2=gockt2+1;
                    servoktt2.write(gockt2);
                }           
            }
            delay(20/9);
            
        for (i>=200;i<=400;i+=1){
            
        }
    
    }
    

    for (i=200;i>=0;i-=1){
        gockt1=0;
        gockt2=0;

        if ( i<200 and i % 10 == 0){   
            if(gockt1>=0){
                gockt1=gockt1-1;
                servorktt1.write(gockt1);
            }  

            if(gockt2>=0){
                gockt2=gockt2-1;
                servoktt2.write(gockt2);
            }           
        }
        delay(20/9);
    
    }
}
