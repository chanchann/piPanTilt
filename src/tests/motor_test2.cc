#include "../motor.h"

int main() {
    if(!Motor::Instance().init()) {
        std::cout << "motor init failed " << std::endl;
        return -1;
    }
}