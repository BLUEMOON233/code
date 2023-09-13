//
//  main.cpp
//  opencv_for_mac_test_1
//
//  Created by BLUEMOON on 2023/9/13.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main(int argc, const char * argv[]) {
    cv::Mat pic = cv::imread("/Users/bluemoon/develop/code/course_design/opencv/opencv_for_mac_test_1/doggy.jpg");
    cv::namedWindow("doggy pic", cv::WINDOW_AUTOSIZE);
    cv::imshow("doggy pic", pic);
    cv::waitKey(0);
    return 0;
}
