#include "opencv_exp_2.h"

opencv_exp_2::opencv_exp_2(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.PB_read, &QPushButton::clicked, [=]()mutable {
		QString imagePath = QFileDialog::getOpenFileName(nullptr, "选择图片", "./pic", "Images (*.png *.xpm *.jpg)");
		image = cv::imread(imagePath.toStdString());
		if (image.empty()) {
			return;
		}
		cv::Mat ori_image;
		cv::cvtColor(image, ori_image, cv::COLOR_BGR2RGB);
		QImage qImage(ori_image.data, ori_image.cols, ori_image.rows, ori_image.cols * ori_image.channels(), QImage::Format_RGB888);
		QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.LB_ori->size(), Qt::KeepAspectRatio));
		ui.LB_ori->setPixmap(pixmap);
		ui.LB_pix_ori->setText(QString::fromStdString(std::to_string(ori_image.cols) + "x" + std::to_string(ori_image.rows)));
		});

	connect(ui.PB_trans, &QPushButton::clicked, [=]()mutable {
		if (image.empty()) {
			return;
		}
		//输入平移参数
		int dx = ui.LE_dx->text().toInt();
		int dy = ui.LE_dy->text().toInt();
		//获得平移计算矩阵
		cv::Mat cal_mat = (cv::Mat_<double>(3, 3) << 1, 0, (dx > 0 ? dx : 0), 0, 1, (dy > 0 ? dy : 0), 0, 0, 1);
		//生成转化后的矩阵
		cv::Mat image_trans(image.rows + abs(dy), image.cols + abs(dx), image.type());
		//遍历像素，计算出平移后的像素位置并赋值
		for (int i = 0; i < image.rows; i++) for (int j = 0; j < image.cols; j++) {
			cv::Vec3d vec(j, i, 1);
			cv::Mat res = cal_mat * vec;
			image_trans.at<cv::Vec3b>(res.at<double>(1, 0), res.at<double>(0, 0)) = image.at<cv::Vec3b>(i, j);
		}
		//Qt显示图片操作
		cv::cvtColor(image_trans, image_trans, cv::COLOR_BGR2RGB);
		QImage qImage(image_trans.data, image_trans.cols, image_trans.rows, image_trans.cols * image_trans.channels(), QImage::Format_RGB888);
		QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.LB_aft->size(), Qt::KeepAspectRatio));
		ui.LB_aft->setPixmap(pixmap);
		ui.LB_pix_aft->setText(QString::fromStdString(std::to_string(image_trans.cols) + "x" + std::to_string(image_trans.rows)));
		});

	connect(ui.PB_scale, &QPushButton::clicked, [=]()mutable {
		if (image.empty()) {
			return;
		}
		//输入缩放因子
		double factor = ui.LE_scale_factor->text().toDouble();
		//获得缩放计算矩阵
		cv::Mat cal_mat = (cv::Mat_<double>(3, 3) << 1.0 / factor, 0, 0, 0, 1.0 / factor, 0, 0, 0, 1);
		//生成转化后的矩阵
		cv::Mat image_trans(image.rows * factor, image.cols * factor, image.type());
		//遍历像素，计算出缩放前的像素位置并赋值
		for (int i = 0; i < image_trans.rows; i++) for (int j = 0; j < image_trans.cols; j++) {
			cv::Vec3d vec(j, i, 1);
			cv::Mat res = cal_mat * vec;
			image_trans.at<cv::Vec3b>(i, j) = image.at<cv::Vec3b>(res.at<double>(1, 0), res.at<double>(0, 0));
		}
		//Qt显示图片操作
		cv::cvtColor(image_trans, image_trans, cv::COLOR_BGR2RGB);
		QImage qImage(image_trans.data, image_trans.cols, image_trans.rows, image_trans.cols * image_trans.channels(), QImage::Format_RGB888);
		QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.LB_aft->size(), Qt::KeepAspectRatio));
		ui.LB_aft->setPixmap(pixmap);
		ui.LB_pix_aft->setText(QString::fromStdString(std::to_string(image_trans.cols) + "x" + std::to_string(image_trans.rows)));
		});

	connect(ui.PB_spin, &QPushButton::clicked, [=]()mutable {
		if (image.empty()) {
			return;
		}
		//输入旋转角度
		double angle = ui.LE_spin->text().toDouble() / 180.0 * acos(-1);
		cv::Mat image_trans(image.rows * fabs(cos(angle)) + image.cols * fabs(sin(angle)), image.rows * fabs(sin(angle)) + image.cols * fabs(cos(angle)), image.type());
		//得到旋转前的图片中心
		int a = (image.rows - 1) / 2, b = (image.cols - 1) / 2;
		//得到旋转后的图片中心
		int c = (image_trans.rows - 1) / 2, d = (image_trans.cols - 1) / 2;
		cv::Mat cal_mat = (cv::Mat_<double>(3, 3) << cos(angle), -sin(angle), 0, sin(angle), cos(angle), 0, a - cos(angle) * c - sin(angle) * d, b + sin(angle) * c - cos(angle) * d, 1);
		//遍历像素，计算出旋转前的像素位置并赋值
		for (int i = 0; i < image_trans.rows; i++) for (int j = 0; j < image_trans.cols; j++) {
			cv::Vec3d vec(j, i, 1);
			cv::Mat res = vec.t() * cal_mat;
			if (res.at<double>(0, 0) < 0 || res.at<double>(0, 0) >= image.cols) continue;
			if (res.at<double>(0, 1) < 0 || res.at<double>(0, 1) >= image.rows) continue;
			image_trans.at<cv::Vec3b>(i, j) = image.at<cv::Vec3b>(res.at<double>(0, 1), res.at<double>(0, 0));
		}
		//Qt显示图片操作
		cv::cvtColor(image_trans, image_trans, cv::COLOR_BGR2RGB);
		QImage qImage(image_trans.data, image_trans.cols, image_trans.rows, image_trans.cols * image_trans.channels(), QImage::Format_RGB888);
		QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.LB_aft->size(), Qt::KeepAspectRatio));
		ui.LB_aft->setPixmap(pixmap);
		ui.LB_pix_aft->setText(QString::fromStdString(std::to_string(image_trans.cols) + "x" + std::to_string(image_trans.rows)));
		});

	connect(ui.PB_fix, &QPushButton::clicked, [=]()mutable {
		//设置畸变后的图形点位
		std::vector<cv::Point2f> srcCorners;
		srcCorners.emplace_back(cv::Point2f(46, 0));
		srcCorners.emplace_back(cv::Point2f(141, 0));
		srcCorners.emplace_back(cv::Point2f(0, image.rows - 1));
		srcCorners.emplace_back(cv::Point2f(image.cols - 1, image.rows - 1));
		//设置校正后的图片点位
		std::vector<cv::Point2f> dstCorners;
		dstCorners.emplace_back(cv::Point2f(0, 0));
		dstCorners.emplace_back(cv::Point2f(image.cols - 1, 0));
		dstCorners.emplace_back(cv::Point2f(0, image.rows - 1));
		dstCorners.emplace_back(cv::Point2f(image.cols - 1, image.rows - 1));
		//生成透视转化的计算矩阵
		cv::Mat perspectiveMatrix = cv::getPerspectiveTransform(srcCorners, dstCorners);
		cv::Mat image_corrected;
		//计算并校正
		cv::warpPerspective(image, image_corrected, perspectiveMatrix, image.size());
		//Qt显示图片操作
		cv::cvtColor(image_corrected, image_corrected, cv::COLOR_BGR2RGB);
		QImage qImage(image_corrected.data, image_corrected.cols, image_corrected.rows, image_corrected.cols * image_corrected.channels(), QImage::Format_RGB888);
		QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.LB_aft->size(), Qt::KeepAspectRatio));
		ui.LB_aft->setPixmap(pixmap);
		ui.LB_pix_aft->setText(QString::fromStdString(std::to_string(image_corrected.cols) + "x" + std::to_string(image_corrected.rows)));
		});
}

opencv_exp_2::~opencv_exp_2()
{}
