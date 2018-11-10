#include "trafficApplication.h"
#include <QtWidgets/QApplication>
#include "myThread.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	trafficApplication w;
	w.show();

	return a.exec();
}
