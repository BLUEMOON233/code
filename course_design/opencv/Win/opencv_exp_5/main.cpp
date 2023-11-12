#include<iostream>
#include<opencv2/opencv.hpp>

cv::Mat Erode(cv::Mat& image, cv::Mat S) {
	cv::Mat ret = image.clone();
	//转为二值图像
	for (int r = 0; r < image.rows; r++) for (int c = 0; c < image.cols; c++) {
		if (image.at<uchar>(r, c) <= 127) image.at<uchar>(r, c) = 0;
		else image.at<uchar>(r, c) = 255;
	}

	int S_H = S.rows / 2, S_W = S.cols / 2;
	//侵蚀操作，若源图像中以该坐标为中心的结构元素像素值全部相符，则返回true，否则返回false
	auto erode = [&](int r, int c) -> bool {
		for (int y = 0; y < S.rows; y++) {
			for (int x = 0; x < S.cols; x++) {
				if (S.at<uchar>(y, x) == 255) continue;
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
				ret.at<uchar>(r, c) = 0;
			}
			else ret.at<uchar>(r, c) = 255;
		}
	}
	return ret;
}

cv::Mat Dilate(cv::Mat& image, cv::Mat& S_t) {
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
		if (image.at<uchar>(r, c) <= 127) image.at<uchar>(r, c) = 0;
		else image.at<uchar>(r, c) = 255;
	}

	int S_H = S.rows / 2, S_W = S.cols / 2;
	//侵蚀操作，若源图像中以该坐标为中心的结构元素像素值全部相符，则返回true，否则返回false
	auto erode = [&](int r, int c) -> bool {
		for (int y = 0; y < S.rows; y++) {
			for (int x = 0; x < S.cols; x++) {
				if (S.at<uchar>(y, x) == 255) continue;
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
				ret.at<uchar>(r, c) = 0;
			}
			else ret.at<uchar>(r, c) = 255;
		}
	}
	return ret;
}

cv::Mat Open(cv::Mat image, cv::Mat S) {
	cv::Mat ret = image.clone();
	ret = Erode(ret, S);
	ret = Dilate(ret, S);
	return ret;
}

cv::Mat Close(cv::Mat image, cv::Mat S) {
	cv::Mat ret = image.clone();
	ret = Dilate(ret, S);
	ret = Erode(ret, S);
	return ret;
}

int main() {
	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_erode = Erode(cells, circle);

	//cv::namedWindow("circle", cv::WINDOW_NORMAL);
	//cv::imshow("circle", circle);
	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_erode", cv::WINDOW_NORMAL);
	//cv::imshow("cells_erode", cells_erode);

	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_dilate = Dilate(cells, circle);

	//cv::namedWindow("circle", cv::WINDOW_NORMAL);
	//cv::imshow("circle", circle);
	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_dilate", cv::WINDOW_NORMAL);
	//cv::imshow("cells_dilate", cells_dilate);

	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_open = Open(cells, circle);

	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_open", cv::WINDOW_NORMAL);
	//cv::imshow("cells_open", cells_open);

	//cv::Mat circle = cv::imread("./circle.png", 0);
	//cv::Mat cells = cv::imread("./cells.png", 0);
	//cv::Mat cells_close = Close(cells, circle);

	//cv::namedWindow("cells", cv::WINDOW_NORMAL);
	//cv::imshow("cells", cells);
	//cv::namedWindow("cells_close", cv::WINDOW_NORMAL);
	//cv::imshow("cells_close", cells_close);

	cv::Mat sztx = cv::imread("./shuzituxiang.png", 0);
	cv::Mat rec = cv::imread("./rec.png", 0);
	cv::Mat sztx_erode = Erode(sztx, rec);			
	cv::Mat sztx_edge = sztx_erode - sztx;

	cv::namedWindow("sztx", cv::WINDOW_NORMAL);
	cv::imshow("sztx", sztx);
	cv::namedWindow("sztx_edge", cv::WINDOW_NORMAL);
	cv::imshow("sztx_edge", sztx_edge);

	cv::waitKey(0);
	return 0;
}