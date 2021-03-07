#ifndef MOTOR_H
#define MOTOR_H

#include <iostream> 
#include <wiringPi.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <functional>
#include <chrono>
#include <thread>
#include "SignalHandler.h"
#include "imgManager.h"

// singleton
class Motor {
public:
    static Motor& Instance();
    bool init(int MotorPin1 = 26, int MotorPin2 = 19, int MotorPin3 = 13, int MotorPin4 = 6);
    void left();
    void right();
    void forward();
    void backward();
    void clean();
    void loop();
    void setMotorPin1(int pin) { MotorPin1_ = pin; }
    void setMotorPin2(int pin) { MotorPin2_ = pin; }
    void setMotorPin3(int pin) { MotorPin3_ = pin; }
    void setMotorPin4(int pin) { MotorPin4_ = pin; }
    void setRotateTime(int time) { rotateTime_ = time;}
    
    int getMotorPin1() const { return MotorPin1_; }
    int getMotorPin2() const { return MotorPin2_; }
    int getMotorPin3() const { return MotorPin3_; }
    int getMotorPin4() const { return MotorPin4_; }
    
private:
    Motor() = default;
    ~Motor() = default;
    Motor(const Motor&) = delete;
    Motor& operator=(const Motor&) = delete;
private:
    // BCM
    int MotorPin1_;
    int MotorPin2_;
    int MotorPin3_;
    int MotorPin4_;
    SignalHandler handler_;
    bool isInited_ = false; // amomic   
    ImagManager imgManager;
    int rotateTime_ = 5000;
};


#endif