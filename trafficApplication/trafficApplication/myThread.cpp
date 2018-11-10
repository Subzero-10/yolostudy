#include "myThread.h"



myThread::myThread()
{	
}


myThread::~myThread()
{
}

void myThread::run()
{
	yolo1->startyolo();
	qDebug("hello:%d", yolo1->i);

}


