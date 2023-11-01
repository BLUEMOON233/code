#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2\imgproc\types_c.h>
#include<opencv2/imgproc/imgproc_c.h>

const double PI = acos(-1);

cv::Mat Otsu(cv::Mat image) {
	cv::Mat ret = image.clone();
	std::vector<double> w(256, 0), pre_w(256, 0), ave(256, 0.0);
	//设置分布函数、累积分布函数、平均灰度数组。
	for (int r = 0; r < image.rows; r++) {
		for (int c = 0; c < image.cols; c++) {
			w[image.at<uchar>(r, c)] += 1.0;
			//计算分布函数
		}
	}
	for (auto& x : w) x /= (image.rows * image.cols);
	for (int i = 0; i < 256; i++) ave[i] = w[i] * i;
	//计算平均灰度
	for (int i = 1; i < 256; i++) ave[i] += ave[i - 1];
	pre_w[0] = w[0];
	for (int i = 1; i < 256; i++) pre_w[i] = w[i] + pre_w[i - 1];
	double min_val = 1e18, min_T = 0;
	for (int T = 1; T <= 254; T++) {
		//计算不同阈值下的类间方差
		double w1 = pre_w[T], w2 = pre_w[255] - pre_w[T];
		double ave1 = ave[T] / w1, ave2 = (ave[255] - ave[T]) / w2;
		double val1 = 0.0, val2 = 0.0;
		for (int j = 0; j <= T; j++) {
			val1 += (j - ave1) * (j - ave1) * w[j] / w1;
		}
		for (int j = T + 1; j <= 255; j++) {
			val2 += (j - ave2) * (j - ave2) * w[j] / w2;
		}
		//更新最小类间方差
		if (w1 * val1 + w2 * val2 < min_val) {
			min_val = w1 * val1 + w2 * val2;
			min_T = T;
		}
	}
	for (int r = 0; r < image.rows; r++) {
		for (int c = 0; c < image.cols; c++) {
			ret.at<uchar>(r, c) = image.at<uchar>(r, c) > min_T ? 255 : 0;
		}
	}
	return ret;
}

cv::Mat Sobel_sharpening(cv::Mat image_origin) {
	cv::Mat image_ret(image_origin.rows, image_origin.cols, image_origin.type());
	cv::Mat mat_template_x = (cv::Mat_<double>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1) * (1.0 / 4);
	cv::Mat mat_template_y = (cv::Mat_<double>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1) * (1.0 / 4);
	//横向和纵向的sobel算子模板
	auto filt = [mat_template_x, mat_template_y](cv::Mat mat_sub) -> uchar {
		double gx = 0, gy = 0;
		for (int r = 0; r < mat_sub.rows; r++) {
			for (int c = 0; c < mat_sub.cols; c++) {
				gx += mat_template_x.at<double>(r, c) * mat_sub.at<uchar>(r, c);
				gy += mat_template_y.at<double>(r, c) * mat_sub.at<uchar>(r, c);
				//分别计算横向和纵向的梯度。
			}
		}
		double ret = abs(gx) + abs(gy);
		//根据横纵梯度计算当前锐化后的灰度值。
		return std::max(std::min(int(ret), 255), 0);
		};

	for (int r = 1; r < image_origin.rows - 1; r++) {
		for (int c = 1; c < image_origin.cols - 1; c++) {
			cv::Mat mat_sub = image_origin(cv::Range(r - 1, r + 2), cv::Range(c - 1, c + 2));
			//生成以当前坐标为中心的3x3矩阵。
			image_ret.at<uchar>(r, c) = filt(mat_sub);
		}
	}
	return image_ret;
}

cv::Mat Prewitt_sharpening(cv::Mat image_origin) {
	cv::Mat image_ret(image_origin.rows, image_origin.cols, image_origin.type());
	cv::Mat mat_template_x = (cv::Mat_<double>(3, 3) << -1, 0, 1, -1, 0, 1, -1, 0, 1) * (1.0 / 3);
	cv::Mat mat_template_y = (cv::Mat_<double>(3, 3) << -1, -1, -1, 0, 0, 0, 1, 1, 1) * (1.0 / 3);
	//横向和纵向的prewitt算子模板
	auto filt = [mat_template_x, mat_template_y](cv::Mat mat_sub) -> uchar {
		double gx = 0, gy = 0;
		for (int r = 0; r < mat_sub.rows; r++) {
			for (int c = 0; c < mat_sub.cols; c++) {
				gx += mat_template_x.at<double>(r, c) * mat_sub.at<uchar>(r, c);
				gy += mat_template_y.at<double>(r, c) * mat_sub.at<uchar>(r, c);
				//分别计算横向和纵向的梯度。
			}
		}
		double ret = abs(gx) + abs(gy);
		//根据横纵梯度计算当前锐化后的灰度值。
		return std::max(std::min(int(ret), 255), 0);
		};

	for (int r = 1; r < image_origin.rows - 1; r++) {
		for (int c = 1; c < image_origin.cols - 1; c++) {
			cv::Mat mat_sub = image_origin(cv::Range(r - 1, r + 2), cv::Range(c - 1, c + 2));
			//生成以当前坐标为中心的3x3矩阵。
			image_ret.at<uchar>(r, c) = filt(mat_sub);
		}
	}
	return image_ret;
}

cv::Mat Roberts_sharpening(cv::Mat image_origin) {
	cv::Mat image_ret(image_origin.rows, image_origin.cols, image_origin.type());
	cv::Mat mat_template_x = (cv::Mat_<double>(3, 3) << -1, -1, 0, -1, 0, 1, 0, 1, 1) * (1.0 / 3);
	cv::Mat mat_template_y = (cv::Mat_<double>(3, 3) << 0, 1, 1, -1, 0, 1, -1, -1, 0) * (1.0 / 3);
	//横向和纵向的roberts算子模板
	auto filt = [mat_template_x, mat_template_y](cv::Mat mat_sub) -> uchar {
		double gx = 0, gy = 0;
		for (int r = 0; r < mat_sub.rows; r++) {
			for (int c = 0; c < mat_sub.cols; c++) {
				gx += mat_template_x.at<double>(r, c) * mat_sub.at<uchar>(r, c);
				gy += mat_template_y.at<double>(r, c) * mat_sub.at<uchar>(r, c);
				//分别计算横向和纵向的梯度。
			}
		}
		double ret = abs(gx) + abs(gy);
		//根据横纵梯度计算当前锐化后的灰度值。
		return std::max(std::min(int(ret), 255), 0);
		};

	for (int r = 1; r < image_origin.rows - 1; r++) {
		for (int c = 1; c < image_origin.cols - 1; c++) {
			cv::Mat mat_sub = image_origin(cv::Range(r - 1, r + 2), cv::Range(c - 1, c + 2));
			//生成以当前坐标为中心的3x3矩阵。
			image_ret.at<uchar>(r, c) = filt(mat_sub);
		}
	}
	return image_ret;
}

cv::Mat LOG(cv::Mat image_origin) {
	cv::Mat image_ret(image_origin.rows, image_origin.cols, image_origin.type());
	cv::Mat mat_template = (cv::Mat_<double>(5, 5) <<
		-2, -4, -4, -4, -2,
		-4, 0, 8, 0, -4,
		-4, 8, 24, 8, -4,
		-4, 0, 8, 0, -4,
		-2, -4, -4, -4, -2)
		* (1.0 / 4);
	//高斯拉普拉斯模板
	auto filt = [mat_template](cv::Mat mat_sub) -> uchar {
		double gx = 0, gy = 0;
		for (int r = 0; r < mat_sub.rows; r++) {
			for (int c = 0; c < mat_sub.cols; c++) {
				gx += mat_template.at<double>(r, c) * mat_sub.at<uchar>(r, c);
				//分别计算横向和纵向的梯度。
			}
		}
		double ret = abs(gx);
		//根据横纵梯度计算当前锐化后的灰度值。
		return ret >= 255 ? 255 : 0;
		};

	for (int r = 2; r < image_origin.rows - 2; r++) {
		for (int c = 2; c < image_origin.cols - 2; c++) {
			cv::Mat mat_sub = image_origin(cv::Range(r - 2, r + 3), cv::Range(c - 2, c + 3));
			//生成以当前坐标为中心的5x5矩阵。
			image_ret.at<uchar>(r, c) = filt(mat_sub);
		}
	}
	return image_ret;
}

cv::Mat Canny(cv::Mat image) {
	cv::Mat ret = image.clone();
	cv::Mat template_gaussian = (cv::Mat_<double>(5, 5) <<
		6.58573e-006, 0.000424781, 0.00170354, 0.000424781, 6.58573e-006,
		0.000424781, 0.0273984, 0.109878, 0.0273984, 0.000424781,
		0.00170354, 0.109878, 0.440655, 0.109878, 0.00170354,
		0.000424781, 0.0273984, 0.109878, 0.0273984, 0.000424781,
		6.58573e-006, 0.000424781, 0.00170354, 0.000424781, 6.58573e-006);
	//高斯平滑模板
	auto cal_gaussian = [template_gaussian](cv::Mat mat_sub) -> int {
		double ret = 0.0;
		for (int r = 0; r < mat_sub.rows; r++) {
			for (int c = 0; c < mat_sub.cols; c++) {
				ret += template_gaussian.at<double>(r, c) * mat_sub.at<uchar>(r, c);
			}
		}
		//使用模板计算高斯平滑后的像素灰度值
		return int(ret);
		};
	for (int r = 2; r < image.rows - 2; r++) {
		for (int c = 2; c < image.rows - 2; c++) {
			cv::Mat mat_sub = image(cv::Range(r - 2, r + 3), cv::Range(c - 2, c + 3));
			//生成以当前坐标为中心的3x3矩阵。
			ret.at<uchar>(r, c) = cal_gaussian(mat_sub);
		}
	}
	//sobel计算梯度：
	cv::Mat mat_template_x = (cv::Mat_<double>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1) * (1.0 / 4);
	cv::Mat mat_template_y = (cv::Mat_<double>(3, 3) << 1, 2, 1, 0, 0, 0, -1, -2, -1) * (1.0 / 4);
	std::vector<std::vector<double>> gx(image.rows, std::vector<double>(image.cols, 0.0));
	std::vector<std::vector<double>> gy(image.rows, std::vector<double>(image.cols, 0.0));
	std::vector<std::vector<double>> g(image.rows, std::vector<double>(image.cols, 0.0));
	//定义水平、垂直、整体梯度数组
	for (int r = 2; r < image.rows - 2; r++) {
		for (int c = 2; c < image.cols - 2; c++) {
			cv::Mat mat_sub = ret(cv::Range(r - 1, r + 2), cv::Range(c - 1, c + 2));
			for (int y = 0; y < mat_sub.rows; y++) {
				for (int x = 0; x < mat_sub.cols; x++) {
					gx[r][c] += mat_template_x.at<double>(y, x) * mat_sub.at<uchar>(y, x);
					gy[r][c] += mat_template_y.at<double>(y, x) * mat_sub.at<uchar>(y, x);
					g[r][c] = sqrt(gx[r][c] * gx[r][c] + gy[r][c] * gy[r][c]);
				}
			}
		}
	}
	//非最大值抑制（NMS）:
	auto NMS = [&gx, &gy, &g](int r, int c) -> int {
		double angle = atan(gy[r][c] / gx[r][c]);
		double left = 0, mid = mid = g[r][c], right = 0;
		//计算不同梯度的方向
		if (fabs(angle) <= PI / 8.0) left = g[r][c - 1], right = g[r][c + 1]; //水平
		else if (fabs(angle) > PI * 3.0 / 8.0) left = g[r - 1][c], right = g[r + 1][c]; //垂直
		else if (PI / 8.0 < angle && angle <= PI * 3.0 / 8.0) left = g[r - 1][c - 1], right = g[r + 1][c + 1]; //斜率为1
		else left = g[r - 1][c + 1], right = g[r + 1][c - 1]; //斜率为-1
		return (left < mid && right < mid) ? int(mid) : 0;
		};
	for (int r = 2; r < image.rows - 2; r++) {
		for (int c = 2; c < image.cols - 2; c++) {
			ret.at<uchar>(r, c) = std::min(NMS(r, c), 255);
		}
	}
	//双阈值划分：
	for (int r = 2; r < image.rows - 2; r++) {
		for (int c = 2; c < image.cols - 2; c++) {
			if (ret.at<uchar>(r, c) >= 64) ret.at<uchar>(r, c) = 255;
			else if (ret.at<uchar>(r, c) >= 16) ret.at<uchar>(r, c) = 128;
			else ret.at<char>(r, c) = 0;
		}
	}
	for (int r = 2; r < image.rows - 2; r++) {
		for (int c = 2; c < image.cols - 2; c++) {
			if (ret.at<uchar>(r, c) == 255) {
				for (int y = r - 1; y <= r + 1; y++) for (int x = c - 1; x <= c + 1; x++) if (ret.at<uchar>(y, x) == 128)
					ret.at<uchar>(y, x) = 255;
			}
			else if (ret.at<uchar>(r, c) == 128) {
				for (int y = r - 1; y <= r + 1; y++) for (int x = c - 1; x <= c + 1; x++) if (ret.at<uchar>(y, x) == 255)
					ret.at<uchar>(r, c) = 255;
			}
		}
	}
	for (int r = 2; r < image.rows - 2; r++) {
		for (int c = 2; c < image.cols - 2; c++) {
			if (ret.at<uchar>(r, c) == 128) {
				ret.at<uchar>(r, c) = 0;
			}
		}
	}
	return ret;
}

cv::Mat Grow(cv::Mat image) {
	cv::Mat ret(image.rows, image.cols, image.type());
	for (int r = 0; r < image.rows; r++) {
		for (int c = 0; c < image.cols; c++) {
			ret.at<uchar>(r, c) = 0;
		}
	}
	//选择初始种子点。
	int min_val = 256, min_r = 0, min_c = 0;
	for (int r = 0; r < image.rows; r++) for (int c = 0; c < image.cols; c++)
		if (image.at<uchar>(r, c) < min_val) {
			min_val = image.at<uchar>(r, c);
			min_r = r, min_c = c;
		}

	std::queue<std::pair<int, int>> que;
	ret.at<uchar>(min_r, min_c) = 255;
	que.push({ min_r, min_c });
	int gap = 6;
	//设置相似性准则
	while (!que.empty()) {
		auto [r, c] = que.front();
		que.pop();
		//每次选取新的种子点
		if (r + 1 < image.rows && ret.at<uchar>(r + 1, c) == 0)
			if (abs(image.at<char>(r, c) - image.at<char>(r + 1, c)) <= gap) {
				ret.at<uchar>(r + 1, c) = 255;
				que.push({ r + 1, c });
			}
		if (c + 1 < image.cols && ret.at<uchar>(r, c + 1) == 0)
			if (abs(image.at<char>(r, c) - image.at<char>(r, c + 1)) <= gap) {
				ret.at<uchar>(r, c + 1) = 255;
				que.push({ r, c + 1 });
			}
		if (r - 1 >= 0 && ret.at<uchar>(r - 1, c) == 0)
			if (abs(image.at<char>(r, c) - image.at<char>(r - 1, c)) <= gap) {
				ret.at<uchar>(r - 1, c) = 255;
				que.push({ r - 1, c });
			}
		if (c - 1 >= 0 && ret.at<uchar>(r, c - 1) == 0)
			if (abs(image.at<char>(r, c) - image.at<char>(r, c - 1)) <= gap) {
				ret.at<uchar>(r, c - 1) = 255;
				que.push({ r, c - 1 });
			}
	}
	return ret;
}

cv::Mat Hough_trans(cv::Mat image) {
	cv::Mat image_canny, ret;
	//使用Canny算法预处理图像。
	Canny(image, image_canny, 50, 200, 3);
	cvtColor(image_canny, ret, CV_GRAY2BGR);
	std::vector <cv::Vec2f> lines;
	//Hough算法中标注线数组
	HoughLines(image_canny, lines, 1, CV_PI / 180, 150, 0, 0);
	//调用Hough算法接口，输入canny处理后的图像。
	for (int i = 0; i < lines.size(); i++) {
		float rho = lines[i][0], theta = lines[i][1];
		cv::Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(ret, pt1, pt2, cv::Scalar(0, 0, 255), 1, CV_AA);
		//将hough结果标注在原图上。
	}
	return ret;
}

int main() {
	//cv::Mat image_origin = cv::imread("./cameraman.tif", 0);
	//cv::namedWindow("cameraman_origin", cv::WINDOW_NORMAL);
	//cv::imshow("cameraman_origin", image_origin);

	//cv::Mat image_otsu = Otsu(image_origin);
	//cv::imshow("cameraman_otsu", image_otsu);

	//cv::Mat image_sobel = Sobel_sharpening(image_origin);
	//cv::namedWindow("cameraman_sobel", cv::WINDOW_NORMAL);
	//cv::imshow("cameraman_sobel", image_sobel);

	//cv::Mat image_prewitt = Prewitt_sharpening(image_origin);
	//cv::namedWindow("cameraman_prewitt", cv::WINDOW_NORMAL);
	//cv::imshow("cameraman_prewitt", image_prewitt);

	//cv::Mat image_roberts = Roberts_sharpening(image_origin);
	//cv::namedWindow("cameraman_roberts", cv::WINDOW_NORMAL);
	//cv::imshow("cameraman_roberts", image_roberts);

	//cv::Mat image_LOG = LOG(image_origin);
	//cv::namedWindow("cameraman_log", cv::WINDOW_NORMAL);
	//cv::imshow("cameraman_log", image_LOG);

	//cv::Mat image_Canny = Canny(image_origin);
	//cv::namedWindow("cameraman_canny", cv::WINDOW_NORMAL);
	//cv::imshow("cameraman_canny", image_Canny);

	//cv::Mat image_Grow = Grow(image_origin);
	//cv::namedWindow("cameraman_grow", cv::WINDOW_NORMAL);
	//cv::imshow("cameraman_grow", image_Grow);

	cv::Mat image_origin = cv::imread("./road.png", 0);
	cv::namedWindow("road_origin", cv::WINDOW_NORMAL);
	cv::imshow("road_origin", image_origin);

	cv::Mat image_Hough = Hough_trans(image_origin);
	cv::namedWindow("road_hough", cv::WINDOW_NORMAL);
	cv::imshow("road_hough", image_Hough);

	cv::waitKey(0);
	return 0;
}