/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QRadioButton *_Debug;
    QRadioButton *_User;
    QPushButton *_Ok;
    QPushButton *_Exit;
    QComboBox *_ComboBox;
    QPushButton *_Refresh;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(500, 115);
        MainWindow->setMinimumSize(QSize(500, 115));
        MainWindow->setMaximumSize(QSize(500, 115));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        _Debug = new QRadioButton(centralWidget);
        _Debug->setObjectName(QString::fromUtf8("_Debug"));
        _Debug->setGeometry(QRect(20, 20, 131, 31));
        _User = new QRadioButton(centralWidget);
        _User->setObjectName(QString::fromUtf8("_User"));
        _User->setGeometry(QRect(20, 60, 111, 31));
        _Ok = new QPushButton(centralWidget);
        _Ok->setObjectName(QString::fromUtf8("_Ok"));
        _Ok->setGeometry(QRect(230, 60, 75, 23));
        _Exit = new QPushButton(centralWidget);
        _Exit->setObjectName(QString::fromUtf8("_Exit"));
        _Exit->setGeometry(QRect(360, 60, 75, 23));
        _ComboBox = new QComboBox(centralWidget);
        _ComboBox->setObjectName(QString::fromUtf8("_ComboBox"));
        _ComboBox->setGeometry(QRect(240, 20, 211, 22));
        _Refresh = new QPushButton(centralWidget);
        _Refresh->setObjectName(QString::fromUtf8("_Refresh"));
        _Refresh->setGeometry(QRect(210, 20, 21, 23));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Control v1.0.0", nullptr));
        _Debug->setText(QCoreApplication::translate("MainWindow", "Debug Mode", nullptr));
        _User->setText(QCoreApplication::translate("MainWindow", "User Mode", nullptr));
        _Ok->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        _Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        _Refresh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
