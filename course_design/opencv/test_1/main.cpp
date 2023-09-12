#include <opencv2/opencv.hpp>
using namespace cv;

//-----------------------------------------------------------------------------------------------
#define WINDOW_NAME_ORIGINAL "origin pic"  
double m = 0.5;
Mat srcImage, srcImage1;
//-----------------------------------------------------------------------------------------------
int main() {
	srcImage = imread("01.JPG");                          //项目文件夹下存放图片01.JPG
	namedWindow(WINDOW_NAME_ORIGINAL, WINDOW_AUTOSIZE);   //显示原始图
	resize(srcImage, srcImage1, Size(), m, m);            //图片太大，可以缩小显示
	imshow(WINDOW_NAME_ORIGINAL, srcImage1);

	waitKey(0);
	return 0;
}
