#include "motor.h"

namespace {
void sigHandler(int s){
    printf("Caught signal %d\n",s);
    Motor::Instance().clean();
    exit(1); 
}
} // namespace 



void Motor::left() {
    digitalWrite(MotorPin1_, HIGH);
    digitalWrite(MotorPin2_, LOW);
    digitalWrite(MotorPin3_, LOW);
    digitalWrite(MotorPin4_, LOW);
}

void Motor::right() {
    digitalWrite(MotorPin1_, LOW);
    digitalWrite(MotorPin2_, HIGH);
    digitalWrite(MotorPin3_, LOW);
    digitalWrite(MotorPin4_, LOW);
}

void Motor::forward() {
    digitalWrite(MotorPin1_, LOW);
    digitalWrite(MotorPin2_, LOW);
    digitalWrite(MotorPin3_, HIGH);
    digitalWrite(MotorPin4_, LOW);
}

void Motor::backward() {
    digitalWrite(MotorPin1_, LOW);
    digitalWrite(MotorPin2_, LOW);
    digitalWrite(MotorPin3_, LOW);
    digitalWrite(MotorPin4_, HIGH);
}

void Motor::clean() {
    digitalWrite(MotorPin1_, LOW);
    digitalWrite(MotorPin2_, LOW);
    digitalWrite(MotorPin3_, LOW);
    digitalWrite(MotorPin4_, LOW);
}

void Motor::loop() {
    left();
    delay(rotateTime_);
    clean();
    imgManager.capture();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    right();
    delay(rotateTime_);
    clean();
    imgManager.capture();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    forward();
    delay(rotateTime_);
    clean();
    imgManager.capture();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    backward();
    delay(rotateTime_);
    clean();
    imgManager.capture();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    imgManager.stitch();
}

Motor& Motor::Instance() {
    static Motor motor;
    return motor;
}

bool Motor::init(int MotorPin1, int MotorPin2, int MotorPin3, int MotorPin4) {
    if(isInited_) return true;
    MotorPin1_ = MotorPin1;
    MotorPin2_ = MotorPin2;
    MotorPin3_ = MotorPin3;
    MotorPin4_ = MotorPin4;
    if(wiringPiSetupGpio() == -1) {
        std::cout << "Setup wiring pi failed" << std::endl;
        return false;
    }
    pinMode(MotorPin1_, OUTPUT);
    pinMode(MotorPin2_, OUTPUT);
    pinMode(MotorPin3_, OUTPUT);
    pinMode(MotorPin4_, OUTPUT);
    handler_.registerSignalHandler(sigHandler);
    isInited_ = true;
    return true;
}
