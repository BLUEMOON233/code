#include <iostream>
#include <opencv2/opencv.hpp>

void exp_1() {
	cv::Mat pic = cv::imread("lena.jpg"); //读入当前目录下名为lena的jpg格式图片，存入名为pic的Mat数据类型
	cv::namedWindow("output", cv::WINDOW_AUTOSIZE); //创建图片显示自动调整大小的窗口
	cv::imshow("output", pic); //显示矩阵pic
	cv::waitKey(0); //等待键盘输入
	cv::imwrite("lena_copy.jpg", pic); //将矩阵pic写入当前目录下名为lena_copy的jpg格式文件。
}

void exp_2() {
	cv::Mat pic = cv::imread("lena.jpg");
	//遍历方式1:(使用.at<>()方法)
	for (int y = 0; y < pic.rows; ++y) {
		for (int x = 0; x < pic.cols; ++x) {
			cv::Vec3b pixel = pic.at<cv::Vec3b>(y, x); // 获取像素值
			//std::cout << pixel << '\n';
		}
	}
	//遍历方式2:(使用指针访问像素)
	// 指向第一行的像素数据
	for (cv::Vec3b* pixelPtr = pic.ptr<cv::Vec3b>(0); pixelPtr != pic.ptr<cv::Vec3b>(pic.rows); pixelPtr += pic.step1()) {
		for (int x = 0; x < pic.cols; ++x) {
			cv::Vec3b& pixel = pixelPtr[x]; // 获取像素值
			//std::cout << pixel << '\n';
		}
	}
	//遍历方式3:(使用迭代器访问像素)
	for (cv::Mat_<cv::Vec3b>::iterator it = pic.begin<cv::Vec3b>(); it != pic.end<cv::Vec3b>(); ++it) {
		cv::Vec3b& pixel = (*it); // 获取像素值
		//std::cout << pixel << '\n';
	}
}

void exp_3() {
	cv::Mat pic = cv::imread("lena.jpg", 0); //读入灰度图片。
	cv::Mat enhanced_pic;
	cv::equalizeHist(pic, enhanced_pic); //调用直方图均衡化算法对灰度图片进行增强。
	cv::imshow("enhanced_lena", enhanced_pic); //显示直方图均衡化算法增强后灰度图片。
	double alpha = 1.5;
	enhanced_pic = pic * alpha; //显示线性灰度增强。
	cv::imshow("lena", enhanced_pic); //显示线性灰度增强图片。
	cv::waitKey(0);
}

void exp_4() { //Spicy and Salted lena
	cv::Mat pic = cv::imread("lena.jpg");
	int numNoisePoints = 300; //设置椒盐噪声像素点的数量
	for (int i = 0; i < numNoisePoints; i++) {
		int x = rand() % pic.cols; // 随机生成横坐标
		int y = rand() % pic.rows; // 随机生成纵坐标
		if (rand() % 2 == 0) { // 随机选择噪声类型，椒或盐
			pic.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 0); // 添加椒噪声（黑色像素）
		}
		else {
			pic.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 255, 255); // 添加盐噪声（白色像素）
		}
	}
	cv::namedWindow("Spicy and Salted Lena", cv::WINDOW_NORMAL); 
	cv::imshow("Spicy and Salted Lena", pic); //显示加入椒盐噪声后的图片
	cv::waitKey(0);
}

void exp_5() {
	cv::Mat ori_pic = cv::imread("lena.jpg"); //读入彩度图片。
	double alpha = 1.5; //亮度因子。
	cv::Mat bri_pic = ori_pic * alpha; //实现彩色图片增量。
	cv::namedWindow("origin picture", cv::WINDOW_NORMAL);
	cv::imshow("origin picture", ori_pic); //显示原图片
	cv::namedWindow("brightened picture", cv::WINDOW_NORMAL);
	cv::imshow("brightened picture", bri_pic); //显示增量后图片
	cv::waitKey(0);
}

int main(int argc, const char* argv[]) {
	//exp_1();
	//exp_2();
	//exp_3();
	//exp_4();
	exp_5();
	return 0;
}
