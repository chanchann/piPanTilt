#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
using namespace std;

#define  MotorPin1 17
#define  MotorPin2 18
#define  MotorEnableDC1 4

#define MotorPin3 27
#define MotorPin4 22
#define MotorEnableDC2 23


 int main(void)
 {

 if(wiringPiSetupGpio()==-1)
{
    cout<<"Setup wiring pi failed";
    return 1;
}


pinMode(MotorPin1,OUTPUT);
pinMode(MotorPin2,OUTPUT);
pinMode(MotorEnableDC1,OUTPUT);

pinMode(MotorPin3,OUTPUT);
pinMode(MotorPin4,OUTPUT);
pinMode(MotorEnableDC2,OUTPUT);

softPwmCreate(MotorEnableDC1,0,50);
softPwmCreate(MotorEnableDC2,0,50);

while(1)
{

    softPwmWrite(MotorEnableDC1,HIGH);
    digitalWrite(MotorPin1,HIGH);
    digitalWrite(MotorPin2,LOW);
    delay(5000);
    softPwmWrite(MotorEnableDC1,LOW);

    softPwmWrite(MotorEnableDC2,HIGH);
    digitalWrite(MotorPin3,LOW);
    digitalWrite(MotorPin4,HIGH);
    delay(5000);
    softPwmWrite(MotorEnableDC2,LOW);
}
return 0;
}