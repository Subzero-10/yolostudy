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
	myThread *thread1 = new myThread; //�½��̶߳���
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
	if (!frame.empty())
	{
		image = Mat2QImage(frame);
		QImage newImg = image.scaled(ui->label->width(), ui->label->height());
		ui->label->setPixmap(QPixmap::fromImage(newImg));
		ui->label_2->setText("Car Number:\n" + QString::number(carnum));
		ui->label_3->setText("Car Count:\n" + QString::number(carcount));
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
