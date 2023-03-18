#include<Arduino.h>
#include <Servo.h> 
#define cambien A0
 
Servo s1,s2,s3,s4,s5,s6,s7,s8,s9; 
int pos = 0;  
int pos1 = 45;
int pos2 = 90; 
int donhay = 800; 
void setup() 
{ 
  
  s1.attach(0);   
  s2.attach(1);
  s3.attach(2);
  s4.attach(3); 
  s5.attach(4);
  s6.attach(5); 
  s7.attach(6);
  s8.attach(7);
  s9.attach(8);                   
} 
 
 
void loop() 
{  if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s3.write(pos);              
    delay(15);  
    s5.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s3.write(pos);              
    delay(15);  
    s5.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s3.write(pos);              
    delay(15);  
    s5.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s3.write(pos);              
    delay(15);  
    s5.write(pos);
    delay(15); 
                  
  } }
  //////////////////////////////////////////////////////////////////////////////////
  if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s1.write(pos);              
    delay(15); 
    s2.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s1.write(pos);              
    delay(15);  
    s2.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s1.write(pos);              
    delay(15); 
    s2.write(pos);
    delay(15); 
                      
  } }
   if(analogRead(cambien) > donhay){
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s1.write(pos);              
    delay(15);  
    s2.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s3.write(pos);              
    delay(15); 
    s4.write(pos);
                     
  } }
   if(analogRead(cambien) > donhay){
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s3.write(pos);              
    delay(15);  
    s4.write(pos);
    delay(15); 
                    
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s3.write(pos);              
    delay(15); 
    s4.write(pos);
    delay(15); 
                      
  } }
for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s4.write(pos);              
    delay(15); 
    s2.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s4.write(pos);              
    delay(15);  
    s2.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s4.write(pos);              
    delay(15); 
    s2.write(pos);
    delay(15); 
                      
  } }
   if(analogRead(cambien) > donhay){
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s4.write(pos);              
    delay(15);  
    s2.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  } }// tách đoạn 2
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s1.write(pos);              
    delay(15); 
    s4.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s1.write(pos);              
    delay(15);  
    s4.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s1.write(pos);              
    delay(15); 
    s4.write(pos);
    delay(15); 
                      
  } }
   if(analogRead(cambien) > donhay){
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s1.write(pos);              
    delay(15);  
    s4.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  } }// tách đoạn 3
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s3.write(pos);              
    delay(15); 
    s2.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s3.write(pos);              
    delay(15);  
    s2.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s3.write(pos);              
    delay(15); 
    s2.write(pos);
    delay(15); 
                      
  } }
   if(analogRead(cambien) > donhay){
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s3.write(pos);              
    delay(15);  
    s2.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  } }// tách đoạn 4
if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 60; pos += 3)
if(analogRead(cambien) > donhay){
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s3.write(pos);              
    delay(15);  
    s4.write(pos);
    delay(15); 
                      
  } }
 if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s3.write(pos);              
    delay(15); 
    s4.write(pos);
    delay(15); 
                      
  } }
   if(analogRead(cambien) > donhay){
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s3.write(pos);              
    delay(15);  
    s4.write(pos);
    delay(15); 
                      
  } }
  if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 60; pos += 3)  
  {                                  
    
    s8.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
    
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 60; pos>=1; pos-=3)    
  {                                

    s8.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 60; pos += 3)  
  {                                  
   
    s8.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
    
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 60; pos>=1; pos-=3)    
  {                                

    s8.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 60; pos += 3)  
  {                                  
   
    s8.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
    
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 60; pos>=1; pos-=3)    
  {                                

    s8.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s1.write(pos);              
    delay(15); 
    s3.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s1.write(pos);              
    delay(15);  
    s3.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    s1.write(pos);              
    delay(15); 
    s3.write(pos);
    delay(15); 
                      
  } }
   if(analogRead(cambien) > donhay){
  for(pos = 180; pos>=1; pos-=15)    
  {                                
    s1.write(pos);              
    delay(15);  
    s3.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15);
                     
  } }// tách đoạn 1
   if(analogRead(cambien) > donhay){
{                                  
    
    s8.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
    s2.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 60; pos>=1; pos-=3)    
  {                                

    s8.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
    s2.write(pos);
    delay(15);              
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 60; pos += 3)  
  {                                  
   
    s8.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
    s1.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 60; pos>=1; pos-=3)    
  {                                

    s8.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
    s1.write(pos);
    delay(15);              
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 60; pos += 3)  
  {                                  
   
    s8.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
    s4.write(pos);
    delay(15);
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 60; pos>=1; pos-=3)    
  {                                

    s8.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
    s4.write(pos);
    delay(15);              
  } }// tách đoạn 5
if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    
    s1.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
    
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                

    s1.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
   
    s2.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
    
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                

    s2.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
   
    s4.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
    
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)    
  {                                

    s4.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
                  
  } }// tách đoạn 6
if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 180; pos += 15)  
  {                                  
    
    s3.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
    
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 180; pos>=1; pos-=15)
{                                

    s3.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 60; pos += 3)  
  {                                  
   
    s8.write(pos);
    delay(15);
    s5.write(pos);
    delay(15);  
    
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 60; pos>=1; pos-=3)    
  {                                

    s8.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
                  
  } }
   if(analogRead(cambien) > donhay){
   for(pos = 0; pos < 60; pos += 3)  
  {                                  
   
    s8.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
    
                     
  }}
   if(analogRead(cambien) > donhay){ 
  for(pos = 60; pos>=1; pos-=3)    
  {                                

    s8.write(pos);
    delay(15); 
    s5.write(pos);
    delay(15); 
                  
  } }// tách đoạn 7
}