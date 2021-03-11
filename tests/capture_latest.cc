#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <mutex>
using namespace cv;
using namespace std;


int main(int argc, char *argv[])
{
    cv::Mat buffer;
    cv::VideoCapture cap;
    std::mutex mutex;
    cap.open(0);
        if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    std::thread product([](cv::Mat& buf, cv::VideoCapture cap1, std::mutex& mtx){
        while (true) { // keep product the new image
            std::lock_guard<std::mutex> lock(mtx);
            cap1.grab();
        }
    }, std::ref(buffer), cap, std::ref(mutex));
    product.detach();
    int i;
    int cnt = 0;
    while (cnt < 4) { // process in the main thread
        cv::Mat tmp;
        {
            std::lock_guard<std::mutex> lock(mutex);
            // (void*)lock;
            // cap.retrieve(tmp);
            cap >> tmp;
        }

        if(!tmp.data)
            std::cout<<"null"<<i++<<std::endl;
        else {
            // cv::imshow("test", tmp);
            string name = to_string(cnt++) + ".jpg";
            imwrite(name ,tmp);
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return 0;
}