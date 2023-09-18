#include "opencv_exp_1_qt.h"

opencv_exp_1_qt::opencv_exp_1_qt(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.brightnessSlider->setRange(0, 100);

	cv::Mat ori_image = cv::imread("./lena.jpg");
	cv::Mat image;
	double brightness_factor = 0;
	//init:
	cv::cvtColor(ori_image, image, cv::COLOR_BGR2RGB);
	image.convertTo(image, -1, brightness_factor, 0);
	QImage qImage(image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);
	QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.image_label->size(), Qt::KeepAspectRatio));
	ui.image_label->setPixmap(pixmap);

	if (!ori_image.empty()) {
		QObject::connect(ui.brightnessSlider, &QSlider::valueChanged, [=](int value)mutable {
			//ui.image_label->setText(QString::number(value));
			brightness_factor = double(value) / 20;
			cv::cvtColor(ori_image, image, cv::COLOR_BGR2RGB);
			image.convertTo(image, -1, brightness_factor, 0);
			QImage qImage(image.data, image.cols, image.rows, image.cols * image.channels(), QImage::Format_RGB888);
			QPixmap pixmap = QPixmap::fromImage(qImage.scaled(ui.image_label->size(), Qt::KeepAspectRatio));
			ui.image_label->setPixmap(pixmap);
			});
	}
}

opencv_exp_1_qt::~opencv_exp_1_qt()
{}
