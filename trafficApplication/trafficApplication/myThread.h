#pragma once
#include <QThread>
#include "yolo_console_dll.h"

class myThread :
	public QThread
{
public:
	myThread();
	~myThread();
	void run();
	yolo_console_dll *yolo1;
};

