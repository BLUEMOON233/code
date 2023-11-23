#include "Fatigue_Detection_System.h"

Fatigue_Detection_System::Fatigue_Detection_System(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	fatigue_detection = new Fatigue_Detection();
	ui.LB_face->setScaledContents(true);
	ui.LB_ori->setScaledContents(true);
	ui.LB_mouth->setScaledContents(true);
	ui.LB_eye->setScaledContents(true);
	

	/*打开文件按钮设置*/
	connect(ui.PB_getFilePath, &QPushButton::clicked, [=]()mutable {
		QString fileName = QFileDialog::getOpenFileName(this, "选择视频文件", "", "视频文件 (*.mp4 *.avi)");
		if (fileName.isEmpty()) return;
		fatigue_detection->init_system(fileName.toStdString());
		ui.slider->setRange(0, fatigue_detection->get_frameCnt() - 1);
		});

	connect(timer, &QTimer::timeout, this, &Fatigue_Detection_System::update_frame);

	connect(ui.PB_playVideo, &QPushButton::clicked, [&]()mutable {
		index_frame = 0;
		timer->start(10);
		});

	connect(ui.slider, &QSlider::valueChanged, [&]()mutable {
		int mod = fatigue_detection->get_FPS() / tar_fps, index = ui.slider->value();
		cv::Mat frame = fatigue_detection->get_frame(index);
		QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_BGR888);
		QPixmap pixmap = QPixmap::fromImage(image);
		ui.LB_ori->setPixmap(pixmap);
		frame = fatigue_detection->get_frame(index / mod, 1);
		QImage image_face(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_Grayscale8);
		QPixmap pixmap_face = QPixmap::fromImage(image_face);
		ui.LB_face->setPixmap(pixmap_face);
		frame = fatigue_detection->get_frame(index / mod, 2);
		QImage image_mouth(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_Grayscale8);
		QPixmap pixmap_mouth = QPixmap::fromImage(image_mouth);
		ui.LB_mouth->setPixmap(pixmap_mouth);
		frame = fatigue_detection->get_frame(index / mod, 3);
		QImage image_eye(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_Grayscale8);
		QPixmap pixmap_eye = QPixmap::fromImage(image_eye);
		ui.LB_eye->setPixmap(pixmap_eye);
		ui.LB_bps->setText(QString::number(fatigue_detection->get_blink_per_second(index / mod), 103, 3));
		ui.LB_yawn->setText(QString::fromStdString(fatigue_detection->get_is_yawning(index / mod) ? "打了打了" : "没打没打"));
		ui.LB_blinkcnt->setText(QString::number(fatigue_detection->get_blinktime(), 103, 3));
		});
}

Fatigue_Detection_System::~Fatigue_Detection_System()
{}

void Fatigue_Detection_System::update_frame() {
	int mod = fatigue_detection->get_FPS() / tar_fps;
	auto mats = fatigue_detection->detection(index_frame);
	if (mats.empty()) {
		timer->stop();
		return;
	}
	QImage image(mats[0].data, mats[0].cols, mats[0].rows, mats[0].step, QImage::Format_BGR888);
	QPixmap pixmap = QPixmap::fromImage(image);
	ui.LB_ori->setPixmap(pixmap);
	if (index_frame % mod == 0) {
		QImage image(mats[1].data, mats[1].cols, mats[1].rows, mats[1].step, QImage::Format_Grayscale8);
		QPixmap pixmap = QPixmap::fromImage(image);
		ui.LB_face->setPixmap(pixmap);

		int index_fps10 = index_frame / int(fatigue_detection->get_FPS() / tar_fps);
		QImage image_mouth(mats[2].data, mats[2].cols, mats[2].rows, mats[2].step, QImage::Format_Grayscale8);
		QPixmap pixmap_mouth = QPixmap::fromImage(image_mouth);
		ui.LB_mouth->setPixmap(pixmap_mouth);

		QImage image_eye(mats[3].data, mats[3].cols, mats[3].rows, mats[3].step, QImage::Format_Grayscale8);
		QPixmap pixmap_eye = QPixmap::fromImage(image_eye);
		ui.LB_eye->setPixmap(pixmap_eye);
	}
	ui.LB_bps->setText(QString::number(fatigue_detection->get_blink_per_second(), 103, 3));
	ui.LB_yawn->setText(QString::fromStdString(fatigue_detection->get_is_yawning() ? "打了打了" : "没打没打"));
	ui.LB_blinkcnt->setText(QString::number(fatigue_detection->get_blinktime(), 103, 3));
	index_frame++;
}