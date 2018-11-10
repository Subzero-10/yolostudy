#pragma once

#include <QtWidgets/QWidget>
#include "ui_trafficApplication.h"
#include <opencv2/opencv.hpp>            // C++
#include "opencv2/core/version.hpp"
//#include "yolo_console_dll.h"
#include "myThread.h"

class trafficApplication : public QWidget
{
	Q_OBJECT

public:
	trafficApplication(QWidget *parent = Q_NULLPTR);
	void displayMat(cv::Mat frame,int fps);
	QImage  trafficApplication::Mat2QImage(cv::Mat cvImg);
	myThread *thread1;
	yolo_console_dll *yolo;

private:
	Ui::trafficApplicationClass *ui;
	QTimer *timer;
	QImage image;
	
	
	public slots:
	void displayslot();

};
