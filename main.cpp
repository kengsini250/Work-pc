/**
 * @file main.cpp
 * @author orz (kengsini250@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-07-22
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "head/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
