#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <stdlib.h>
using namespace cv;
using namespace std;

int main() {
	//读取视频或摄像头
	VideoCapture capture;
    capture.open(0);
    capture.set(cv::CAP_PROP_BUFFERSIZE, 1);
    if (!capture.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    int cnt = 1;
	while (true) {
		Mat frame;
		// capture >> frame;
        capture.read(frame);
        string name = "cap" + to_string(cnt++) + ".jpg";
		imwrite(name, frame);
        cout << "capture" << endl;
        // sleep(5);
        this_thread::sleep_for(chrono::seconds(5));
        if(cnt == 5) break;
	}
	return 0;
}
