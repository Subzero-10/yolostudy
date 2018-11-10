/********************************************************************************
** Form generated from reading UI file 'trafficApplication.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAFFICAPPLICATION_H
#define UI_TRAFFICAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trafficApplicationClass
{
public:

    void setupUi(QWidget *trafficApplicationClass)
    {
        if (trafficApplicationClass->objectName().isEmpty())
            trafficApplicationClass->setObjectName(QStringLiteral("trafficApplicationClass"));
        trafficApplicationClass->resize(600, 400);

        retranslateUi(trafficApplicationClass);

        QMetaObject::connectSlotsByName(trafficApplicationClass);
    } // setupUi

    void retranslateUi(QWidget *trafficApplicationClass)
    {
        trafficApplicationClass->setWindowTitle(QApplication::translate("trafficApplicationClass", "trafficApplication", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class trafficApplicationClass: public Ui_trafficApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAFFICAPPLICATION_H
