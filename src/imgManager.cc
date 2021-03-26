#include "imgManager.h"

void ImagManager::capture(int num) {
    int cnt = 0;
    while(cnt < num) {
        Mat frame;
        {
            std::lock_guard<std::mutex> lock(mutex_);
            // capture_.read(frame);
            // capture_.retrieve(frame);
            capture_ >> frame;
        }
        if(frame.empty()) {
            std::cout << "no data" << std::endl;
        } else {
            // imgs_.emplace_back(frame);
            std::time_t t = std::time(0);
            std::string name = "cap" + std::to_string(cnt++) + "_" + std::to_string(t) + ".jpg";
            imwrite(name, frame); // for test
            imgName_.push_back(name);
        }
    }

}

void ImagManager::stitch() {
    Mat pano; 
    Ptr<Stitcher> stitcher = Stitcher::create(mode_); 
    Stitcher::Status status = stitcher->stitch(imgs_, pano); 
    if (status != Stitcher::OK) { 
        std::cout << "Can't stitch images\n"; 
        return; 
    } 
    std::string name = std::to_string(idx_++) + ".jpg";
    imwrite(name, pano); 
    imgs_.clear();
    std::vector<Mat>().swap(imgs_);
}

void ImagManager::stitchVr() {
    std::string parseArgs = "./stitch_detail";
    std::vector<std::string> imgName = {"1.jpg", "2.jpg", "3.jpg"};
    for(auto img: imgName_) {
        parseArgs = parseArgs + " " + img;
    }
    parseArgs += " --warp spherical";
    // std::cout << parseArgs << std::endl;;
    std::system(parseArgs.c_str());
}


ImagManager::ImagManager() 
    : mode_(Stitcher::PANORAMA) {
    capture_.open(0);
    if (!capture_.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
        return;
    }
    // 解决buf问题
    th = std::move(std::thread([](VideoCapture cap, std::mutex& mtx) {
        while(true) {
            std::lock_guard<std::mutex> lock(mtx);
            cap.grab();
        }
    }, capture_, std::ref(mutex_)));
}

ImagManager::~ImagManager() {
    th.join();
}
