#ifndef IMGMANAGER_H
#define IMGMANAGER_H
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <opencv2/imgcodecs.hpp> 
#include <opencv2/stitching.hpp>

using namespace cv;

class ImagManager {
public:
    ImagManager();
    void capture(int num = 1);
    void stitch();
private:
    // void cleanVedioBuf(cv::VideoCapture *invc);
private:
    VideoCapture capture_;
    std::vector<Mat> imgs_;
    int idx_ = 0;
    Stitcher::Mode mode_;
    std::mutex mutex_;

};


#endif // IMGMANAGER_H