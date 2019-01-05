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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trafficApplicationClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QWidget *trafficApplicationClass)
    {
        if (trafficApplicationClass->objectName().isEmpty())
            trafficApplicationClass->setObjectName(QStringLiteral("trafficApplicationClass"));
        trafficApplicationClass->resize(1600, 900);
        label = new QLabel(trafficApplicationClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 1280, 720));
        label_2 = new QLabel(trafficApplicationClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1390, 80, 171, 161));
        QFont font;
        font.setPointSize(19);
        label_2->setFont(font);
        label_3 = new QLabel(trafficApplicationClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1400, 480, 141, 301));
        label_3->setFont(font);
        pushButton = new QPushButton(trafficApplicationClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1400, 20, 75, 23));
        pushButton_2 = new QPushButton(trafficApplicationClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1400, 50, 75, 23));
        label_4 = new QLabel(trafficApplicationClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1390, 280, 161, 131));
        label_4->setFont(font);

        retranslateUi(trafficApplicationClass);

        QMetaObject::connectSlotsByName(trafficApplicationClass);
    } // setupUi

    void retranslateUi(QWidget *trafficApplicationClass)
    {
        trafficApplicationClass->setWindowTitle(QApplication::translate("trafficApplicationClass", "trafficApplication", Q_NULLPTR));
        label->setText(QApplication::translate("trafficApplicationClass", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("trafficApplicationClass", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("trafficApplicationClass", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("trafficApplicationClass", "start", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("trafficApplicationClass", "stop", Q_NULLPTR));
        label_4->setText(QApplication::translate("trafficApplicationClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class trafficApplicationClass: public Ui_trafficApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAFFICAPPLICATION_H
