#include<iostream>
#include<opencv2/opencv.hpp>

cv::Mat Linear_grayscale_trans(cv::Mat image_origin) {
	cv::Mat image_ret(image_origin.rows, image_origin.cols, image_origin.type());
	auto trans = [](int gray_val) -> int {
		//变换函数
		int ret = gray_val;
		//线性变化方程
		if (gray_val < 192) ret *= 239.0 / 191.0;
		else ret = (gray_val - 191) / 4 + 239;
		return ret;
		};
	for (int r = 0; r < image_origin.rows; r++) {
		for (int c = 0; c < image_origin.cols; c++) {
			int gray = image_origin.at<uchar>(r, c);
			image_ret.at<uchar>(r, c) = trans(gray);
			//将处理后的灰度值放入返回图像矩阵中。
		}
	}
	return image_ret;
}

cv::Mat Logarithmic_grayscale_trans(cv::Mat image_origin, double factor) {
	cv::Mat image_ret(image_origin.rows, image_origin.cols, image_origin.type());
	auto trans = [factor](int gray_val) -> int {
		int ret = factor * log10(gray_val + 1);
		return std::max(std::min(ret, 255), 0);
		};
	for (int r = 0; r < image_origin.rows; r++) {
		for (int c = 0; c < image_origin.cols; c++) {
			uchar gray = image_origin.at<uchar>(r, c);
			image_ret.at<uchar>(r, c) = trans(gray);
		}
	}
	return image_ret;
}

cv::Mat Histogram_equalization(cv::Mat image_origin) {
	cv::Mat image_ret(image_origin.rows, image_origin.cols, image_origin.type());
	std::vector<double> pHist(256, 0);
	//用于存储每个灰度值的频数
	for (int r = 0; r < image_origin.rows; r++) {
		for (int c = 0; c < image_origin.cols; c++) {
			uchar gray = image_origin.at<uchar>(r, c);
			pHist[gray] += 1.0;
			//记录频数
		}
	}
	for (auto& val : pHist) {
		val /= image_origin.cols * image_origin.rows;
		//将频数除以总像素数，计算分布函数。
	}
	for (int i = 1; i <= 255; i++) pHist[i] += pHist[i - 1];
	//计算累计分布函数。
	auto trans = [pHist](int gray_val) -> int {
		int ret = 255.0 * pHist[gray_val] + 0.5;
		//进行均衡化操作。
		return ret;
		};
	for (int r = 0; r < image_origin.rows; r++) {
		for (int c = 0; c < image_origin.cols; c++) {
			uchar gray = image_origin.at<uchar>(r, c);
			image_ret.at<uchar>(r, c) = trans(gray);
		}
	}
	return image_ret;
}

cv::Mat Mean_filtering(cv::Mat image_origin) {
	cv::Mat image_ret = image_origin.clone();
	//复制图像矩阵。
	cv::Mat mat_template(3, 3, CV_64FC1, cv::Scalar(1.0 / 9.0));
	//生成均值平滑计算模板
	auto filt = [mat_template](cv::Mat mat_sub) -> uchar {
		double ret = 0;
		for (int r = 0; r < mat_template.rows; r++) {
			for (int c = 0; c < mat_template.cols; c++) {
				ret += mat_template.at<double>(r, c) * mat_sub.at<uchar>(r, c);
			}
		}
		//使用模板对该坐标的像素点灰度值进行计算。
		return uchar(ret);
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

cv::Mat Median_filtering(cv::Mat image_origin) {
	cv::Mat image_ret = image_origin.clone();
	//复制图像矩阵。
	auto filt = [](cv::Mat mat_sub) -> uchar {
		std::vector<uchar> v;
		for (int r = 0; r < mat_sub.rows; r++) {
			for (int c = 0; c < mat_sub.cols; c++) {
				v.emplace_back(mat_sub.at<uchar>(r, c));
				//将子矩阵中的灰度值依次放入vector数组中。
			}
		}
		std::sort(v.begin(), v.end());
		//对数组进行排序。
		return v[4];
		//返回中值。
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

int main() {
	cv::Mat image_origin = cv::imread("./lena.tif", 0);
	cv::namedWindow("lena_origin", cv::WINDOW_NORMAL);
	cv::imshow("lena_origin", image_origin);

	//linear grayscale transformation:
	cv::Mat image_linear_grayscale = Linear_grayscale_trans(image_origin);
	//cv::namedWindow("lena_linear_grayscale", cv::WINDOW_NORMAL);
	//cv::imshow("lena_linear_grayscale", image_linear_grayscale);

	//logarithmic grayscale transformation:
	cv::Mat image_logarithmic_grayscale = Logarithmic_grayscale_trans(image_origin, 106);
	//cv::namedWindow("lena_logarithmic_grayscale", cv::WINDOW_NORMAL);
	//cv::imshow("lena_logarithmic_grayscale", image_logarithmic_grayscale);

	//Histogram equalization：
	cv::Mat image_histogram_equalization = Histogram_equalization(image_origin);
	//cv::namedWindow("lena_histogram_equalization", cv::WINDOW_NORMAL);
	//cv::imshow("lena_histogram_equalization", image_histogram_equalization);

	//Mean filtering:
	cv::Mat image_mean_filtering = Mean_filtering(image_origin);
	//cv::namedWindow("lena_mean_filtering", cv::WINDOW_NORMAL);
	//cv::imshow("lena_mean_filtering", image_mean_filtering);

	//median filtering:
	cv::Mat image_median_filtering = Median_filtering(image_origin);
	//cv::namedWindow("lena_median_filtering", cv::WINDOW_NORMAL);
	//cv::imshow("lena_median_filtering", image_median_filtering);

	cv::Mat image_sobel_sharpening = Sobel_sharpening(image_origin);
	//cv::imshow("lena_sobel_sharpening", image_sobel_sharpening);
	//cv::Mat image_sobel_sharpening2 = image_sobel_sharpening + image_origin;
	image_sobel_sharpening += image_origin;
	cv::namedWindow("lena_sobel_sharpening", cv::WINDOW_NORMAL);
	cv::imshow("lena_sobel_sharpening", image_sobel_sharpening);

	cv::waitKey(0);
	return 0;
}