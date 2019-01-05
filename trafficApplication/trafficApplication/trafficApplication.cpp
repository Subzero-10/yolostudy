#include "trafficApplication.h"
#include <qdebug.h>

trafficApplication::trafficApplication(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::trafficApplicationClass)
{
	ui->setupUi(this);
	this->setWindowTitle("Smart Traffic");
	yolo_console_dll *yolo = new yolo_console_dll;
	QObject::connect(yolo, SIGNAL(updatemat()), this, SLOT(displayslot()));
	myThread *thread1 = new myThread; //新建线程对象
	thread1->yolo1 = yolo;
	//QObject::connect(thread1, SIGNAL(updatematT()), this, SLOT(displayslot()));
	thread1->start();

	timer = new QTimer;  //初始化定时器
	isStart = false;
	timer2 = new QTimer;  //初始化定时器
	isStart2 = false;
	sec = 0;
	sec2 = 0;
	cartimeCount = 0;
	cartimePlus = 0;
	timePlus = 0;
	connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
	connect(timer2, SIGNAL(timeout()), this, SLOT(updateTime2()));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(startTime()));
	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(stopTime()));
}

void trafficApplication::displayslot()
{
	//qDebug("FPS:123");
    displayMat(mat, fps);
	
}

void trafficApplication::displayMat(cv::Mat frame,int fps)
{
	float space_occupancy;
	float car_spacing;
	int checksec2 = 0;
	if (!frame.empty())
	{
		image = Mat2QImage(frame);
		QImage newImg = image.scaled(ui->label->width(), ui->label->height());
		space_occupancy = 4.5*traffic_density / 10;
		if (traffic_density != 0)
			car_spacing = 1000 / (float)traffic_density-4.5;
		else
			car_spacing = 25;

		if (timer_start)
		{
			checksec2 = stopTime2();
			timePlus = timePlus + checksec2;
			cartimeCount++;
			if (cartimeCount == 5)
			{
				ui->label_4->setText( "Time Occupancy:\n" + QString::number(cartimePlus/ timePlus*200) + "%\n");
				cartimeCount = 0;
				cartimePlus = 0;
				timePlus = 0;
			}
			startTime2();
			timer_start = false;
			ui->label_2->setText("Head time interval:\n" + QString::number(checksec2) + "\n" + "CAR:" + QString::number(cartimeCount) + "\n");
		}

		ui->label->setPixmap(QPixmap::fromImage(newImg));

		ui->label_3->setText("Traffic Density:\n" + QString::number(traffic_density) + "\n" + "Car Flow::\n" + QString::number(carcount)+"\n"+"Space Occupancy:\n"+ QString::number(space_occupancy) + "\n" + "Car Spacing:\n" + QString::number(car_spacing) + "\n" + "Car Ave Speed:\n" + QString::number(ave_carspeed) + "\n" );
	}
}

QImage  trafficApplication::Mat2QImage(cv::Mat cvImg)
{
	QImage qImg;
	if (cvImg.channels() == 3)                             //3 channels color image
	{

		cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}
	else if (cvImg.channels() == 1)                    //grayscale image
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_Indexed8);
	}
	else
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}

	return qImg;

}

void trafficApplication::updateTime()
{
	sec++;
}

void trafficApplication::startTime()
{
	if (!isStart)
	{
		timer->start(1000);
		isStart = true;
	}
		
}

void trafficApplication::stopTime()
{
	if (isStart)
	{
		timer->stop();
		isStart = false;
	}
}

void trafficApplication::updateTime2()
{
	sec2++;
}

void trafficApplication::startTime2()
{
	if (!isStart2)
	{
		timer2->start(1000);
		isStart2 = true;
	}
}

int trafficApplication::stopTime2()
{
	int checksec2 = 0;
	if (isStart2)
	{
		timer2->stop();
		isStart2 = false;
	}
	checksec2 = sec2;
	sec2 = 0;
	if (car_speed != 0)
		cartimePlus = cartimePlus + 4.5 / ((float)car_speed / 3.6);
	else
		cartimePlus = cartimePlus + checksec2;
	return checksec2;
}
