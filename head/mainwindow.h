#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"

#include "head/Products_Base/ui_main_class.h"
#include "head/Products/productA.h"

#include "dataformat.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    UI_Main_Class* MainUI;

    Server* server;
    QMap<qintptr,QString> AllPid;

    ConnectType connectTemp;

};

#endif // MAINWINDOW_H
