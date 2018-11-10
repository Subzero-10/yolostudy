#include "trafficApplication.h"
#include "yolo_console_dll.h"

trafficApplication::trafficApplication(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	yolo_console_dll yolo;
	yolo.startyolo;
}
