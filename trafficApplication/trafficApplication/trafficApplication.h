#pragma once

#include <QtWidgets/QWidget>
#include "ui_trafficApplication.h"
#include <opencv2/opencv.hpp>            // C++
#include "opencv2/core/version.hpp"
//#include "yolo_console_dll.h"
#include "myThread.h"
#include <QTimer>

class trafficApplication : public QWidget
{
	Q_OBJECT

public:
	trafficApplication(QWidget *parent = Q_NULLPTR);
	void displayMat(cv::Mat frame,int fps);
	QImage  trafficApplication::Mat2QImage(cv::Mat cvImg);
	myThread *thread1;
	yolo_console_dll *yolo;
	int sec;
	int sec2;
	int cartimeCount;
	float cartimePlus;
	int timePlus;
	void startTime2();
	int stopTime2();

private:
	Ui::trafficApplicationClass *ui;
	QTimer *timer;
	QTimer *timer2;
	QImage image;
	bool isStart;
	bool isStart2;
	
	
public slots:
	void displayslot();
	void updateTime();
	void startTime();
	void stopTime();
	void updateTime2();

};
