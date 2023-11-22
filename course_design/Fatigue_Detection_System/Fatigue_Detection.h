#pragma once
#include<opencv2/opencv.hpp>

struct Video {
	Video(std::string file_path);
	~Video();
	std::vector<cv::Mat> get_frame();

	cv::VideoCapture data;
	bool isOpened = false;
};


class Fatigue_Detection {
public:
	bool init_system(std::string file_path);
	cv::Mat get_frame(int index, int sel = 0);
	cv::Mat face_detection(int index);
	//cv::Mat dis_detection(int index);
	cv::Mat edge_detection(int index);
	cv::Mat eye_detection(int index);
	cv::Mat mouth_detection(int index);

	std::vector<cv::Mat> detection(int index);

	double get_FPS();
	int get_frameCnt();
	double get_duration();
	double get_blink_per_second(int index = -1);
	bool get_is_yawning(int index = -1);

private:
	/*初始化视频指针，使用完释放*/
	Video* video = nullptr;
	/*级联识别器，分别对应脸部、眼部、嘴部*/
	cv::CascadeClassifier faceCascade;
	cv::CascadeClassifier eyeCascade;
	cv::CascadeClassifier mouthCascade;
	/*读取的视频属性，本系统以每秒钟10帧计算*/
	double FPS = 0.0;
	int frameCnt = 0;
	double duration = 0.0;
	/*预留面部捕捉框图，用于延迟识别，对准帧位*/
	cv::Rect lstFace = cv::Rect(0, 0, 200, 200);
	cv::Rect lstMouth = cv::Rect(0, 0, 1, 1);
	cv::Rect lstEye = cv::Rect(0, 0, 1, 1);

	bool eyes_check = true;
	int mouth_cnt = 0;
	/*原始帧，originfps*/
	std::vector<cv::Mat> frames_ori;
	/*脸部识别后帧，10fps*/
	std::vector<cv::Mat> frames;

	std::vector<cv::Mat> frames_mouth;
	std::vector<cv::Mat> frames_eyes;
	std::vector<double> bps;
	std::vector<bool> yawn;
	/*差分帧*/
	//std::vector<cv::Mat> frames_dis;
	
	std::queue<int> blink;
	int blink_cnt = 0;
	double blink_per_second = 0.0;

	const double tar_fps = 10;
};