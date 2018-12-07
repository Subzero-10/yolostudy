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
	if (!frame.empty())
	{
		image = Mat2QImage(frame);
		QImage newImg = image.scaled(ui->label->width(), ui->label->height());
		space_occupancy = 4.5*traffic_density / 10;
		if (traffic_density != 0)
			car_spacing = 1000 / (float)traffic_density-4.5;
		else
			car_spacing = 25;

		ui->label->setPixmap(QPixmap::fromImage(newImg));
		ui->label_2->setText("Traffic Density:\n" + QString::number(traffic_density));
		ui->label_3->setText("Car Count:\n" + QString::number(carcount)+"\n"+"Space Occupancy:\n"+ QString::number(space_occupancy) + "\n" + "Car Spacing:\n" + QString::number(car_spacing) + "\n" + "Car Ave Speed:\n" + QString::number(ave_carspeed));
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
