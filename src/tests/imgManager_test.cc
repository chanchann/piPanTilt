#include "../imgManager.h"
#include <chrono>
#include <thread>

int main() {
    ImagManager imgManager;
    imgManager.capture();
    std::cout << "capture 1" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    imgManager.capture();
    std::cout << "capture 2" << std::endl;
    // imgManager.capture(4);
    imgManager.stitch();
}