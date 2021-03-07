#include <iostream>
#include <wiringPi.h>
#include <signal.h>

using namespace std;

// BCM
#define MotorPin1 26
#define MotorPin2 19
#define MotorPin3 13
#define MotorPin4 6

// https://stackoverflow.com/questions/1641182/how-can-i-catch-a-ctrl-c-event
void my_handler(int s){
    printf("Caught signal %d\n",s);
    digitalWrite(MotorPin1,LOW);
    digitalWrite(MotorPin2,LOW);
    digitalWrite(MotorPin3,LOW);
    digitalWrite(MotorPin4,LOW);
    exit(1); 
}

void init() {
    pinMode(MotorPin1, OUTPUT);
    pinMode(MotorPin2, OUTPUT);
    pinMode(MotorPin3, OUTPUT);
    pinMode(MotorPin4, OUTPUT);
}

void left() {
    digitalWrite(MotorPin1,HIGH);
    digitalWrite(MotorPin2,LOW);
    digitalWrite(MotorPin3,LOW);
    digitalWrite(MotorPin4,LOW);
}

void right() {
    digitalWrite(MotorPin1,LOW);
    digitalWrite(MotorPin2,HIGH);
    digitalWrite(MotorPin3,LOW);
    digitalWrite(MotorPin4,LOW);
}

void forward() {
    digitalWrite(MotorPin1,LOW);
    digitalWrite(MotorPin2,LOW);
    digitalWrite(MotorPin3,HIGH);
    digitalWrite(MotorPin4,LOW);
}

void backward() {
    digitalWrite(MotorPin1,LOW);
    digitalWrite(MotorPin2,LOW);
    digitalWrite(MotorPin3,LOW);
    digitalWrite(MotorPin4,HIGH);
}

void clean() {
    digitalWrite(MotorPin1,LOW);
    digitalWrite(MotorPin2,LOW);
    digitalWrite(MotorPin3,LOW);
    digitalWrite(MotorPin4,LOW);
}




int main() {
    if(wiringPiSetupGpio()==-1) {
        cout << "Setup wiring pi failed";
        return 1;
    }
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    init();

    while(true) {
        left();
        delay(5000);

        right();
        delay(5000);

        forward();
        delay(5000);

        backward();
        delay(5000);

        clean();
    }

    return 0;
}