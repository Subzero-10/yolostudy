#include "trafficApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	trafficApplication w;
	w.show();
	return a.exec();
}
