//
//  main.cpp
//  opencv_exp_1
//
//  Created by BLUEMOON on 2023/9/13.
//

#include <iostream>
#include <opencv2/opencv.hpp>

void exp_1() {
    cv::Mat pic = cv::imread("./lena.jpg"); //读入当前目录下名为lena的jpg格式图片，存入名为pic的Mat数据类型
    cv::namedWindow("output", cv::WINDOW_AUTOSIZE); //创建图片显示自动调整大小的窗口
    cv::imshow("output", pic); //显示矩阵pic
    cv::waitKey(0); //等待键盘输入
    cv::imwrite("./lena_copy.jpg", pic); //将矩阵pic写入当前目录下名为lena_copy的jpg格式文件。
}

void exp_2() {
    cv::Mat pic = cv::imread("./lena.jpg");
    //遍历方式1:
    for (int y = 0; y < pic.rows; ++y) {
        for (int x = 0; x < pic.cols; ++x) {
            cv::Vec3b pixel = pic.at<cv::Vec3b>(y, x); // 获取像素值
//            std::cout << pixel << '\n';
        }
    }
    //遍历方式2:
    // 指向第一行的像素数据
    for (cv::Vec3b* pixelPtr = pic.ptr<cv::Vec3b>(0); pixelPtr != pic.ptr<cv::Vec3b>(pic.rows); pixelPtr += pic.step1()) {
        for (int x = 0; x < pic.cols; ++x) {
            cv::Vec3b& pixel = pixelPtr[x]; // 获取像素值
//            std::cout << pixel << '\n';
        }
    }
    //遍历方式3:
    for (cv::Mat_<cv::Vec3b>::iterator it = pic.begin<cv::Vec3b>(); it != pic.end<cv::Vec3b>(); ++it) {
        cv::Vec3b& pixel = (*it); // 获取像素值
//        std::cout << pixel << '\n';
    }
}

void exp_3() {
    cv::Mat pic = cv::imread("./lena.jpg", 0); //读入灰度图片。
    cv::Mat enhanced_pic;
    cv::equalizeHist(pic, enhanced_pic); //调用直方图均衡化算法对灰度图片进行增强。
    cv::imshow("enhanced_lena", enhanced_pic);
    double alpha = 1.5;
    pic = pic * alpha;
    cv::imshow("lena", pic);
    cv::waitKey(0);
}

int main(int argc, const char * argv[]) {
//    exp_1();
//    exp_2();
    exp_3();
    return 0;
}
