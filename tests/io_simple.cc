#include <iostream>
#include <wiringPi.h>

using namespace std;
#define  MotorPin1 17
#define  MotorPin2 18
#define MotorPin3 27
#define MotorPin4 22


int main() {

    if(wiringPiSetupGpio()==-1) {
        cout << "Setup wiring pi failed";
        return 1;
    }
    pinMode(MotorPin1,OUTPUT);
    pinMode(MotorPin2,OUTPUT);
    pinMode(MotorPin3,OUTPUT);
    pinMode(MotorPin4,OUTPUT);

    while(1) {
        digitalWrite(MotorPin1,HIGH);
        digitalWrite(MotorPin2,LOW);
        delay(5000);


        digitalWrite(MotorPin3,LOW);
        digitalWrite(MotorPin4,HIGH);
        delay(5000);

    }
    return 0;
}