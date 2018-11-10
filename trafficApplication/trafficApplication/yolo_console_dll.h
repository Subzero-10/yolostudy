#pragma once
#include <qobject.h>
#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <thread>
#include <atomic>
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

class yolo_console_dll: public QObject
{
	Q_OBJECT

public:
	yolo_console_dll();
	int startyolo();
	~yolo_console_dll();
	void update(cv::Mat frame);
	cv::Mat mat;

signals:
	void updatemat();
};

