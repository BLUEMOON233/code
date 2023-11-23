#include "Fatigue_Detection.h"

Video::Video(std::string file_path) {
	this->isOpened = false;
	this->data.open(file_path);
	if (!data.isOpened()) {
		std::cout << "打开视频失败！\n";
		return;
	}
	this->isOpened = true;
}

Video::~Video() {
	this->data.release();
}


std::vector<cv::Mat> Video::get_frame() {
	std::vector<cv::Mat> ret;
	cv::Mat frame;
	while (data.read(frame)) {
		ret.emplace_back(frame.clone());
	}
	reverse(ret.begin(), ret.end());
	data.set(cv::CAP_PROP_POS_FRAMES, 0);
	return ret;
}

bool Fatigue_Detection::init_system(std::string file_path) {
	video = new Video(file_path);
	if (!video->isOpened) {
		delete video;
		video = nullptr;
		return false;
	}
	if (!faceCascade.load("./xml/haarcascade_frontalface_alt2.xml")) {
		std::cout << "error!\n";
		return false;
	}
	if (!mouthCascade.load("./xml/haarcascade_smile.xml")) {
		std::cout << "error!\n";
		return false;
	}
	if (!eyeCascade.load("./xml/haarcascade_righteye_2splits.xml")) {
		std::cout << "error!\n";
		return false;
	}
	frames.clear();
	frames_ori.clear();
	frames_ori = video->get_frame();
	this->FPS = video->data.get(cv::CAP_PROP_FPS);
	this->frameCnt = video->data.get(cv::CAP_PROP_FRAME_COUNT);
	this->duration = (double)this->frameCnt / this->FPS;
	std::cout << FPS << '\n' << frameCnt << '\n' << duration << '\n';
	delete video;
	video = nullptr;
	return true;
}

cv::Mat Fatigue_Detection::get_frame(int index, int sel) {
	if (sel == 0) {
		if (index >= frames_ori.size()) {
			return cv::Mat();
		}
		return this->frames_ori[index];
	}
	else if (sel == 1) {
		if (index >= frames.size()) {
			return cv::Mat();
		}
		cv::Mat ret;
		cv::cvtColor(this->frames[index], ret, cv::COLOR_BGR2GRAY);
		return ret;
	}
	else if (sel == 2) {
		if (index >= frames_mouth.size()) {
			return cv::Mat();
		}
		return this->frames_mouth[index];
	}
	else if (sel == 3) {
		if (index >= frames_eyes.size()) {
			return cv::Mat();
		}
		return this->frames_eyes[index];
	}
}

cv::Mat Fatigue_Detection::face_detection(int index) {
	std::vector<cv::Rect> faces;
	cv::Mat gray;

	gray = frames_ori[index].clone();
	cv::resize(gray, gray, cv::Size(), 0.3, 0.3);

	//cv::Mat image_lab;
	//cv::cvtColor(gray, image_lab, cv::COLOR_BGR2Lab); // 将图像转换为Lab色彩空间
	//std::vector<cv::Mat> labChannels;
	//cv::split(image_lab, labChannels); // 分离Lab通道
	//cv::equalizeHist(labChannels[0], labChannels[0]); // 对亮度通道进行直方图均衡化
	////labChannels[0].setTo(0);
	//cv::merge(labChannels, image_lab); // 合并Lab通道
	//cv::cvtColor(image_lab, gray, cv::COLOR_Lab2BGR);
	faceCascade.detectMultiScale(gray, faces, 1.3, 5);
	//cv::cvtColor(gray, gray, cv::COLOR_BGR2GRAY);

	if (faces.size() == 0) {
		faces.emplace_back(lstFace);
	}	
	else {
		lstFace = faces[0];
		faces[0].y += 20;
	}
	gray = gray(faces[0]);
	double a = 200.0 / gray.rows, b = 200.0 / gray.cols;
	cv::resize(gray, gray, cv::Size(), a, b);
	//cv::medianBlur(gray, gray, 3);
	//cv::equalizeHist(gray, gray);
	frames.emplace_back(gray.clone());
	return gray.clone();
}

//cv::Mat Fatigue_Detection::dis_detection(int index) {
//	if (index == 0) {
//		frames_dis.emplace_back(cv::Mat(200, 200, CV_8UC1, cv::Scalar(0)));
//		return frames_dis.back();
//	}
//	cv::Mat ret;
//	cv::absdiff(frames[index - 1], frames[index], ret);
//	frames_dis.emplace_back(ret);
//	return ret.clone();
//}

cv::Mat Fatigue_Detection::edge_detection(int index) {
	cv::Mat ret;
	cv::Canny(frames[index], ret, 100, 200);
	return ret.clone();
}

cv::Mat Fatigue_Detection::eye_detection(int index) {
	std::vector<cv::Rect> eyes;
	cv::Rect limit(0, 0, 200, 100);
	cv::Mat face = frames[index].clone();
	face = face(limit);
	eyeCascade.detectMultiScale(face, eyes, 1.05, 4, 0 | cv::CASCADE_DO_ROUGH_SEARCH);
	cv::Mat ret = frames[index].clone(), tmp;
	if (eyes.size() == 0) eyes.emplace_back(lstEye);
	else lstEye = eyes[0];

	cv::cvtColor(ret, ret, cv::COLOR_BGR2GRAY);
	cv::medianBlur(ret, ret, 3);
	cv::equalizeHist(ret, ret);

	cv::threshold(ret, ret, 31, 255, cv::THRESH_BINARY);
	tmp = 255 - ret;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(8, 8));
	cv::morphologyEx(tmp, tmp, cv::MORPH_OPEN, element);
	bool flag = false;
	for (int i = 0; i < std::min(int(eyes.size()), 2); i++) {
		int dy = 1.0 / 3 * eyes[i].height;
		eyes[i].y += dy, eyes[i].height -= dy;
		if (cv::countNonZero(tmp(eyes[i])) <= 20) flag = true;
		//cv::rectangle(ret, eyes[i], cv::Scalar(0), 1);
		cv::rectangle(tmp, eyes[i], cv::Scalar(255), 1);
	}
	if (flag) eyes_cnt++;
	else eyes_cnt = 0;
	if (eyes_cnt == 1) blink.push(1), blink_cnt += 1;
	else blink.push(0);

	if (blink.size() > 30) {
		blink_cnt -= blink.front();
		blink.pop();
	}
	frames_eyes.emplace_back(tmp.clone());
	return tmp.clone();
}

cv::Mat Fatigue_Detection::mouth_detection(int index) {
	std::vector<cv::Rect> mouths;
	cv::Rect limit(0, 120, 200, 80);
	cv::Mat face = frames[index].clone();
	face = face(limit);
	mouthCascade.detectMultiScale(face, mouths, 1.1, 3, 0 | cv::CASCADE_DO_ROUGH_SEARCH);
	cv::Mat ret = frames[index].clone(), tmp;
	if (mouths.size() == 0) mouths.emplace_back(lstMouth);
	else if (mouths[0].x > 100 || mouths[0].x < 40) mouths[0] = lstMouth;
	else lstMouth = mouths[0];
	
	cv::cvtColor(ret, ret, cv::COLOR_BGR2GRAY);
	cv::medianBlur(ret, ret, 3);
	cv::equalizeHist(ret, ret);

	cv::threshold(ret, ret, 31, 255, cv::THRESH_BINARY);
	tmp = 255 - ret;
	//cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(8, 8));
	//cv::morphologyEx(tmp, tmp, cv::MORPH_OPEN, element);
	bool flag = false;

	if (mouths.size()) {
		mouths[0].y += 120;
		if (cv::countNonZero(tmp.clone()(mouths[0])) > mouths[0].area() / 3.0) flag = true;
		cv::rectangle(ret, mouths[0], cv::Scalar(0), 1);
	}
	if (flag) mouth_cnt++;
	if (mouth_cnt && !flag) {
		if (mouth_cnt < 8) mouth_cnt--;
		else mouth_cnt -= 3;
	}
	frames_mouth.emplace_back(ret.clone());
	return ret.clone();
}

std::vector<cv::Mat> Fatigue_Detection::detection(int index) {
	std::vector<cv::Mat> ret;
	cv::Mat frame = get_frame(index);
	int mod = get_FPS() / tar_fps;
	if (frame.empty()) return ret;
	ret.emplace_back(frame.clone());

	if (index % mod) {
		return ret;
	}

	int index_fps10 = index / mod;
	ret.emplace_back(cv::Mat());
	ret.back() = face_detection(index);
	cv::cvtColor(ret.back(), ret.back(), cv::COLOR_BGR2GRAY);
	ret.emplace_back(cv::Mat());
	ret.back() = mouth_detection(index_fps10);
	ret.emplace_back(cv::Mat());
	ret.back() = eye_detection(index_fps10);

	if (blink.size()) blink_per_second = tar_fps * blink_cnt / blink.size();
	bps.emplace_back(blink_per_second);
	yawn.emplace_back(get_is_yawning());
	return ret;
}


double Fatigue_Detection::get_FPS() {
	return this->FPS;
}

int Fatigue_Detection::get_frameCnt() {
	return this->frameCnt;
}

double Fatigue_Detection::get_duration() {
	return this->duration;
}

double Fatigue_Detection::get_blinktime() {
	return 1.0 / tar_fps * this->eyes_cnt;
}

double Fatigue_Detection::get_blink_per_second(int index) {
	if (index != -1) return bps[index];
	return blink_per_second;
}
bool Fatigue_Detection::get_is_yawning(int index) {
	if (index != -1) return yawn[index];
	return mouth_cnt >= 4;
}
