#include<iostream>
#include<opencv2/opencv.hpp>

cv::Mat Erode(cv::Mat& image, cv::Mat S, int sel) {
	cv::Mat ret = image.clone();
	//转为二值图像
	for (int r = 0; r < image.rows; r++) for (int c = 0; c < image.cols; c++) {
		if (image.at<uchar>(r, c) <= 159) image.at<uchar>(r, c) = 0;
		else image.at<uchar>(r, c) = 255;
	}
	int S_H = S.rows / 2, S_W = S.cols / 2;
	//侵蚀操作，若源图像中以该坐标为中心的结构元素像素值全部相符，则返回true，否则返回false
	auto erode = [&](int r, int c) -> bool {
		for (int y = 0; y < S.rows; y++) {
			for (int x = 0; x < S.cols; x++) {
				if (S.at<uchar>(y, x) == sel) continue;
				if (image.at<uchar>(r + y, c + x) != S.at<uchar>(y, x))
					return false;
			}
		}
		return true;
		};
	for (int r = S_H; r < image.rows - S_H; r++) {
		for (int c = S_W; c < image.cols - S_W; c++) {
			int tar = erode(r - S_H, c - S_W);
			if (tar) {
				ret.at<uchar>(r, c) = 255 - sel;
			}
			else ret.at<uchar>(r, c) = sel;
		}
	}
	return ret;
}

cv::Mat Dilate(cv::Mat& image, cv::Mat& S_t, int sel) {
	cv::Mat ret = image.clone();
	cv::Mat S = S_t.clone();
	//图像反射
	int width = S.cols;
	int height = S.rows;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width / 2; x++) {
			uchar pixel1 = S_t.at<uchar>(y, x);
			uchar pixel2 = S_t.at<uchar>(y, width - x - 1);
			S.at<uchar>(y, x) = pixel2;
			S.at<uchar>(y, width - x - 1) = pixel1;
		}
	}
	//转为二值图像
	for (int r = 0; r < image.rows; r++) for (int c = 0; c < image.cols; c++) {
		if (image.at<uchar>(r, c) <= 159) image.at<uchar>(r, c) = 0;
		else image.at<uchar>(r, c) = 255;
	}

	int S_H = S.rows / 2, S_W = S.cols / 2;
	//侵蚀操作，若源图像中以该坐标为中心的结构元素像素值全部相符，则返回true，否则返回false
	auto erode = [&](int r, int c) -> bool {
		for (int y = 0; y < S.rows; y++) {
			for (int x = 0; x < S.cols; x++) {
				if (S.at<uchar>(y, x) == sel) continue;
				if (image.at<uchar>(r + y, c + x) == S.at<uchar>(y, x))
					return true;
			}
		}
		return false;
		};
	for (int r = S_H; r < image.rows - S_H; r++) {
		for (int c = S_W; c < image.cols - S_W; c++) {
			int tar = erode(r - S_H, c - S_W);
			if (tar) {
				ret.at<uchar>(r, c) = 255 - sel;
			}
			else ret.at<uchar>(r, c) = sel;
		}
	}
	return ret;
}

cv::Mat Open(cv::Mat& image, cv::Mat& S, int sel) {
	//对于原图像先进行腐蚀运算再进行膨胀运算
	cv::Mat ret = image.clone();
	ret = Erode(ret, S, sel);
	ret = Dilate(ret, S, sel);
	return ret;
}

cv::Mat Close(cv::Mat& image, cv::Mat& S, int sel) {
	//对于原图像先进行膨胀运算再进行腐蚀运算
	cv::Mat ret = image.clone();
	ret = Dilate(ret, S, sel);
	ret = Erode(ret, S, sel);
	return ret;
}

cv::Mat Skeletonization(cv::Mat& image, cv::Mat S, int sel) {
	cv::Mat ret = image.clone();
	cv::Mat now = image.clone();
	//初始化返回矩阵
	for (int r = 0; r < ret.rows; r++) {
		for (int c = 0; c < ret.cols; c++) {
			ret.at<uchar>(r, c) = 0;
		}
	}

	int lst = -1;
	for (int i = 0; i < 1000; i++) {
		//对图像进行腐蚀操作
		cv::Mat image_erode = Erode(now, S, sel);
		//查询当前图像像素点灰度不为0的点数量
		int cnt = cv::countNonZero(image_erode);
		//数量不发生变化时，则侵蚀操作不会对原图像做出改变，程序结束
		if (cnt == lst) break;
		lst = cnt;
		cv::Mat image_open = Dilate(image_erode, S, sel);
		//返回图像加上上一个操作图像减去开运算后的图像
		ret += (now - image_open);
		//更新操作图像
		now = image_erode;
	}
	return ret;
}

cv::Mat get_image_edge(cv::Mat& image, cv::Mat S, int sel) {
	//对图像进行侵蚀操作
	cv::Mat image_erode = Erode(image, S, 0);
	//原图像减去侵蚀操作
	cv::Mat image_edge = image - image_erode;
	return image_edge;
}


int main() {
	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_erode = Erode(cells, circle, 255);

	//cv::namedWindow("circle", cv::WINDOW_NORMAL);
	//cv::imshow("circle", circle);
	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_erode", cv::WINDOW_NORMAL);
	//cv::imshow("cells_erode", cells_erode);

	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_dilate = Dilate(cells, circle, 255);
	//cv::namedWindow("circle", cv::WINDOW_NORMAL);
	//cv::imshow("circle", circle);
	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_dilate", cv::WINDOW_NORMAL);
	//cv::imshow("cells_dilate", cells_dilate);

	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_open = Open(cells, circle, 255);
	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_open", cv::WINDOW_NORMAL);
	//cv::imshow("cells_open", cells_open);

	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_close = Close(cells, circle, 255);

	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_close", cv::WINDOW_NORMAL);
	//cv::imshow("cells_close", cells_close);

	//cv::Mat sztx = cv::imread("./shuzituxiang.png", 0);
	//cv::Mat rec = cv::imread("./rec.png", 0);

	//cv::Mat sztx_edge = get_image_edge(sztx, rec, 0);
	//cv::namedWindow("sztx", cv::WINDOW_NORMAL);
	//cv::imshow("sztx", sztx);
	//cv::namedWindow("sztx_edge", cv::WINDOW_NORMAL);
	//cv::imshow("sztx_edge", sztx_edge);
	//cv::Mat sztx_skeleton = Skeletonization(sztx, rec, 0);
	//cv::namedWindow("sztx", cv::WINDOW_NORMAL);
	//cv::imshow("sztx", sztx);
	//cv::namedWindow("sztx_skeleton", cv::WINDOW_NORMAL);
	//cv::imshow("sztx_skeleton", sztx_skeleton);

	cv::Mat noise = cv::imread("./noise.png", 0);
	cv::Mat fixed = cv::imread("./fixed.png", 0);

	//对图像先进行开运算
	cv::Mat final = Open(noise, fixed, 255);
	//再对图像进行闭运算
	final = Close(final, fixed, 255);

	cv::namedWindow("noise", cv::WINDOW_NORMAL);
	cv::imshow("noise", noise);
	cv::namedWindow("final", cv::WINDOW_NORMAL);
	cv::imshow("final", final);


	cv::waitKey(0);
	return 0;
}