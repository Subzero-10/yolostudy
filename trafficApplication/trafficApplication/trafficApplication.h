#pragma once

#include <QtWidgets/QWidget>
#include "ui_trafficApplication.h"

class trafficApplication : public QWidget
{
	Q_OBJECT

public:
	trafficApplication(QWidget *parent = Q_NULLPTR);

private:
	Ui::trafficApplicationClass ui;
};
