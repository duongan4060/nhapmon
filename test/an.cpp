#include<Arduino.h>
#include "PCA9685.h"
#include "Wire.h"

// khai bào tên các servo cần dùng
// d là đầu, tt là tay trái,tp là tay phải,ct là chân trái , cp là chân phải 
//128 là -90 324 là 0 và 526 là 90 tính theo
PCA9685 Controller(Wire);         
PCA9685_ServoEval servodau(128,324,526);
PCA9685_ServoEval servott1,servott2(128,324,526);
PCA9685_ServoEval servotp1,servotp2(128,324,526);
PCA9685_ServoEval servoct1,servoct2,servoct3(128,324,526);
PCA9685_ServoEval servocp1,servocp3(128,324,526);
PCA9685_ServoEval servocp2(128,324,526);

// cảm biến âm thanh
int cambienam=A3;
int giatri;


//khai báo chân servo gắn vào 
int headfoot=1;                           // chân trên pca của servo đầu
int tt1=2;int tt2=13;                    // chân trên pca của servo tay phải
int tp1=4;int tp2=5;                    // chân trên pca của servo tat trái 
int ct1=6;int ct2=7  ;int ct3=8;         //  chân trên pca của servo chân trái 
int cp1=9;int cp2=10;int cp3=11;      // chân trên pca của servo chân phải 

// khai bào góc gắn với chân servo đã cho
float gd;                     //góc của cái đầu
float gtt1,gtt2;             //góc của cái tay trái
float gtp1,gtp2;            //góc của cái tay phải
float gct1,gct2,gct3;      //góc của cái chân trái
float gcp1,gcp2,gcp3;     //góc của cái chân phải

// khai báo biến phụ
float i,i1n,i2n;
float i1,i2,ihello;

// biến đúng sai
bool run ; // true false

void setup() {
    Serial.begin(115200);               
    Wire.begin();
    Controller.resetDevices();       
    Controller.init();               
    Controller.setPWMFreqServo(); 
    pinMode(cambienam,INPUT);   
}
// động tác sinh chào
void vitribandau(){
    Controller.setChannelPWM(headfoot, servodau.pwmForAngle(0));

    Controller.setChannelPWM(tt1, servott1.pwmForAngle(90));
    Controller.setChannelPWM(tt2, servott2.pwmForAngle(-90));

    Controller.setChannelPWM(tp1, servotp1.pwmForAngle(-90));
    Controller.setChannelPWM(tp2, servotp2.pwmForAngle(90));

    Controller.setChannelPWM(ct1, servoct1.pwmForAngle(-90));
    Controller.setChannelPWM(ct2, servoct2.pwmForAngle(0));
    Controller.setChannelPWM(ct3, servoct3.pwmForAngle(0));

    Controller.setChannelPWM(cp1, servocp1.pwmForAngle(90));
    Controller.setChannelPWM(cp2, servocp2.pwmForAngle(-20));
    Controller.setChannelPWM(cp3, servocp3.pwmForAngle(0));
}
void hello(int lan,int dela){
    vitribandau();
    delay(500);
    gtt1=90;
    gtt2=-90;
    for (i=0;i<=100;i+=1){
        gtt1-=2;
        if(gtt1>=-90 and gtt1<=90){
            Controller.setChannelPWM(tt1, servott1.pwmForAngle(gtt1));
        }
        delay(30);
    }
    for(i=0;i<=lan;i+=1){
        for(i1=0;i1<=70;i1++){
            gtt2+=1;
            if(gtt2>=-90 and gtt2<=-20){
                Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
            }
            delay(dela);
        }

        for(i1=0;i1<=70;i1++){
            gtt2-=1;
            if(gtt2>=-90 and gtt2<=-20){
                Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
            }
            delay(dela);
        }
        
    }
}

void vaytay(int lan, int dela) {  
    Controller.setChannelPWM(tt1, servott1.pwmForAngle(90));
    Controller.setChannelPWM(tp1, servotp1.pwmForAngle(-90));
    gtt2=0;
    gtp2=0;
    for (i1=0; i1<=lan;i1++){
        for (i=0;i<=75;i+=1)
        {
            if( i>=0 and i<=75){
                gtt2-=1;
                Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
                gtp2+=1;
                Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));
            }
            delay(dela);
        }
        for (i=75;i>=0;i-=1) {
            if (i<=75 and i>=0)
            {
                gtt2+=1;
                Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
                gtp2-=1;
                Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));
            }
            delay(dela);
        }
    }
}

// động tác xoạt chân và thu chân
void xoatchanrado (){
// gct2  hướng tới từ 0 đến 70 (70 độ), gct3 hướng tới là từ 0 đt đến 70 ht (70 độ)
// gcp2 hướng tới là từ -20 đến -90(70 độ),gcp3 hướng tới là từ 0 đt  đến -70ht (70 độ)
    gct2=0;gct3=0;
    gcp2=-20;gcp3=0;
    for (i=0;i<=70;i+=1)
    {

        if (i>=0 and i<=70){
            gct2=gct2+1;
            gcp2=gcp2-1;
            gct3=gct3+1;
            gcp3=gcp3-1;
            if(gct2>=0 and gct2<=70 ){
                Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
            }
            if (gcp2<=-20 and gcp2>=-90){
                Controller.setChannelPWM(cp2, servocp2.pwmForAngle(gcp2));
            }
            if (gct3>=0 and gct3<=70) {
                Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
            } 
            if (gcp3<=0 and gcp3>=-70){
                Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));
            }      
        }
        delay(20);
    }

    for (i=70;i>=0;i-=1)
    {
        if (i<=70 and i>=0){
            gct2=gct2-1;
            gcp2=gcp2+1;
            gct3=gct3-1;
            gcp3=gcp3+1;
            if(gct2>=0 and gct2<=70 ){
                Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
            }
            if (gcp2<=-20 and gcp2>=-90){
                Controller.setChannelPWM(cp2, servocp2.pwmForAngle(gcp2));
            }
            if (gct3>=0 and gct3<=70){
                Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
            }          
            if (gcp3<=0 and gcp3>=-70){
                Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3)); 
            }            
        }
        delay(20);
    }
}

// xoạt chân ra
void xoatchanra(){
    gct2=0;gct3=0;
    gcp2=-20;gcp3=0;
    for (i=0;i<=70;i+=1)
    {

        if (i>=0 and i<=70){
            gct2=gct2+1;
            gcp2=gcp2-1;
            gct3=gct3+1;
            gcp3=gcp3-1;
            if(gct2>=0 and gct2<=70 ){
                Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
            }
            if (gcp2<=-20 and gcp2>=-90){
                Controller.setChannelPWM(cp2, servocp2.pwmForAngle(gcp2));
            }
            if (gct3>=0 and gct3<=70) {
                Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
            } 
            if (gcp3<=0 and gcp3>=-70){
                Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));
            }      
        }
        delay(20);
    }

}  
//thu chân về
void thuchanlai(){
// gct2  hướng tới từ 0 đến 70 (70 độ), gct3 hướng tới là từ -70 đt đến 0 ht (70 độ)
// gcp2 hướng tới là từ -20 đến -90(70 độ),gcp3 hướng tới là từ -70đt  đến -90ht (20 độ)
    for (i=70;i>=0;i-=1)
    {
        if (i<=70 and i>=0){
            gct2=gct2-1;
            gcp2=gcp2+1;
            gct3=gct3-1;
            gcp3=gcp3+1;
            if(gct2>=0 and gct2<=70 ){
                Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
            }
            if (gcp2<=-20 and gcp2>=-90){
                Controller.setChannelPWM(cp2, servocp2.pwmForAngle(gcp2));
            }
            if (gct3>=0 and gct3<=70){
                Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
            }          
            if (gcp3<=0 and gcp3>=-70){
                Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3)); 
            }            
        }
        delay(20);
    }
}
void dongtac1(){
    Controller.setChannelPWM(tp1, servotp1.pwmForAngle(-90));
    gd=0;
    gtt1=90;
    gtp2=0;
    for(i=1;i<=100;i+=1){
        gd+=2;
        if (gd>=0 and gd<=90){
            Controller.setChannelPWM(headfoot, servodau.pwmForAngle(gd));
        }
        delay(10);
        if(gd>90){
            i=100;
        }
    }
    gd=90;
    if (gd<=90){
        for (i1=1;i1<=100;i1+=1){
            gtt1-=5;
            if(gtt1<=90 and gtt1>=0){
                Controller.setChannelPWM(tt1,servott1.pwmForAngle(gtt1));
            }
            gtp2-=5;
            if (gtp2<=0 and gtp2>=-90){
                Controller.setChannelPWM(tp2,servotp2.pwmForAngle(gtp2));
            }
            delay(15);
            if(gtt1<0 and gtp2<-90){
                i1=100;
            }
            
        }
        delay(1000);
        for (i1=1;i1<=100;i1+=1){
            gtt1+=5;
            if(gtt1<=90 and gtt1>=0){
                Controller.setChannelPWM(tt1, servott1.pwmForAngle(gtt1));
            }
            gtp2+=5;
            if (gtp2<=0 and gtp2>=-90){
                Controller.setChannelPWM(tp2,servotp2.pwmForAngle(gtp2));
            }           
            delay(15);
            if(gtt1>90 and gtp2>0){
                i1=100;
            }
        }
    }
    for(i=1;i<=100;i+=1){
        gd-=2;
        if (gd>=0 and gd<=90){
            Controller.setChannelPWM(headfoot, servodau.pwmForAngle(gd));
        }
        delay(10);
        if(gd<0){
            i=100;
        }
    }

}
// dongtac2 là 1 phần muốn lập lại của động tác 1
void dongtac2(){
    Controller.setChannelPWM(tp1, servotp1.pwmForAngle(-90));
    for (i1=1;i1<=100;i1+=1){
        gd+=5;
        if (gd>=0 and gd<=90){
            Controller.setChannelPWM(headfoot, servodau.pwmForAngle(gd));
        }      
        gtt1-=5;
        if(gtt1<=90 and gtt1>=0){
            Controller.setChannelPWM(tt1,servott1.pwmForAngle(gtt1));
        }
        gtp2-=5;
        if (gtp2<=0 and gtp2>=-90){
            Controller.setChannelPWM(tp2,servotp2.pwmForAngle(gtp2));
        }
        delay(15);
        if(gtt1<0 and gtp2<-90){
            i1=100;
        }
        
    }
    for (i1=1;i1<=100;i1+=1){
        gtt1+=5;
        if(gtt1<=90 and gtt1>=0){
            Controller.setChannelPWM(tt1, servott1.pwmForAngle(gtt1));
        }
        gtp2+=5;
        if (gtp2<=0 and gtp2>=-90){
            Controller.setChannelPWM(tp2,servotp2.pwmForAngle(gtp2));
        }
        gd-=5;
        if (gd>=0 and gd<=90){
            Controller.setChannelPWM(headfoot, servodau.pwmForAngle(gd));
        }        
        delay(15);
        if(gtt1>90 and gtp2>0){
            i1=100;
        }
    }
}

void chuyenvedithangvavengan(){
    gcp1=90;
    gct1=-90;
    for ( i = 0; i <=100; i++)
    {
        gcp1-=1;
        gct1+=1;
        if (gcp1<=90 and gcp1>=0){
            Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
        }
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        delay(15);
        if (gcp1<0 and gct1>0){
            i=100;
        }
    }

    gcp1=0;
    gct1=0;
    for ( i = 0; i <=100; i++)
    {
        gcp1+=1;
        gct1-=1;
        if (gcp1<=90 and gcp1>=0){
            Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
        }
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        delay(15);
        if (gcp1>90 and gct1<-90){
            i=100;
        }
    }
    
}
void ngangthang(){
    gcp1=90;
    gct1=-90;
    for ( i = 0; i <=100; i++)
    {
        gcp1-=1;
        gct1+=1;
        if (gcp1<=90 and gcp1>=0){
            Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
        }
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        delay(15);
        if (gcp1<0 and gct1>0){
            i=100;
        }
    }

}

void thangtongang(){
    gcp1=0;
    gct1=0;
    for ( i = 0; i <=100; i++)
    {
        gcp1+=1;
        gct1-=1;
        if (gcp1<=90 and gcp1>=0){
            Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
        }
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        delay(15);
        if (gcp1>90 and gct1<-90){
            i=100;
        }
    }
}
void nhungngang(int lan,int dela){
    Controller.setChannelPWM(ct2, servoct2.pwmForAngle(0)); //thẳng 0
    Controller.setChannelPWM(cp2, servocp2.pwmForAngle(-20));//thẳng -20
    gtt1=0;
    gtp1=0;
    Controller.setChannelPWM(tt1, servott1.pwmForAngle(gtt1));
    Controller.setChannelPWM(tp1, servotp1.pwmForAngle(gtp1));
    gtt2=0;
    gtp2=0;
    Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
    Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));
    gcp3=0; //hướng tới góc -20
    gct3=0;  //hướng tới góc +20
    for (i1=0;i1<=lan;i1++){
        for (i=0; i<=100;i+=1){
            gcp3-=1;
            gct3+=1;
            if(gcp3<=0 and gcp3>=-20){
                Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));       
            }
            if (gct3>=0 and gct3<=20){
                Controller.setChannelPWM(ct3,servoct3.pwmForAngle(gct3));
            }
            gtt2-=4.5;
            gtp2+=4.5;
            if(gtt2<=0 and gtt2>=-90){
                Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
            }
            if (gtp2>=0 and gtp2<=90){
                Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));
            }
            delay(dela);
            if (gtt2<-90 and gtp2>90){
                i=100;
            }
        }

        for (i=0; i<=100;i+=1){
            gcp3+=1;
            gct3-=1;
            if(gcp3<=0 and gcp3>=-20){
                Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));       
            }
            if (gct3>=0 and gct3<=20){
                Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
            }
            gtt2+=4.5;
            gtp2-=4.5;
            if(gtt2<=0 and gtt2>=-90){
                Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
            }
            if (gtp2>=0 and gtp2<=90){
                Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));
            }
            delay(dela);
            if (gtt2>0 and gtp2<0){
                i=100;
            }
        }
    }
}
void nhungtoi(){
    Controller.setChannelPWM(ct3, servoct3.pwmForAngle(0));
    Controller.setChannelPWM(cp3, servocp3.pwmForAngle(0));
    Controller.setChannelPWM(tt1, servott1.pwmForAngle(0));
    Controller.setChannelPWM(tp1, servotp2.pwmForAngle(0));
    Controller.setChannelPWM(ct2, servoct2.pwmForAngle(0));
    Controller.setChannelPWM(cp2, servocp2.pwmForAngle(-20));
    gcp3=-70; //tiến tới -80  lùi lại -60
    gct3=-70; //tiền tới -60 lùi lại  -80

    for(i=1;i<=100;i+=1){
        gcp3+=1;
        if(gcp3>=0 and gcp3<=10){
            Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));       
        }
        gct3+=1;
        if(gct3>=0 and gct3<=10){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        delay(20);
        if(gct3>10 and gcp3>10){
            i=100;
        }
    }

    for(i=1;i<=100;i+=1){
        gcp3-=1;
        if(gcp3>=0 and gcp3<=10){
            Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));       
        }
        gct3-=1;
        if(gct3>=0 and gct3<=10){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        delay(20);
        if(gct3<0 and gcp3<0){
            i=100;
        }
    }

    for(i=1;i<=100;i+=1){
        gcp3-=1;
        if(gcp3<=0 and gcp3>=-10){
            Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));       
        }
        gct3-=1;
        if(gct3<=0 and gct3>=-10){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        delay(20);
        if(gct3<-10 and gcp3<-10){
            i=100;
        }
    }
    for(i=1;i<=100;i+=1){
        gcp3+=1;
        if(gcp3<=0 and gcp3>=-10){
            Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));       
        }
        gct3+=1;
        if(gct3<=0 and gct3>=-10){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        delay(20);
        if(gct3>0 and gcp3>0){
            i=100;
        }
    }

}

void dongtacchimbay(){
    Controller.setChannelPWM(ct2, servoct2.pwmForAngle(0)); //thẳng 0
    Controller.setChannelPWM(cp2, servocp2.pwmForAngle(-20));//thẳng -20

    gct1=-90;

    for (i=1;i<=100;i++){
        gct1+=1;
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        if (gct1>0){
            i=100;
        }
        delay(15);
    }

    gct2=0;
    gct3=0;
    for (i=0;i<=20;i++){
        gct2-=1;
        gct3-=1;
        if (gct2>=-20 and gct2<=0){
            Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
        }
        if (gct3>=-20 and gct3<=0){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        if (gct2 >0 and gct3>20){
            i=20;   
        }
        delay(30);
        
    }
    delay(500);

    // về lại vị trí ban đầu
    gct2=-20;
    gct3=-20;
    for (i=0;i<=20;i++){
        gct2+=1;
        gct3+=1;
        if (gct2>=-20 and gct2<=0){
            Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
        }
        if (gct3>=-20 and gct3<=0){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        if (gct2>0 and gct3>0){
            i=20;
        }
        delay(30);  
    }

    gct1=0;
    for (i=1;i<=100;i++){
        gct1-=1;
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        if (gct1<-90){
            i=100;
        }
        delay(15);
    }


}

void chimchansau(){
    Controller.setChannelPWM(ct2, servoct2.pwmForAngle(0)); //thẳng 0
    Controller.setChannelPWM(cp2, servocp2.pwmForAngle(-20));//thẳng -20

    gct1=-90;

    for (i=1;i<=100;i++){
        gct1+=1;
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        if (gct1>0){
            i=100;
        }
        delay(15);
    }

    gct2=0;
    gct3=0;
    for (i=0;i<=20;i++){
        gct2-=1;
        gct3-=1;
        if (gct2>=-20 and gct2<=0){
            Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
        }
        if (gct3>=-20 and gct3<=0){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        if (gct2 >0 and gct3>20){
            i=20;   
        }
        delay(30);
        
    }
    delay(500);
}
void chimchanve(){
    gct2=-20;
    gct3=-20;
    for (i=0;i<=20;i++){
        gct2+=1;
        gct3+=1;
        if (gct2>=-20 and gct2<=0){
            Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
        }
        if (gct3>=-20 and gct3<=0){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        if (gct2>0 and gct3>0){
            i=20;
        }
        delay(30);  
    }

    gct1=0;
    for (i=1;i<=100;i++){
        gct1-=1;
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        if (gct1<-90){
            i=100;
        }
        delay(15);
    }
   
}

void chimcahaichan(){
    Controller.setChannelPWM(ct2, servoct2.pwmForAngle(0)); //thẳng 0
    Controller.setChannelPWM(cp2, servocp2.pwmForAngle(-20));//thẳng -20

    gct1=-90;
    gcp1=90;
    for (i=1;i<=100;i++){
        gct1+=1;
        gcp1-=1;
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        if(gcp1<=90 and gcp1>=0){
            Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
        }
        if (gct1>0  and gcp1<0){
            i=100;
        }
        delay(15);
    }

    gct2=0;
    gct3=0;
    gcp2=-20;
    gcp3=0;
    for (i=0;i<=20;i++){
        // chân trái
        gct2-=1;
        gct3-=1;
        if (gct2>=-20 and gct2<=0){
            Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
        }
        if (gct3>=-20 and gct3<=0){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        // chân phải
        gcp2-=1;
        gcp3-=1;
        if(gcp2<=-20 and gcp2>=-40 ){
            Controller.setChannelPWM(cp2,servocp2.pwmForAngle(gcp2));
        }
        if(gcp3>=-20 and gcp3<=0){
            Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));        
        }

        if (gct2 <-20 and gct3<-20 and gcp2<-40 and gcp3<-20){
            i=20;   
        }
        delay(30);
        
    }
    delay(500);

    // về lại vị trí ban đầu
    gct2=-20;
    gct3=-20;
    for (i=0;i<=20;i++){
        // CHÂN TRÁI
        gct2+=1;
        gct3+=1;
        if (gct2>=-20 and gct2<=0){
            Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
        }
        if (gct3>=-20 and gct3<=0){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        //CHÂN PHẢI
        gcp2+=1;
        gcp3+=1;
        if(gcp2<=-20 and gcp2>=-40 ){
            Controller.setChannelPWM(cp2,servocp2.pwmForAngle(gcp2));
        }
        if(gcp3>=-20 and gcp3<=0){
            Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));        
        }       
        if (gct2 >0 and gct3>0 and gcp2>-20 and gcp3>0){
            i=20;
        }
        delay(30);  
    }

    gct1=0;
    gcp1=0;
    for (i=1;i<=100;i++){
        gct1-=1;
        gcp1+=1;
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        if(gcp1<=90 and gcp1>=0){
            Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
        }
        if (gct1<-90 and gcp1 >90){
            i=100;
        }
        delay(15);
    }
}
// chim cha hai chân lượt đi 
void luotchimdi(){
    Controller.setChannelPWM(ct2, servoct2.pwmForAngle(0)); //thẳng 0
    Controller.setChannelPWM(cp2, servocp2.pwmForAngle(-20));//thẳng -20

    gct1=-90;
    gcp1=90;
    for (i=1;i<=100;i++){
        gct1+=1;
        gcp1-=1;
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        if(gcp1<=90 and gcp1>=0){
            Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
        }
        if (gct1>0  and gcp1<0){
            i=100;
        }
        delay(15);
    }

    gct2=0;
    gct3=0;
    gcp2=-20;
    gcp3=0;
    for (i=0;i<=20;i++){
        // chân trái
        gct2-=1;
        gct3-=1;
        if (gct2>=-20 and gct2<=0){
            Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
        }
        if (gct3>=-20 and gct3<=0){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        // chân phải
        gcp2-=1;
        gcp3-=1;
        if(gcp2<=-20 and gcp2>=-40 ){
            Controller.setChannelPWM(cp2,servocp2.pwmForAngle(gcp2));
        }
        if(gcp3>=-20 and gcp3<=0){
            Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));        
        }

        if (gct2 <-20 and gct3<-20 and gcp2<-40 and gcp3<-20){
            i=20;   
        }
        delay(30);
        
    }
    delay(500);

}
//chim bay lượt về
void luotchimve(){
    // về lại vị trí ban đầu
    gct2=-20;
    gct3=-20;
    for (i=0;i<=20;i++){
        // CHÂN TRÁI
        gct2+=1;
        gct3+=1;
        if (gct2>=-20 and gct2<=0){
            Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
        }
        if (gct3>=-20 and gct3<=0){
            Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
        }
        //CHÂN PHẢI
        gcp2+=1;
        gcp3+=1;
        if(gcp2<=-20 and gcp2>=-40 ){
            Controller.setChannelPWM(cp2,servocp2.pwmForAngle(gcp2));
        }
        if(gcp3>=-20 and gcp3<=0){
            Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));        
        }       
        if (gct2 >0 and gct3>0 and gcp2>-20 and gcp3>0){
            i=20;
        }
        delay(30);  
    }

    gct1=0;
    gcp1=0;
    for (i=1;i<=100;i++){
        gct1-=1;
        gcp1+=1;
        if (gct1>=-90 and gct1<=0){
            Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
        }
        if(gcp1<=90 and gcp1>=0){
            Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
        }
        if (gct1<-90 and gcp1 >90){
            i=100;
        }
        delay(15);
    }
}

void xaitaychan(){
    gtt2=-90;
    gtp2=90;
    gct2=0;gct3=0;
    gcp2=-20;gcp3=0;
    for (i=0;i<=90;i+=1)
    {  
        if (i>=20 and i<=90) {
            gcp2=gcp2-1;
            gct3=gct3+1;
            gcp3=gcp3-1;
            if (gcp2<=-20 and gcp2>=-90){
                Controller.setChannelPWM(cp2, servocp2.pwmForAngle(gcp2));
            }
            if (gct3>=0 and gct3<=70) {
                Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
            } 
            if (gcp3<=0 and gcp3>=-70){
                Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));
            } 
            if (gcp3<-70 and gct3>70 and gcp2<-90 ){
                i=100;    
            }
        }
        gtt2+=1;
        gtp2-=1;
        if (gtt2>=-90 and gtt2<=0){
            Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
        }
        if (gtp2<=90 and gtp2>=0){
            Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));        
        }
        delay(20);
    }
}
void xaitaychan1(){
    gtt2=-90;
    gtp2=90;
    gct2=0;gct3=0;
    gcp2=-20;gcp3=0;
    for (i=0;i<=90;i+=1)
    {  
        if (i>=20 and i<=90) {
            gct2=gct2+1;
            gcp2=gcp2-1;
            gct3=gct3+1;
            gcp3=gcp3-1;
            if(gct2>=0 and gct2<=70 ){
                Controller.setChannelPWM(ct2, servoct2.pwmForAngle(gct2));
            }
            if (gcp2<=-20 and gcp2>=-90){
                Controller.setChannelPWM(cp2, servocp2.pwmForAngle(gcp2));
            }
            if (gct3>=0 and gct3<=70) {
                Controller.setChannelPWM(ct3, servoct3.pwmForAngle(gct3));
            } 
            if (gcp3<=0 and gcp3>=-70){
                Controller.setChannelPWM(cp3, servocp3.pwmForAngle(gcp3));
            } 
            if (gcp3<-70 and gct3>70 and gcp2<-90 and gct2>70){
                i=100;    
            }
        }
        gtt2+=1;
        gtp2-=1;
        if (gtt2>=-90 and gtt2<=0){
            Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
        }
        if (gtp2<=90 and gtp2>=0){
            Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));        
        }
        delay(20);
    }
}
void chabidao(int lan,int dela){
    gtt2=0;
    gtp2=0;
    Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
    Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));
    Controller.setChannelPWM(tt2, servott2.pwmForAngle(0));
    Controller.setChannelPWM(tp2, servotp2.pwmForAngle(0));

    gcp1=90;
    gct1=-90;
    for (i1=0;i1<=lan;i1++){
        for ( i = 0; i <=45; i++)
        {
            // xoay chân vào 45 đọ
            gcp1-=1;
            gct1+=1;
            if (gcp1<=90 and gcp1>=45){
                Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
            }
            if (gct1>=-90 and gct1<=-45){
                Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
            }
            // đưa tay vào 90 độ
            gtt2-=2;
            gtp2+=2;
            if(gtt2<=0 and gtt2>=-90){
                Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
            }
            if (gtp2>=0 and gtp2<=90){
                Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));
            }
            delay(dela);
            if (gcp1<45 and gct1>-45){
                i=100;
            }
        }
        for ( i = 0; i <=45; i++){
            // xoay chân ra 45 đọ
            gcp1+=1;
            gct1-=1;
            if (gcp1<=90 and gcp1>=45){
                Controller.setChannelPWM(cp1, servocp1.pwmForAngle(gcp1));
            }
            if (gct1>=-90 and gct1<=-45){
                Controller.setChannelPWM(ct1, servoct1.pwmForAngle(gct1));
            }
            //tay ra 90
            gtt2+=2;
            gtp2-=2;
            if(gtt2<=0 and gtt2>=-90){
                Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
            }
            if (gtp2>=0 and gtp2<=90){
                Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));
            }
            delay(dela);
            if (gcp1<45 and gct1>-45){
                i=100;
            }
        }
    }

}

//động tác kết hợp tay chân và đầu


void loop (){
    vitribandau();
    giatri=analogRead(cambienam);
    Serial.println("giá trị hiện tại của cảm biến âm : ");
    Serial.println(giatri);
    delay(200);
 //các đông tác mình code được
    if(giatri>1000){
        run=true;
    }
    else {
        run= false;
    }

    while (run==true){
        if (ihello==0){
        hello(4,5);
        ihello+=1;
        } 
        xaitaychan();
        dongtac1();
        if (ihello==0){
            hello(4,5);
            ihello+=1;
        }
        dongtac2();
        thuchanlai();
        chimchansau();
        vaytay(3,20);
        chimchanve();
        luotchimdi();
        vaytay(3,20);
        luotchimve();
        nhungngang(2,20);
        vaytay(2,20);
        chabidao(2,20);
        nhungngang(2,20);
        chabidao(2,20);

    // thu tay về của động tác nhung ngang
        gtt1=0;
        gtp1=0;
        for (i=0;i<=100;i++){
            gtt1+=1;
            gtp1-=1;
            if (gtt1>=0 and gtt1<=90){
                Controller.setChannelPWM(tt1, servott1.pwmForAngle(gtt1));
            }
            if (gtp1<=0 and gtp1>=-90){
                Controller.setChannelPWM(tp1, servotp1.pwmForAngle(gtp1));
            }
            if (gtt1>90 and gtp1<-90){
                i=100;
            }
            delay(25);
                
        }
        gtt2=0; // về -90
        gtp2=0; //về 90
        for(i=0;i<=100;i++){
            gtt2--;
            gtp2++;
            if (gtt2<=0 and gtt2>=-90){
                Controller.setChannelPWM(tt2, servott2.pwmForAngle(gtt2));
            }
            if( gtp2>=0 and gtp2<=90){
                Controller.setChannelPWM(tp2, servotp2.pwmForAngle(gtp2));
            }
            if (gtt2<90 and gtp2>90){
                i=100;
            }
            delay(20);
        }
        run=false;
    }
/*

    xaitaychan();
    xoatchanrado();
    xoatchanra();
    thuchanlai();

    dongtac1();
    dongtac2();
    vaytay();

    nhungtoi();
    nhungngang();

    chuyenvedithangvavengan();
    ngangthang();
    thangtongang();

    dongtacchimbay();
    chimchansau();
    chimchanve();
    chimcahaichan();
*/
    


/*
    Controller.setChannelPWM(headfoot, servodau.pwmForAngle(0));

    Controller.setChannelPWM(tt1, servott1.pwmForAngle(90));
    Controller.setChannelPWM(tt2, servott2.pwmForAngle(-90));

    Controller.setChannelPWM(tp1, servotp1.pwmForAngle(-90));
    Controller.setChannelPWM(tp2, servotp2.pwmForAngle(90));

    Controller.setChannelPWM(ct1, servoct1.pwmForAngle(-90));
    Controller.setChannelPWM(ct2, servoct2.pwmForAngle(0));
    Controller.setChannelPWM(ct3, servoct3.pwmForAngle(0));

    Controller.setChannelPWM(cp1, servocp1.pwmForAngle(90));
    Controller.setChannelPWM(cp2, servocp2.pwmForAngle(-20));
    Controller.setChannelPWM(cp3, servocp3.pwmForAngle(0));
  */  

}
