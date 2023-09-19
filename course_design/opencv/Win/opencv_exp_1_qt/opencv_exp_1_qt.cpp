#include "opencv_exp_1_qt.h"

opencv_exp_1_qt::opencv_exp_1_qt(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.brightness_slider->setRange(0, 100);
	ui.blur_slider->setRange(1, 20);//设置滑动条的范围

	cv::Mat ori_image = cv::imread("./lena.jpg"); //读取图片
	cv::Mat image; //副本数据 
	double brightness_factor = 1; //亮度因子
	int kernel_size = 1; //滤波器大小

	//初始化操作：
	cv::cvtColor(ori_image, image, cv::COLOR_BGR2RGB);
	image.convertTo(image, -1, brightness_factor, 0);
	QImage qImage(image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);
	QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.image_label->size(), Qt::KeepAspectRatio));
	ui.image_label->setPixmap(pixmap);

	if (!ori_image.empty()) {
		QObject::connect(ui.brightness_slider, &QSlider::valueChanged, [=, &brightness_factor, &kernel_size](int value)mutable {
			brightness_factor = double(value) / 20;//根据滑动条计算亮度因子
			cv::cvtColor(ori_image, image, cv::COLOR_BGR2RGB);//将原始图片的BGR格式转化为RGB格式
			image.convertTo(image, -1, brightness_factor, 0);//修改图片的亮度
			cv::blur(image, image, cv::Size(kernel_size, kernel_size));//模糊操作
			QImage qImage(image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);//将opencv格式转化为Qimage格式
			QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.image_label->size(), Qt::KeepAspectRatio));//调整大小
			ui.image_label->setPixmap(pixmap);//将图片放入Qlabel控件中
			});

		QObject::connect(ui.blur_slider, &QSlider::valueChanged, [=, &brightness_factor, &kernel_size](int value)mutable {
			kernel_size = value;//根据滑动条修改滤波器的大小
			cv::cvtColor(ori_image, image, cv::COLOR_BGR2RGB);//将原始图片的BGR格式转化为RGB格式
			image.convertTo(image, -1, brightness_factor, 0);//修改图片的亮度
			cv::blur(image, image, cv::Size(kernel_size, kernel_size));//模糊操作
			QImage qImage(image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);//将opencv格式转化为Qimage格式
			QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.image_label->size(), Qt::KeepAspectRatio));//调整大小
			ui.image_label->setPixmap(pixmap);//将图片放入Qlabel控件中
			});
	}

}

opencv_exp_1_qt::~opencv_exp_1_qt()
{}
